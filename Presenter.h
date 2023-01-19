#pragma once
#include "Area.h" 
class Presenter
{
public:
	virtual void DisplayArea(Area area) = 0;
};

class ConsolePresenter : Presenter
{
public:
	void DisplayArea(Area area) override
	{
		for (int i = 0; i < area.getRows(); i++)
		{
			for (int j = 0; j < area.getElements(); j++)
			{
				if (area.getCell(i, j).getHP() != 0)
				{
					printf("\033[41;101m%d\033[m", area.getCell(i, j).getHP());
					std::cout << " ";
				}
				else
				{
					std::cout << area.getCell(i, j).getHP() << " ";
				}
				//std::cout << area.getCell(i, j).getHP() << " ";
			}
			std::cout << std::endl;
		}
	}
};
