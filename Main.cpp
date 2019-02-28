#include <fstream>
#include <iostream>
#include <string>
#include "Classic.h"
using namespace std;
char** randFile(int row, int col);
void display(Classic board);
void displayPause(Classic board);

int main(int argc, char** argv)
{
	char option1, mode, option3;
	cout << "Press R for a random configuration, Press F to input a file." << endl;
	cin >> option1;
	int row, col; //dimensions of grid
	int** grid;
	if(option1 == 'R' || option1 == 'r')//generate random file
	{
		cout << "Enter the Dimensions of the grid\nNumber of Rows: ";
		cin >> row;
		cout << "Number of Columns: ";
		cin >> col;
		//grid = randFile(row, col);
	}
	else if(option1 == 'F' || option1 == 'f')
	{
		string path;
		cout << "File Name: ";
		cin >> path;
		ifstream file;
		file.open(path, ifstream::in);
		string rows, cols;
		if(!file.eof())
			getline(file, rows);
		if(!file.eof())
			getline(file, cols);
		row = stoi(rows);
		col = stoi(cols);
		grid = new int*[row];
		for(int i = 0; i < row; i++)
		{
			grid[i] = new int[col];
			string line;
			getline(file, line);
			for(int j = 0; j < line.length(); j++)
			{
				if(line[j] == 'X')
					grid[i][j] = 1;
				if(line[j] == '-')
					grid[i][j] = 0;
			}
		}
		file.close();
	}
	cout << "Enter C for Classic Mode, D for Doughnut Mode, M for Mirror Mode. "; //promt boundary mode
	cin >> mode;
	Mode board;
	if(mode == 'C' || mode == 'c')
	{
		board = Classic(grid, row, col);
	}
	else if(mode == 'D' || mode == 'd')
	{
		//implement later
	}
	else if(mode == 'M' || mode == 'm')
	{
		//implement later
	}
	board.display();
/*
	cout << board.neighbors(1,0) << endl;
	cout << board.neighbors(1,1) << endl;
	cout << board.neighbors(1,2) << endl;
	cout << board.neighbors(1,3) << endl;
	cout << board.neighbors(1,4) << endl;
	cout << board.neighbors(1,5) << endl;
	cout << board.neighbors(1,6) << endl; */

	cout << "would you like a pause(P) between generations,\nor would you like to press enter(E) between generations? ";
	cin >> option3;
	if(option3 == 'P' || option3 == 'p')
	{
		displayPause(board);
	}
	else if(option3 == 'E' || option3 == 'e')
	{
		display(board);
	}
	return 0;
}
char** randFile(int row, int col)
{
	return new char*[0];
}
void display(Mode board)
{
	board.generation();
	board.display();
}
void displayPause(Mode board)
{
	board.generation();
	board.display();
}
