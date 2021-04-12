#include <Bodies/boid.hpp>



// Boid constructor
Boid::Boid(float x, float y, sf::Color color, bool _debug): debug(_debug)
{
    
    position = sf::Vector2f(x, y);
    
    
    // Setup boid's shape
    shape.setPointCount(3);
    
    shape.setPoint(0, sf::Vector2f(-(size - 3), -(size - 3)));
    shape.setPoint(1, sf::Vector2f( size      ,  0         ));
    shape.setPoint(2, sf::Vector2f(-(size - 3),  size - 3  ));
    
    shape.setOutlineColor(color);
    shape.setOutlineThickness(1);
    shape.setFillColor(sf::Color(0,0,0,0));
    
    
    // Setup debug arrows
    if (debug)
    {
        velocity_arrow.setSize(sf::Vector2f(40, 2));
        velocity_arrow.setFillColor(sf::Color(127, 255, 255));
        velocity_arrow.setOrigin(sf::Vector2f(1, 0));
        
        acceleration_arrow.setSize(sf::Vector2f(40, 2));
        acceleration_arrow.setFillColor(sf::Color(255, 127, 255));
        acceleration_arrow.setOrigin(sf::Vector2f(1, 0));
    }
    
    
    // Setup random velocity
    float angle = ((float)rand() / (float)RAND_MAX) * 2.f * 3.14159265; 
    velocity = fromAngle(angle);
    
}



// Update boid's acceleration
void Boid::updateAcceleration(std::vector<Boid>& boids)
{
    
    // Reset acceleration value
    acceleration *= 0.f;
    
    int count = 0;
    sf::Vector2f positionSum;
    sf::Vector2f velocitySum;
    sf::Vector2f differenceSum;
    
    // Iterate thru boids objects
    for (Boid& boid : boids)
    {   
        if (&boid != this)
        {
        
            sf::Vector2f delta = boid.getPosition() - position;
            float distance = getDistance(position, boid.getPosition());
            double angle = getAngleBetween(velocity, delta);
            
            // Validate boid's position
            if (distance <= range && angle <= field / 2.f)
            {
                
                positionSum += boid.getPosition();
                velocitySum += boid.getVelocity();
                differenceSum += (position - boid.getPosition()) / (float)pow(distance, 2);
                
                count++;
            }
        }
    }
    
    // Apply boids rules
    applyAllignment(velocitySum, count);
    applyCohesion(positionSum, count);
    applySeparation(differenceSum, count);
    
    // Smooth acceleration
    acceleration *= tune;
    
}



// Boid alligment rule
void Boid::applyAllignment(sf::Vector2f allignment, float count)
{
    
    if (count > 0)
    {
        
        // Get allignment force vector
        allignment /= count;
        allignment = setMagnitude(allignment, velocity_magnitude);
        allignment -= velocity;
        allignment *= tune_a;
        
        // Apply allignment
        acceleration += allignment;
        
    }
    
}

// Boid cohesion ruleP
void Boid::applyCohesion(sf::Vector2f cohesion, float count)
{
    
    if (count > 0)
    {
        
        // Get cohesion force
        cohesion /= count;
        cohesion -= position;
        cohesion = setMagnitude(cohesion, velocity_magnitude);
        cohesion -= velocity;
        cohesion *= tune_c;
        
        // Apply cohesion
        acceleration += cohesion;
        
    }
    
}

// Boid separation rule
void Boid::applySeparation(sf::Vector2f separation, float count)
{
    
    if (count > 0)
    {
        
        // Get separation force
        separation /= count;
        separation = setMagnitude(separation, velocity_magnitude);
        separation -= velocity;
        separation *= tune_s;
        
        // Apply separation
        acceleration += separation;
        
    }
    
}



// Return boid's velocity vector
sf::Vector2f Boid::getVelocity()
{
    return velocity;
}

// Return boid's position vector
sf::Vector2f Boid::getPosition()
{
    return position;
}



// Constrain boid's position
void Boid::constrain(int width, int height)
{
    
    // Constrain X position
    if (position.x > width + size)
    {
        position.x = -size;
    }
    
    else if (-size > position.x)
    {
        position.x = width + size;
    }
    
    // Constrain Y position
    if (position.y > height + size)
    {
        position.y = -size;
    }
    
    else if (-size > position.y)
    {
        position.y = height + size;
    }
    
}

// Update boid state
void Boid::update(std::vector<Boid>& boids)
{
    
    // Update boid's vectors
    updateAcceleration(boids);
    velocity += acceleration;
    position += velocity;
    
    // Update shapes positions
    shape.setPosition(position);
    shape.setRotation(getHeadingAngle(velocity) * (180 / 3.14159265));
    
    
    // Update debug arrows states
    if (debug)
    {
        velocity_arrow.setPosition(position);
        velocity_arrow.setRotation(getHeadingAngle(velocity) * (180 / 3.14159265));
        
        acceleration_arrow.setPosition(position);
        acceleration_arrow.setRotation(getHeadingAngle(acceleration) * (180 / 3.14159265));
    }
    
}

// Display boid shape
void Boid::display(sf::RenderWindow* renderer)
{
    
    // Draw boid's shape
    renderer->draw(shape);
    
    // Draw debug arrows
    if (debug)
    {
        renderer->draw(velocity_arrow);
        renderer->draw(acceleration_arrow);
    }
    
}

void Boid::display(sf::RenderTexture& renderer)
{
    
    // Draw boid's shape
    renderer.draw(shape);
    
    // Draw debug arrows
    if (debug)
    {
        renderer.draw(velocity_arrow);
        renderer.draw(acceleration_arrow);
    }
    
}
