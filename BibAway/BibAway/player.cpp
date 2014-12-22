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
	setPosition(0, 0);
	currentLane = 2;
}

void Player::walkLeft()
{
	if (currentLane > 1)
	{
		currentLane--;
	}
}

void Player::walkRight()
{
	if (currentLane < 3)
	{
		currentLane--;
	}
}