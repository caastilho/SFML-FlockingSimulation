#include "boids/boid.hpp" 
#include <engine/canvas.hpp>

#include <cstdlib>
#include <time.h>
#include <vector>


std::vector<Boid> array;
int amount = 150;

// Setup simulation environment 
void Canvas::Setup()
{

    // Setup random seed
    srand(time(NULL));
    
    // Setup boid array
    for (int i = 0; i < amount; i++) {
        int x = rand() % CANVAS_width;
        int y = rand() % CANVAS_height;
        Boid boid(x, y, CANVAS_window, &array);
        
        array.push_back(boid);
    }
    
}


// Run simulation environment
void Canvas::Loop()
{
    
    // Clear canvas content
    CANVAS_window->clear(sf::Color(200, 200, 200));

    // Run boids objects
    for (Boid& boid : array) {
        boid.update();
        boid.draw();
    }
    
}


// Clean simulation environment
void Canvas::Clean()
{
    
}
