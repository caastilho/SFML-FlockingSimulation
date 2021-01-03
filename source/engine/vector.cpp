#include <engine/vector.hpp>


// Get random Vector2f between a range 
sf::Vector2f* getRandomVector(float minimum, float maximum)
{
    
    // Get random coordinates
    float x = minimum + ((float)rand() / RAND_MAX) * (maximum - minimum);
    float y = minimum + ((float)rand() / RAND_MAX) * (maximum - minimum);
    
    // Return vector
    return new sf::Vector2f(x, y);
    
}

// Get hadamard product (element-wise operation) between two vectors
sf::Vector2f* hadamard(sf::Vector2f* v1, sf::Vector2f* v2)
{
    
    // Get the product between axis
    float x = v1->x * v2->x;
    float y = v1->y * v2->y;
    
    // Return new vector
    return new sf::Vector2f(x, y);
    
}
