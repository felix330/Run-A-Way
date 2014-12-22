#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>

#include "Header.h"


Game::Game()
{
	windowX = 240;
	windowY = 320;

	
}

void Game::loop()
{
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Run a Way");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	Player player1;

	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event)) //Schlieﬂt wenn Fenster zu
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					printf("goleft");
					player1.walkLeft();
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					printf("goright");
					player1.walkRight();
				}
			}
			
		}

		//Spieler Funktionsaufrufe
		player1.readCommands();

		//Fenster Darstellung
		window.clear();
		window.draw(shape);
		window.display();
	}
}

void Game::doodle()
{

}