#pragma once
#ifndef __BOID
#define __BOID

#include <SFML/Graphics.hpp>
#include <Math/vector.hpp>

#include <random>
#include <vector>
#include <cmath>

#include <iostream>



class Boid
{

    private:
        
        // Debug arrows
        bool debug = false;
        sf::RectangleShape velocity_arrow;
        sf::RectangleShape acceleration_arrow;
        
        // Boid's vectors: Position, velocity, acceleration
        sf::Vector2f position, velocity, acceleration;
        
        // Boid's shape
        sf::ConvexShape shape;
        
        
        // Boid's maximum size
        const int size = 8; 
        
        // Boid's velocity magnitude
        const float velocity_magnitude = 4;
        
        // Boid's sense attributes
        const float range = 200;
        const double field = 3.14159265;
        
        // Boid's rule coeficients
        const float tune = 0.05;
        const float tune_a = 0.28;
        const float tune_c = 0.3;
        const float tune_s = 0.3;
        
        
        // Update boid's acceleration
        void updateAcceleration(std::vector<Boid>& boids);
        
        
        // Boid allignment rule
        void applyAllignment(sf::Vector2f alligment, float amount);
        
        // Boid cohesion rule
        void applyCohesion(sf::Vector2f cohesion, float amount);
        
        // Boid separation rule
        void applySeparation(sf::Vector2f separation, float amount);
        

    public:
        
        // Boid default constructor
        Boid() {};
        
        // Boid normal constructor
        Boid(float x, float y, sf::Color color, bool debug=false);
        
        
        // Return boid's velocity vector
        sf::Vector2f getVelocity();
        
        // Return boid's position vector
        sf::Vector2f getPosition();
        
        
        // Constrain boid's position
        void constrain(int width, int height);
        
        // Update boid state
        void update(std::vector<Boid>& boids);
        
        // Display boid shape
        void display(sf::RenderWindow* renderer);
        void display(sf::RenderTexture& renderer);
        
};

#endif
