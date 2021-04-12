#pragma once
#ifndef __SCENESMANAGER
#define __SCENESMANAGER

#include <SFML/Graphics.hpp>
#include <Graphics/assetsManager.hpp>


// Include scenes objects
#include <Scenes/mainScene.hpp> 


// Engine scenes manager
class ScenesManager
{

    
    private:
        
        // Current scene index
        int scene_index = 0;
        
        // Scenes objects
        MainScene scene_0;
        
    
    public:
        
        
        // Default "SceneManager" constructor
        ScenesManager() {};
        
        
        // Setup scenes environment
        void setup(sf::RenderWindow* renderer, AssetsManager manager);
        
        // Run scenes environment
        void run(bool isFocused);
        
        // Run scenes event handler
        void events(sf::Event& action);
    
};


#endif
