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

Structure::Structure(Player* p, Game* g)
{
	srand(time(NULL));
	int random = rand() % 6;
	ga = g;
	pl = p;
	
	switch (random)
	{
	case 0:
		addEnemy(1);
		break;
	case 1:
		addEnemy(2);
		break;
	case 2:
		addEnemy(3);
		break;
	case 3:
		addEnemy(1);
		addEnemy(2);
		break;
	case 4:
		addEnemy(1);
		addEnemy(3);
		break;
	case 5:
		addEnemy(2);
		addEnemy(3);
		break;

	}
	delete this;
}

void Structure::addEnemy(int l)
{
	Enemy *e1 = new Enemy(pl, l, ga);
	printf("addenemy");
}