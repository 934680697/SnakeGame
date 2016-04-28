#include"Snake.h"
#include <stdio.h>
int main()
{

	system("MODE con: COLS=45 LINES=45");
	Snake * ps = new Snake();
	Wall * pw = new Wall();
	Food * pf = new Food(*ps);
	while (!ps->checkwall() && !KEYDOWN(VK_ESCAPE) && !ps->checkbody())
	{
		Sleep(50);
		system("cls");
		pw->show(&pf);
		ps->draw();
		ps->move();
		ps->eat(&pf);
				
	}
	system("cls");
	printf(" Game Over");
	system("pause");
	return 0;
}
