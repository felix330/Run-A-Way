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

GameObject::GameObject(int xPos, int yPos)
{
	x = xPos;
	y = yPos;
}

void GameObject::setPosition(int xPos, int yPos) //sets x,y to position
{
	x = xPos;
	y = yPos;
}


void GameObject::movePosition(int moveX, int moveY) //moves by a certain amount of pixels
{
	x += moveX;
	y += moveY;
}