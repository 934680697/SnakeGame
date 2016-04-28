#ifndef Snake_h_
#define Snake_h_
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)
#include <Windows.h>
#include <vector>
#include <ctime>
#include <cstdlib>
const int wallrow = 43;
const int wallcolumn = 45; 
enum direction{ up = 1, down, left, right };
class Snake;
class Food
{
public:
	Food(Snake & snake);
	bool m_exist;
	COORD m_position;
};
class Wall
{
	friend class Food;
public:
	Wall();
	void renew();
	void show(Food **);
private:
	char wall[wallrow][wallcolumn];
};
class Snake
{
	friend class Food;
public:
	Snake();
	void draw();
	bool eat(Food ** food);
	bool checklive();
	void move();
	bool checkwall();
	bool checkbody();
	//void show(Wall & wall);
private:
	bool m_vertial;
	bool m_live;
	std::vector<COORD>m_body;
	int m_length;
	int m_scores;	
	int m_direction;
};

#endif
