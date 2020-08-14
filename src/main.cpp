#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <array>

#include "resources.hpp"

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	sf::Vector2f windowSize = window.getView().getSize();
	Resources::window = &window;
	Resources::load();


	// create buttons
	float buttonSizePercentage = 0.1;
	int radius = windowSize.x * buttonSizePercentage;
	int diameter = radius * 2;
	size_t edges = 30;
	std::array<sf::CircleShape, 6> buttons;
	sf::CircleShape button(radius, edges);
	button.setFillColor(sf::Color::Green);
	const int columns = 3;
	const int rows = 2;
	int columnGap = (windowSize.x - (diameter * columns)) / (columns + 1);
	int rowGap = (windowSize.y - (diameter * rows)) / (rows + 1);

	// generate button positions
	std::array<sf::Vector2f, 6> buttonPositions;
	for(size_t y = 0; y < rows; ++y)
	{
		for(size_t x = 0; x < columns; ++x)
		{
			buttonPositions.at(x + y * columns).x = columnGap * x + diameter * x;
			buttonPositions.at(x + y * columns).y = rowGap + y * diameter;
		}
	}

	// apply button positions
	for(size_t i = 0; i < 6; ++i)
	{
		buttons.at(i) = button;
		buttons.at(i).setPosition(buttonPositions.at(i));
	}

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear();

		// Draw objects here

		// Update the window
		window.display();
	}
	Resources::unload();
	return EXIT_SUCCESS;
}
