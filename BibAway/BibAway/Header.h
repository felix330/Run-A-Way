#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

#include <SFML/Graphics.hpp>


class Level 
{
private:

public:

};


class Powerup
{
private:

public:

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
	int getLives();
	void loseLife();
	int getLane();
	void reset();
};

class Game;

class Enemy : GameObject
{
private:
	Player *pl;
	int newcurrentLane;
	bool active;

public:
	Enemy(Player* p, int lane, Game* g);
	//~Enemy();
	bool collisionCheck();
	void move(int s);
	int getX();
	int getY();
};

class Structure
{
private:
	Enemy* enemies[2];
	Player* pl;
	Game* ga;
public:
	Structure(Player* p, Game* g);
	//~Structure();
	void addEnemy(int l);
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

class Game
{
private:
	int state;
	int windowX; //Fenstergrößen
	int windowY;
	int highscore;
	int score;
	int enemyspeed;
	sf::RenderWindow window;
	sf::Sprite sprites[10];
	int count; //zählt frames
	int enemycount;
	Enemy* enemyArray[];

public:
	Game();
	//~game();
	void incScore();
	void loop();
	void doodle();
	void addEnemy(Enemy* e);
};
