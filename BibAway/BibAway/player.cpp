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

Player::Player()
{
	setPosition(90, 260);
	currentLane = 2;
	lives = 3;

	

}

void Player::walkLeft()
{
	if (currentLane > 1)
	{
		currentLane--;
	}
	
	if (currentLane == 1)
	{
		setPosition(30, 260);
	}
	else if (currentLane == 2)
	{
		setPosition(90, 260);
	}

}

void Player::walkRight()
{
	if (currentLane < 3)
	{
		currentLane++;
	}

	if (currentLane == 2)
	{
		setPosition(90, 260);
	}
	else if (currentLane == 3)
	{
		setPosition(150, 260);
	}
}

int Player::getX()
{
	return getXroot();
}

int Player::getY()
{
	return getYroot();
}

void Player::loseLife()
{
	lives--;
}

void Player::reset()
{
	lives = 3;
	currentLane = 2;
}

int Player::getLives()
{
	return lives;
}

int Player::getLane()
{

	/*char scorevalue[50];
	printf("Playerlane: ");
	itoa(currentLane, scorevalue, 10);
	printf(scorevalue);*/
	return currentLane;
}