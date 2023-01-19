#pragma once
#include "Cell.h"
#include <iostream>
#include <vector>

enum Orientation {
	NORTH,
	EAST,
	WEST,
	SOUTH,
	TOTAL,
};

class Area
{
private:
	std::vector<std::vector<Cell> > matrix;
	int rows;
	int elements;
	int maxships;

	bool isShipExists(int x, int y) {
		return this->matrix[x][y].getHP() != 0;
	}

	bool isShipExistsNearBy(int x, int y) {
		if (x > 0) {
			if (this->isShipExists(x - 1, y)) {
				return true;
			}
		}

		if (x < this->rows - 1) {
			if (this->isShipExists(x + 1, y)) {
				return true;
			}
		}

		if (y > 0) {
			if (this->isShipExists(x, y - 1)) {
				return true;
			}
		}

		if (y < this->elements - 1) {
			if (this->isShipExists(x, y + 1)) {
				return true;
			}
		}

		return false;
	}

	void addShip(int startX, int startY, int length, Orientation orientation) {
		int x = startX;
		int y = startY;

		for(int i = 0; i < length; i++) {
			matrix[x][y].setHP(1);

			switch (orientation) {
				case Orientation::NORTH: {y--; break;}
				case Orientation::EAST: {x++; break;}
				case Orientation::WEST: {x--; break;}
				case Orientation::SOUTH: {y++; break;}
			}
		}
	}

	void placeShips(int shipsAmount, int shipLength) {
		for(int i = 0; i < shipsAmount; i++) {
			int x, y;
			Orientation orientation;

			do{
			    x = rand() % this->rows;
			    y = rand() % this->elements;
			 	orientation = static_cast<Orientation>(rand() % Orientation::TOTAL);
			} while (!this->isAbleToAddShip(x, y, shipLength, orientation));
			this->addShip(x, y, shipLength, orientation);
		}
	}

	bool isAbleToAddShip(int startX, int startY, int length, Orientation orientation) {
		int x = startX;
		int y = startY;

		for (int i = 0; i < length; i++) {

			if (this->isEdgeCase(x, y)) {
				return false;
			}

			if (this->isShipExists(x, y) || this->isShipExistsNearBy(x, y)) {
				return false;
			}

			switch (orientation) {
				case Orientation::NORTH: {y--; break;}
				case Orientation::EAST: {x++; break;}
				case Orientation::WEST: {x--; break;}
				case Orientation::SOUTH: {y++; break;}
			}
		}

		return true;
	}

	bool isEdgeCase(int x, int y) {
		if (x < 0 || x >= rows) {
			return true;
		}

		if (y < 0 || y >= elements) {
			return true;
		}

		return false;
	}

public:
	Area(int rows, int elements, int maxships);

	void Clear(); 

	int NumberOfShips();

	void SetShips();

	int getRows() const
	{
		return this->rows;
	}

	int getElements() const
	{
		return this->elements;
	}

	Cell getCell(int x, int y) const
	{
		return this->matrix[x][y];
	}
};
