#pragma once
#include <SFML/Graphics.hpp>
#include <engine/shapes.hpp>
#include <engine/vector.hpp>

#include <vector>


// Boid class
class Boid
{
    
private:
    
    // Declare vectors
    sf::Vector2f *acceleration, *velocity, *position;
    
    // Declare boid shape
    TriangleShape *shape;
    
    // Boids array
    std::vector<Boid> *boids;
    
    // Canvas window
    sf::RenderWindow *canvas;
    int width, height;
    
    
    // Tune boids rules
    float tune_a = 0.3; 
    float tune_c = 0.3; 
    float tune_s = 0.3;
    float range = 100;
    
    // Boids rules
    void adjustPosition();
    void getAcceleration();
    
    void applyAlingment(sf::Vector2f& sum);
    void applyCohesion(sf::Vector2f& sum);
    void applySeparation(sf::Vector2f& sum);
    
    
public:
    
    // Constructor method
    Boid(sf::RenderWindow* window, std::vector<Boid>* array);
    
    // Run boid environment
    void update();
    void draw();
    
};
