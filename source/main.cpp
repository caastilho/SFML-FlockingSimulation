#include <Graphics/window.hpp> 


// Main project entry-point
int main()
{
    
    // Create "Window" object
    Window window(1920, 1080, "SFML Window");
    
    // Run "Window" environment
    window.run();
    
    // Exit main C++ function
    return 0;
}
