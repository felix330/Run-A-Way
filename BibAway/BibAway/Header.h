#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

#include <SFML/Graphics.hpp>

class Structure 
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
	int highscore;
	sf::RenderWindow window;
	sf::Sprite sprites[];
public:
	Game();
	//~game();
	void loop();
	void doodle();
};

class GameObject
{
private:
	int x;
	int y;
	int sizeX;
	int sizeY;
public:
	GameObject();
	GameObject(int xPos,int yPos);
	void setPosition(int xPos, int yPos); //sets x,y to position
	void movePosition(int moveX, int moveY); //moves by a certain amount of pixels
	int getXroot();
	int getYroot();
};

class Player : GameObject
{
private:
	int receivedCommand; //last received command
	int currentLane; //Lane in which the player currently is (1,2,3)
	int lives; //lifecount
public:
	Player();
	//~Player();
	void walkLeft();
	void walkRight();
	int getX();
	int getY();
};


class Enemy : GameObject
{
private:

public:

};

class Background : GameObject
{
private:
	int count;
public:
	Background(int y);
	void move();
	int getX();
	int getY();
};