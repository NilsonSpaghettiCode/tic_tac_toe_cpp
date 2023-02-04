#include "Board.h"
#include <iostream>

	bool ImpBoard::addSymbol(int x, int y, char symbol)
	{
		bool state = false;

			if (this->board[x][y] == ' ')
			{
				this->board[x][y] = symbol;
				state = true;
			}
		return state;
	}

	void ImpBoard::showBoard()
	{
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				std::cout << this->board[i][j]<<" | ";
			}
			std::cout << std::endl;	
		}
	}


