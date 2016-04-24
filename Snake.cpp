#include "Snake.h"
#include <iostream>
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO info;
Snake::Snake()
{
	m_vertial = 1;
	m_live = 1;
	m_length = 4;
	m_scores = 0;
	COORD pos;
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		pos.X = 15;
		pos.Y = 10 + i;
		m_body.push_back(pos);
	}
}
void Snake::draw()
{
	GetConsoleScreenBufferInfo(handle, &info);
	for (auto beg = m_body.cbegin(); beg != m_body.cend(); beg++)
	{
		SetConsoleCursorPosition(handle, *beg);
		std::cout<< '*';
	}
}
bool Snake::eat(Food ** food)
{
	COORD temp;
	temp.X = 0;
	temp.Y = 0;
	if (m_body.begin()->X == (*food)->m_position.X && m_body.begin()->Y == (*food)->m_position.Y)
	{
		m_body.push_back(temp);
		delete *food;
		*food = new Food(*this);
		return 1;
	}
	return 0;
}
bool Snake::checklive()
{
	return m_live;
}
void Snake::move()
{
	if (KEYDOWN(VK_LEFT))
	{
		if (m_vertial)
		{
			m_body.begin()->X -= 1;
			m_vertial = 0;
		}
	}
	else if (KEYDOWN(VK_RIGHT))
	{
		if (m_vertial)
		{
			m_body.begin()->X += 1;
			m_vertial = 0;

		}
	}
	else if(KEYDOWN(VK_UP))
	{
		if (!m_vertial)
		{
			m_body.begin()->Y -= 1;
			m_vertial = 1;
		}
	}
	else if(KEYDOWN(VK_DOWN))
	{
		if (!m_vertial)
		{
			m_body.begin()->Y += 1;
			m_vertial = 1;
		}
	}

	for (auto beg = m_body.rbegin(); beg != m_body.rend()-1; beg++)
	{
		*beg = *(beg + 1);
	}
}
bool Snake::checkwall()
{
	if (m_body.begin()->X == 0 || m_body.begin()->X == 45 || m_body.begin()->Y == 0 || m_body.begin()->Y == 45)
	{
		return true;
	}
	else if (m_body.begin()->X == m_body.rbegin()->X && m_body.begin()->Y == m_body.rbegin()->Y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Food::Food(Snake & snake)
{
	GetConsoleScreenBufferInfo(handle, &info);
	int posx = 10;
	int posy = 10;
		/*for (auto beg = snake.m_body.begin(); beg != snake.m_body.end(); beg++)
		{
			srand(time(0));
			posx = rand() % 43 + 1;
			posy = rand() % 43 + 1;
			if (posx != beg->X && posy != beg->Y)
			{
				break;
			}
		}*/
		m_exist = 1;
		m_position.X = posx;
		m_position.Y = posy;
		SetConsoleCursorPosition(handle, m_position);
		std::cout << '*';
}	
Wall::Wall()
{
	int row;
	int column;
	for (row = 0; row < wallrow; row++)
	{
		for (column = 0; column < wallcolumn; column++)
		{
			if (row == 0 || row == wallrow - 1)
			{
				wall[row][column] = '*';
			}
			else if (column == 0 || column == wallcolumn - 1)
			{
				wall[row][column] = '*';
			}
			else
			{
				wall[row][column] = ' ';
			}
		}
	}
}
void Wall::renew()
{
	int row;
	int column;
	for (row = 0; row < wallrow; row++)
	{
		for (column = 0; column < wallcolumn; column++)
		{
			if (row == 0 || row == wallrow - 1)
			{
				wall[row][column] = '*';
			}
			else if (column == 0 || column == wallcolumn - 1)
			{
				wall[row][column] = '*';
			}
			else
			{
				wall[row][column] = ' ';
			}
		}
	}
}
void Wall::show()
{
	COORD pos;
	pos.X = 0;
	pos.Y = 0;
	GetConsoleScreenBufferInfo(handle, &info);
	SetConsoleCursorPosition(handle, pos);
	int row;
	int column;
	for (row = 0; row < wallrow; row++)
	{
		for (column = 0; column < wallcolumn; column++)
		{
			std::cout << wall[row][column];
		
		}
	}
}

