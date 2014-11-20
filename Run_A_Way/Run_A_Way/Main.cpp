#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC


#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML Test!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	int count = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			int posX = shape.getPosition().x;
			
			count++;
			if (count == 10)
			{
				shape.setPosition((posX - 1), 0);
				count = 0;
			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			int posX = shape.getPosition().x;

			count++;
			if (count == 10)
			{
				shape.setPosition((posX + 1), 0);
				count = 0;
			}

		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	

	return 0;
}