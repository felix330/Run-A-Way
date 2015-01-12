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
	score = 0;
	count = 0;
}

void Game::loop()
{
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Run a Way");
	window.setFramerateLimit(60);
	int counter=0;

	//Load Sprites here
	sf::Texture playertexM;
	if (!playertexM.loadFromFile("up_middel.png"))
	{
	}
	sf::Texture playertexL;
	if (!playertexL.loadFromFile("up_left.png"))
	{
	}
	sf::Texture playertexR;
	if (!playertexR.loadFromFile("up_right.png"))
	{
	}

	sf::Sprite playerspr;
	playerspr.setTexture(playertexM);
	int playeranimstate = 1;

	sf::Texture backgroundtex; //Background
	if (!backgroundtex.loadFromFile("background.png"))
	{
		// error...
		printf("error");
	}
	sf::Sprite backgroundspr;
	backgroundspr.setTexture(backgroundtex);

	//Font
	sf::Font mainfont;

	if (!mainfont.loadFromFile("arial.ttf"))
	{
	}

	sf::Text scoretext;

	//Create Objects for start of game
	Player player1;

	Background bg1(-640);
	Background bg2(0);

	//Main Loop
	while (window.isOpen()) 
	{
		counter++;

		sf::Event event;
		while (window.pollEvent(event)) //Fenster eventabfrage
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					
					player1.walkLeft();
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					
					player1.walkRight();
				}
			}
			
		}

		incScore();

		//Interface text
		char scorevalue[50];
		itoa(score, scorevalue, 10);
		scoretext.setFont(mainfont); 
		scoretext.setString(scorevalue);
		scoretext.setCharacterSize(12);
		scoretext.setColor(sf::Color::Black);

		//player function calls

		//Fenster Darstellung
		window.clear();

	

		//Draw Sprites
		bg1.move();
		bg2.move();
		backgroundspr.setPosition(bg1.getX(), bg1.getY());
		window.draw(backgroundspr);
		backgroundspr.setPosition(bg2.getX(), bg2.getY());
		window.draw(backgroundspr);

		//Player Animation
		if (counter == 20 || counter == 40 || counter == 60)
		{
			playeranimstate++;
			if (playeranimstate > 4)
			{
				playeranimstate = 1;
			}
		}

		switch (playeranimstate)
		{
		case 1:
			playerspr.setTexture(playertexL);
			break;
		case 2:
			playerspr.setTexture(playertexM);
			break;
		case 3:
			playerspr.setTexture(playertexR);
			break;
		case 4:
			playerspr.setTexture(playertexM);
			break;
		}

		playerspr.setPosition(player1.getX(),player1.getY());
		window.draw(playerspr);

		//Draw Text
		
		window.draw(scoretext);

		//---
		window.display();

		if (counter == 60)
		{
			counter = 0;
		}
	}
}

void Game::doodle()
{

}

void Game::incScore()
{
	count++;
	if (count == 60)
	{
		score++;
		count = 0;
	}
}