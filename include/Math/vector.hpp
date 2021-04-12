#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>


float getDistance(sf::Vector2f a, sf::Vector2f b);
float getMagnitude(sf::Vector2f source);
float getDotProduct(sf::Vector2f a, sf::Vector2f b);
double getHeadingAngle(sf::Vector2f source);
double getAngleBetween(sf::Vector2f a, sf::Vector2f b);

sf::Vector2f setMagnitude(sf::Vector2f source, float newMagnitude);
sf::Vector2f fromAngle(float angle);
sf::Vector2f normalize(sf::Vector2f source);
sf::Vector2f constrain(sf::Vector2f source, float maximum);
