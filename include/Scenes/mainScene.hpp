#pragma once
#include <SFML/Graphics.hpp>
#include <Graphics/assetsManager.hpp>
#include <Bodies/boid.hpp>

#include <random>
#include <time.h>
#include <vector>

#include <string>

#define map(v, min1, max1, min2, max2) min2+(max2-min2)*((v-min1)/(max1-min1))


class MainScene
{

    private:
        
        // Renderer object (Buffer content manipulator)
        sf::RenderWindow* renderer;
        
        // Boid unities array
        std::vector<Boid> boids;
        
        // Renderer dimensions
        int width, height;
        
        
        // Background color
        sf::Color background_color;
        
        // Background rectangle shape
        sf::RectangleShape background;
        
        // Render texture object
        sf::RenderTexture texture;
        
        // Drawn objects sprite
        sf::Sprite sprite;
        
        
        // Frame index
        int index = 0;
        
        // Image final path
        std::string path;
        
        
    public:
        
        // Default scene constructor
        MainScene() {};
        
        
        // Scene default methods
        void setup(sf::RenderWindow* _renderer, AssetsManager manager);
        void run(bool isFocused);
        void events(sf::Event& action);
        
};
