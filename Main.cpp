#include <fstream>
#include <iostream>
#include <string>
#include "Classic.h"
#include "Donut.h"
#include "Mirror.h"
using namespace std;
char** randFile(int row, int col);
void display(Mirror* board);
void displayPause(Mirror* board);

int main(int argc, char** argv)
{
	char option1, mode, option3;
	cout << "Press R for a random configuration, Press F to input a file." << endl;
	cin >> option1;
	int row, col; 																										 //dimensions of grid
	int** grid;
	if(option1 == 'R' || option1 == 'r')                               //generate random file
	{
		cout << "Enter the Dimensions of the grid\nNumber of Rows: "; 	 //user defined dimensions
		cin >> row;
		cout << "Number of Columns: ";
		cin >> col;
		//grid = randFile(row, col);
	}
	else if(option1 == 'F' || option1 == 'f')
	{
    //read file
		string path;
		cout << "File Name: ";
		cin >> path;
		ifstream file;
		file.open(path, ifstream::in);
		string rows, cols;
		if(!file.eof())
			getline(file, rows); 																					 //read first two lines for dimenstions(this is a string)
		if(!file.eof())
			getline(file, cols);
		row = stoi(rows);                                                //read int from string dimensions
		col = stoi(cols);
		grid = new int*[row];
		for(int i = 0; i < row; i++) 																		 //loop thru rest of file
		{
			grid[i] = new int[col];
			string line; 																									 //local var line to hold one line at a time as we read
			getline(file, line);
			for(int j = 0; j < line.length(); j++)
			{
				if(line[j] == 'X')																					 //index of line corresponds to index of row, line index
					grid[i][j] = 1;
				if(line[j] == '-')
					grid[i][j] = 0;
			}
		}
		file.close();
	}
	cout << "Enter C for Classic Mode, D for Doughnut Mode, M for Mirror Mode. "; //promt boundary mode
	cin >> mode;
	//Mode board;
	if(mode == 'C' || mode == 'c')
	{
		//board = Classic(grid, row, col);
	}
	else if(mode == 'D' || mode == 'd')
	{
		//implement later
	}
	else if(mode == 'M' || mode == 'm')
	{
		//implement later
	}
	Mirror* board = new Mirror(grid, row, col);
	board->display();
	cout << "would you like a pause(P) between generations,\nor would you like to press enter(E) between generations? ";
	cin >> option3;
	if(option3 == 'P' || option3 == 'p')
	{
		for(int i = 0; i < 5; i++)
			displayPause(board);
	}
	else if(option3 == 'E' || option3 == 'e')
	{
		for(int i = 0; i < 5; i++)
			display(board);
	}
	return 0;
}
char** randFile(int row, int col)
{
	return new char*[0];
}
void display(Mirror* board)
{
	board->generation();
	board->display();
}
void displayPause(Mirror* board)
{
	board->generation();
	board->display();
}
