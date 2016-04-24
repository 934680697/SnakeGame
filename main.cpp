#include"Snake.h"
int main()
{
	system("MODE con: COLS=45 LINES=45");
	Snake * ps = new Snake();
	Wall * pw = new Wall();
	Food * pf = new Food(*ps);
	while (ps->checklive() && !KEYDOWN(VK_ESCAPE))
	{
		pw->renew();
		ps->move();
		ps->eat(&pf);
		ps->checkwall();
		ps->draw();
	}
	
	
	//system("cls");
	//printf(" Game Over");
	system("pause");
	return 0;
}