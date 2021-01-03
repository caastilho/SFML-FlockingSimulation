#include "boids/boid.hpp" 
#include <engine/canvas.hpp>

#include <cstdlib>
#include <time.h>
#include <vector>


std::vector<Boid> array;
int amount = 1;


// Setup simulation environment 
void Canvas::Setup()
{

    srand(time(NULL));
    
    // Setup boid array
    for (int i = 0; i < amount; i++) 
        array.push_back(Boid(CANVAS_window, &array));
    
}


// Run simulation environment
void Canvas::Loop()
{
    
    // Clear canvas content
    CANVAS_window->clear();
    
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
