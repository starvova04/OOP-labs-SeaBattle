#include <iostream>
#include "Area.h"
#include "Presenter.h"
#include <ctime>

const int rows = 10;
const int elements = 10;

int main()
{
	srand(time(NULL));
	Area bot = Area(rows, elements, 10);
	Area user = Area(rows, elements, 10);

	ConsolePresenter presenter;
	bot.SetShips();
	user.SetShips();
	std::cout << "My position: " << std::endl;
	presenter.DisplayArea(user);
	std::cout << std::endl;
	std::cout << "Bot position: " << std::endl;
	presenter.DisplayArea(bot);

	return 0;
}