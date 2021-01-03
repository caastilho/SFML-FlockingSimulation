#include "boids/boid.hpp"
#define map(v, min1, max1, min2, max2) min2+(max2-min2)*((v-min1)/(max1-min1));


// Construct boid environment
Boid::Boid(sf::RenderWindow* window, std::vector<Boid>* array): canvas(window)
{
    
    boids = array;
    
    sf::Vector2u size = canvas->getSize();
    width = size.x;
    height = size.y;
    
    // Setup boid vectors
    position = getRandomVector(0, 1);
    velocity = getRandomVector(0, 1);
    acceleration = sf::Vector2f();
    
    // Scale position
    sf::Vector2f scaler(width, height);
    position = hadamard(position, scaler);
    
    // Create boid shape
    shape = new TriangleShape(
        sf::Vector2f(0, -boidSize), 
        sf::Vector2f(boidSize/3, 0), 
        sf::Vector2f(-boidSize/3, 0)
    );
    
    // Setup boid color
    float random = (float)rand() / RAND_MAX;
    int r = map(random, 0, 1, 100, 255); 
    int b = map(random, 0, 1, 255, 100); 
    
    shape->setOutlineThickness(2);
    shape->setOutlineColor(sf::Color(r, 0, b));
    shape->setFillColor(sf::Color(r, 0, b));
    
}


// Draw boid shape on canvas
void Boid::draw()
{
    canvas->draw(*shape);
}

// Update boids vectors
void Boid::update()
{

    position += velocity;
    velocity += acceleration;
    getAcceleration();
    
    // Adjust boid position
    adjustPosition();
    
    // Update shape position
    shape->setPosition(position);
    
    // Set shape rotation
    float angle = getAngle(velocity);
    shape->setRotation(angle + 90);
    
}


// Adjust boid position
void Boid::adjustPosition()
{
    float xOffset = 0;
    float yOffset = 0;
    
    // Check X position
    if (position.x - boidSize - 1 > width) {
        xOffset = -(position.x + boidSize);
    } else if (position.x + boidSize + 1 < 0) {
        xOffset = -(position.x) + width + boidSize;
    }
    
    // Check Y position
    if (position.y - boidSize - 1 > height) {
        yOffset = -(position.y + boidSize);
    } else if (position.y + boidSize + 1 < 0) {
        yOffset = -(position.y) + height + boidSize;
    }
    
    // Update position
    position += sf::Vector2f(xOffset, yOffset);
    
}


// Get boid acceleration
void Boid::getAcceleration()
{
    
    int amount = 0;
    acceleration *= 0.f;
    
    // Setup sum vectors
    sf::Vector2f velocitySum(0, 0);
    sf::Vector2f positionSum(0, 0);
    sf::Vector2f differenceSum(0, 0);
    
    // Iterate thru boids
    for (Boid& boid : *boids)
    {
        float distance = getDistance(position, boid.position);
        
        // Validate distance value
        if (&boid != this && distance <= range) {
            amount++;
            
            // Update vectors
            velocitySum += boid.velocity;
            positionSum += boid.position;
            differenceSum += (position - boid.position) / distance;
        }
    }
    
    // Update acceleration
    applyAlingment(velocitySum, amount);
    applyCohesion(positionSum, amount);
    applySeparation(differenceSum, amount);
    
}

void Boid::applyAlingment(sf::Vector2f& force, int amount)
{
    
    // Tune alingment force
    if (amount > 0) {
        force /= (float)amount;
        force = setMagnitude(force, maxVelocity);
        force -= velocity;
        force = constrain(force, maxAcceleration);
        force *= tune_a;
        
        acceleration += force;
    }
    
}

void Boid::applyCohesion(sf::Vector2f& force, int amount)
{
    
    // Tune cohesion force
    if (amount > 0) {
        force /= (float)amount;
        force -= position;
        force = setMagnitude(force, maxVelocity);
        force -= velocity;
        force = constrain(force, maxAcceleration);
        force *= tune_c;
        
        acceleration += force;
    }
    
}

void Boid::applySeparation(sf::Vector2f& force, int amount)
{
    
    // Tune separation force
    if (amount > 0) {
        force /= (float)amount;
        force = setMagnitude(force, maxVelocity);
        force -= velocity;
        force = constrain(force, maxAcceleration);
        force *= tune_c;
        
        acceleration += force;
    }
}
