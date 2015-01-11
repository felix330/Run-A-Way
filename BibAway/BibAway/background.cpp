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

Background::Background(int y)
{
	setPosition(0, y);
	count = 0;
}

int Background::getX()
{
	return getXroot();
}

int Background::getY()
{
	return getYroot();
}

void Background::move()
{
	count++;
	if (count == 1)
	{	
		if (getYroot() >= 320)
		{
			setPosition(0, -960);
		}
		else
		{
			movePosition(0, 1);
		}
		count = 0;
	}
	
}