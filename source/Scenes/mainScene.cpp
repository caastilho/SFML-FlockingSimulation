#include <Scenes/mainScene.hpp>


// Setup scene environment
void MainScene::setup(sf::RenderWindow* _renderer, AssetsManager manager)
{
    
    renderer = _renderer;
    width = renderer->getSize().x;
    height = renderer->getSize().y;

    background.setSize(sf::Vector2f(width, height));
    texture.create(width, height);
    sprite.setTexture(texture.getTexture());
    
    // Setup random engine
    srand(time(NULL));
    
    
    // Setup final image path
    path = "/home/castilho/Videos/002 - Flock Simulation/flock_videos/0/";
    
    // Setup background
    background_color = sf::Color(10, 8, 20);
    sf::Color rectangle_color(background_color);
    rectangle_color.a = 140;
    background.setFillColor(rectangle_color);
    
    // Setup boids vector
    for (int i = 0; i < 100; i++)
    {

        // Get random position
        float x = ((float)rand() / (float)RAND_MAX) * width;
        float y = ((float)rand() / (float)RAND_MAX) * height;
        
        // Get random color
        float random_value = ((float)rand() / (float)RAND_MAX); 
        
        int r = (int)map(random_value, 0.f, 1.f, 220.f,   0.f);
        int g = (int)map(random_value, 0.f, 1.f,  10.f,   50.f);
        int b = (int)map(random_value, 0.f, 1.f,   0.f, 220.f); 
        
        // Create boid object
        Boid boid(x, y, sf::Color(r, g, b));

        // Append to array
        boids.push_back(boid);

    }
    
    //renderer->clear(background_color);
    texture.clear(background_color);
    
}

// Run scene environment
void MainScene::run(bool isFocused)
{
    
    renderer->draw(background);
    //texture.clear(background_color);
    //renderer->clear();
    
    // Iterate thru boids array
    for (Boid& boid : boids)
    {
        boid.update(boids);
        boid.constrain(width, height);
        boid.display(renderer);
    }
    
    // Display objects
    ///renderer->draw(sprite);
    
    // Save frame to file
    //texture.getTexture().copyToImage().saveToFile(path + std::to_string(index) + ".png");
    //index++;
    
}

// Run scene event handler
void MainScene::events(sf::Event& action)
{
    
}
