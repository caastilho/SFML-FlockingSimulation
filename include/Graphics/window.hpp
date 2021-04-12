#pragma once

#include <SFML/Graphics.hpp>
#include <Scripts/tools.hpp>
#include <vector>

#include <Graphics/assetsManager.hpp>
#include <Graphics/scenesManager.hpp>


// Main window class.
class Window
{
    
    private:
        
        // Window object
        bool isFocused = true;
        sf::RenderWindow* renderer;
        sf::Event action;
        
        
        // Window time management
        float frameRate = 60;
        
        
        // Handle window events
        void events();
        
        // Setup window assets
        void setup();
        
        
        // Window assets manager
        AssetsManager assetsManager;
        
        // Window scenes manager
        ScenesManager scenesManager;
    
    
    public:
        
        // Construct window environment
        Window(int width, int height, const char* name);
        
        // Run Window environment
        void run();
    
};
