#include "Area.h"

const int tinyShipsCount = 4;
const int tinyShipLength = 1;

const int smallShipsCount = 3;
const int smallShipLength = 2;

const int mediumShipsCount = 2;
const int mediumShipLength = 3;

const int bigShipsCount = 1;
const int bigShipLength = 4;

const int totalShipsTypeCount = 4;

Area::Area(int rows, int elements, int maxships)
{
	this->rows = rows;
	this->elements = elements;
	this->maxships = maxships;

	for (int i = 0; i < this->rows; i++)
	{
		std::vector<Cell> row;
		for (int j = 0; j < this->elements; j++)
		{
			row.push_back(Cell());
		}
		this->matrix.push_back(row);
	}
}

void Area::Clear()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			matrix[i][j].setHP(0);
		}
	}
}

int Area::NumberOfShips()
{
	int c = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (matrix[i][j].getHP() == 1)
				c++;
		}
	}
	return c;
}

void Area::SetShips()
{
	this->placeShips(tinyShipsCount, tinyShipLength);
	this->placeShips(smallShipsCount, smallShipLength);
	this->placeShips(mediumShipsCount, mediumShipLength);
	this->placeShips(bigShipsCount, bigShipLength);
}
