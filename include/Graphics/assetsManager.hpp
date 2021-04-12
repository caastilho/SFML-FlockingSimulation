#pragma once
#ifndef __ASSETSMANAGER
#define __ASSETSMANAGER

#include <SFML/Graphics.hpp>

#include <Scripts/tools.hpp>
#include <vector>
#include <string>


// Engine assets manager
class AssetsManager
{
    
    private:
        
        std::string assetsPath;
        
        // Graphic objects array
        //std::vector<sf::Shader> shaders;
        std::vector<sf::Texture> textures;
        std::vector<sf::Font> fonts;
    
    public:
        
        // "AssetsManager" constructor
        AssetsManager();
        
        
        // Add graphical objects array
        void addShaders(std::string fragmented, std::string vertex);
        void addTexture(std::string path);
        void addFont(std::string path);
    
};

#endif
