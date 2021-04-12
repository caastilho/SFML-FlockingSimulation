#include <Graphics/window.hpp>



// Construct window environment
Window::Window(int width, int height, const char* name)
{
    
    // Setup render window settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    
    // Create "RenderWindow" object
    sf::VideoMode shape(width, height);
    int style = sf::Style::Close | sf::Style::Titlebar;
    renderer = new sf::RenderWindow(shape,  name, style, settings);
    
}



// Setup window assets
void Window::setup()
{
    
}

// Run window environment
void Window::run()
{
    
    // Setup environment assets
    setup();
    
    // Setup scenes environment
    scenesManager.setup(renderer, assetsManager);
    
    // Limit frame rate speed
    renderer->setFramerateLimit(frameRate);
    
    
    // Start Window main loop
    while(renderer->isOpen())
    {
        
        // Run window environment
        events();
        scenesManager.run(isFocused);
        renderer->display();
    
    }    
}

// Window event handler
void Window::events()
{
    
    // Iterate thru events
    while(renderer->pollEvent(action))
    {
        
        scenesManager.events(action);
        
        // "Close" window event
        if (action.type == sf::Event::Closed)
            renderer->close();
        
        // "FocusIn" window event
        if (action.type == sf::Event::GainedFocus)
            isFocused = true;
        
        // "FocusOut" window event
        if (action.type == sf::Event::LostFocus)
            isFocused = false;
    }
}
