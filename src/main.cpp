#include <SFML/Graphics.hpp>

#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "My Game");

	// Create a circle shape
	sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(350.f, 250.f));
	

	// Add the shape to be drawn in the window
	// (draw inside the game loop)
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        std::optional<sf::Event> event;
        while ((event = window.pollEvent()))
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clear screen
        window.clear();

        // Draw the shape
        window.draw(shape);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
