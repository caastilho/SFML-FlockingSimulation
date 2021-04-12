#include <Math/vector.hpp>


float getDistance(sf::Vector2f a, sf::Vector2f b)
{
    return getMagnitude(a - b);
}

float getMagnitude(sf::Vector2f source)
{
    return sqrt(pow(source.x, 2) + pow(source.y, 2));
}

float getDotProduct(sf::Vector2f a, sf::Vector2f b)
{
    return (a.x * b.x) + (a.y * b.y);
}

double getHeadingAngle(sf::Vector2f source)
{
    return atan2(source.y, source.x);
}

double getAngleBetween(sf::Vector2f a, sf::Vector2f b)
{
    return acos(getDotProduct(a, b) / (double)(getMagnitude(a) * getMagnitude(b)));
}


sf::Vector2f setMagnitude(sf::Vector2f source, float newMagnitude)
{

    float currentMagnitude = getMagnitude(source);
    if (currentMagnitude == 0)
        return sf::Vector2f(0,0);
    
    float x = source.x * (newMagnitude / currentMagnitude);
    float y = source.y * (newMagnitude / currentMagnitude);
    
    return sf::Vector2f(x, y);
    
}

sf::Vector2f normalize(sf::Vector2f source)
{
    float magnitude = getMagnitude(source);
    return source / magnitude;
}

sf::Vector2f fromAngle(float angle)
{
    
    float x = cos(angle);
    float y = sin(angle);
    return sf::Vector2f(x, y);
    
}

sf::Vector2f constrain(sf::Vector2f source, float maximum)
{
    return sf::Vector2f(std::min(source.x, maximum), std::min(source.y, maximum));
}
