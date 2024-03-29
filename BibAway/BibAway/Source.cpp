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
	state = 0;
	score = 0;
	highscore = 0;
	enemycount = 0;
	count = 0;
	enemyspeed = 2;
	spawncounter = 0;
	spawnlimit = 60;
	
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

	//Enemy
	sf::Texture enemyTexL;
	if (!enemyTexL.loadFromFile("enemy_left.png"))
	{
	}
	sf::Texture enemyTexR;
	if (!enemyTexR.loadFromFile("enemy_right.png"))
	{
	}
	sf::Sprite enemySpr;
	enemySpr.setTexture(enemyTexL);
	int enemyanimstate=0;
	
	//Start/Endscreen

	sf::Texture starttex;
	if (!starttex.loadFromFile("titel.png"))
	{ }
	sf::Sprite startspr;
	startspr.setTexture(starttex);

	sf::Texture gotex;
	if (!gotex.loadFromFile("game_over.png"))
	{}
	sf::Sprite gospr;
	gospr.setTexture(gotex);

	//Font
	sf::Font mainfont;

	if (!mainfont.loadFromFile("arial.ttf"))
	{
	}

	sf::Text scoretext;
	sf::Text livetext;

	//Create Objects for start of game
	Player player1;
	
	//Enemy w1(&player1, 2, this);
	//Structure s1(&player1, this);
	//Structure s2(&player1, this);
	Background bg1(-640);
	Background bg2(0);

	//Main Loop
	while (window.isOpen()) 
	{


		sf::Event event;
		while (window.pollEvent(event)) //Fenster eventabfrage
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left && state == 1)
				{
					
					player1.walkLeft();
				}
				if (event.key.code == sf::Keyboard::Right && state == 1)
				{
					
					player1.walkRight();
				}
				if (event.key.code == sf::Keyboard::Return && state == 0)
				{
					state = 1;
					printf("start");
				}

				if (event.key.code == sf::Keyboard::Return && state == 2)
				{
					state = 1;
					score = 0;
					player1.reset();
					printf("start");

					for (int i = 0; i < enemycount; i++){
						delete enemyArray[i];
						enemyArray[i] = NULL;
					}
					enemycount = 0;
					enemyspeed = 2;
					spawncounter = 0;
					spawnlimit = 60;
				}
			}
			
		}


		//Interface text
		char scorevalue[50];
		itoa(score, scorevalue, 10);
		scoretext.setFont(mainfont); 
		scoretext.setString(scorevalue);
		scoretext.setPosition(0, 0);
		scoretext.setCharacterSize(12);
		scoretext.setColor(sf::Color::Black);

		itoa(player1.getLives(), scorevalue, 10);
		livetext.setFont(mainfont);
		livetext.setString(scorevalue);
		livetext.setCharacterSize(12);
		livetext.setColor(sf::Color::Black);

		//player function calls

		//Fenster Darstellung
		window.clear();

		if (state == 0)
		{
			window.draw(startspr);
		}
	
		if (state == 1)
		{
			counter++;
			incScore();
			//Draw Sprites
			bg1.move();
			bg2.move();
			backgroundspr.setPosition(bg1.getX(), bg1.getY());
			window.draw(backgroundspr);
			backgroundspr.setPosition(bg2.getX(), bg2.getY());
			window.draw(backgroundspr);

			//Player Animation
			if (counter == 10 || counter == 20 || counter == 30 || counter == 40 || counter == 50 || counter == 60)
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

			playerspr.setPosition(player1.getX(), player1.getY());
			player1.getLane();
			window.draw(playerspr);

			if (player1.getLives() <= 0)
			{
				state = 2;
			}

			//Enemy from here!!!
			if (spawncounter >= spawnlimit)
			{
				Structure *s = new Structure(&player1, this);
				spawncounter = 0;
			}
			spawncounter++;

			if (counter == 10 || counter == 20 || counter == 30 || counter == 40 || counter == 50 || counter == 60)
			{
				enemyanimstate++;
				if (enemyanimstate > 2)
				{
					enemyanimstate = 1;
				}
			}


			//EnemyAnimation
			switch (enemyanimstate)
			{
			case 1:
				enemySpr.setTexture(enemyTexL);
				break;
			case 2:
				enemySpr.setTexture(enemyTexR);
				break;
			}
			
			for (int i = 0; i < enemycount; i++){
				if (enemyArray[i] != NULL)
				{
					enemySpr.setPosition(enemyArray[i]->getX(), enemyArray[i]->getY());
					enemyArray[i]->move(enemyspeed);
					window.draw(enemySpr);
					if (enemyArray[i]->getY() > 320)
					{
						delete enemyArray[i];
						enemyArray[i] = NULL;
					}
				}

			}
			
			switch (score)
			{
			case 10:
				enemyspeed = 3;
				break;
			case 20:
				spawnlimit = 40;
				enemyspeed = 4;
				break;
			case 40:
				spawnlimit = 30;
				enemyspeed = 5;
				break;
			case 80:
				spawnlimit = 20;
				enemyspeed = 6;
				break;

			}
			//Draw Text

			window.draw(scoretext);
			livetext.setPosition(230, 0);
	
			window.draw(livetext);

			//---
		}

		if (state == 2) //Game over
		{
			
			if (score > highscore)
			{
				highscore = score;
			}

			window.draw(gospr);
			scoretext.setPosition(150, 200);
			window.draw(scoretext);

			sf::Text t;
			t.setFont(mainfont);
			t.setCharacterSize(12);
			t.setColor(sf::Color::Black);
			t.setPosition(50, 200);
			t.setString("Your Time: ");
			window.draw(t);

			//---------------------------

			char newvalue[10];
			scoretext.setPosition(150, 250);
			itoa(highscore, newvalue, 10);
			scoretext.setString(newvalue);
			window.draw(scoretext);

			sf::Text s;
			s.setFont(mainfont);
			s.setCharacterSize(12);
			s.setColor(sf::Color::Black);
			s.setPosition(50, 250);
			s.setString("Best Time: ");
			window.draw(s);
			
		}
		
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
		printf("count");
		score++;
		count = 0;
	}
}

void Game::addEnemy(Enemy* e)
{
	
	enemyArray[enemycount]=e;
	enemycount++;
}

