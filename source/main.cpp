#include <engine/canvas.hpp>


// Main entry-point
int main()
{
    
    // Create canvas
    Canvas canvas(1920, 1080, "Flock Simulation"); 
    canvas.Run();
    
    // End simulation
    return 0;  
    
}
