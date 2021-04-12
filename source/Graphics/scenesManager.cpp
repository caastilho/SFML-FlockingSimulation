#include <Graphics/scenesManager.hpp>


// Setup scenes environment
void ScenesManager::setup(sf::RenderWindow* renderer, AssetsManager manager)
{
    
    // Setup "Main" scene
    scene_0.setup(renderer, manager);
    
}

// Run current scene environment
void ScenesManager::run(bool isFocused)
{
    
    switch (scene_index)
    {
        
        // Run "Main" scene environment
        case 0:
            scene_0.run(isFocused);
            break;
        
    }
    
}

// Run current scene event handler
void ScenesManager::events(sf::Event& action)
{
    
    switch (scene_index)
    {
        
        // Run "Main" scene event handler
        case 0:
            scene_0.events(action);
            break;
        
    }
    
}
