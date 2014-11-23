#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

#include <SFML/Graphics.hpp>

void blabl();

class Structure 
{
private:

public:

};

class Enemy
{
private:

public:

};

class Level 
{
private:

public:

};

class Draw //Zeigt Bildschirminhalt
{
private:

public:

};

class Powerup
{
private:

public:

};

class Game
{
private:
	int windowX; //Fenstergrößen
	int windowY;
	sf::RenderWindow window;
public:
	Game();
	//~game();
	void loop();
};

class Playercontrol
{
private:

public:

};