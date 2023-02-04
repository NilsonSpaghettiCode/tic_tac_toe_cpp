#pragma once

class Board
{
public:
	virtual bool addSymbol(int x, int y, char symbol) = 0;
private:

};

class ImpBoard: Board
{

public:
	bool addSymbol(int x, int y, char symbol);
	void showBoard();
	bool ticTacToe();
	
private:
	char board[3][3] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};
};

