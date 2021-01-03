#include "boids/boid.hpp"


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
        sf::Vector2f(0, -18), 
        sf::Vector2f(6, 0), 
        sf::Vector2f(-6, 0)
    );
    
    //shape->setOrigin(position);
    
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
    //getAcceleration();
    
    // Update shape position
    shape->setPosition(position);
    
}
