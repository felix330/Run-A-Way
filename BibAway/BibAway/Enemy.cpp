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

Enemy::Enemy(Player* p, int lane, Game* g){
	setPosition((30+((lane-1)*60)), -20);		//-Wert evtl ändern
	pl = p;
	newcurrentLane = lane;
	g->addEnemy(this);
	active = true;
}



bool Enemy::collisionCheck(){
	
	//int playerLane = pl->getLane();
	bool c=false;
	int collisionY = getYroot()+32;

	/*char scorevalue[50];
	itoa(collisionY, scorevalue, 10);
	printf("position: ");
	printf(scorevalue);

	printf("currentlane: ");
	itoa(currentLane, scorevalue, 10);
	printf(scorevalue);

	printf("Playerlane: ");
	itoa(playerLane, scorevalue, 10);
	printf(scorevalue);*/

	if (newcurrentLane == pl->getLane() && collisionY >= 258 && collisionY <= 310 && active==true){
		c = true;
		pl->loseLife();
		setPosition(-50, -50);
		active = false;
	}

	
	return c;
	return false;
}

void Enemy::move(int s){

	if (active == true)
	{
		movePosition(0, s);
		collisionCheck();
	}
	
}

int Enemy::getX()
{
	return getXroot();
}

int Enemy::getY()
{
	return getYroot();
}