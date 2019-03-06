#ifndef CLASSIC_H
#define CLASSIC_H
#ifndef DONUT_H
#define DONUT_H
#ifndef MIRROR_H
#define MIRROR_H
#ifndef MODE_H
#define MODE_H
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
#include "Mode.h"
#include "Classic.h"
#include "Donut.h"
#include "Mirror.h"

using namespace std;
int** randFile(int row, int col, float d);
void display(Mode* board);
void displayPause(Mode* board);

int main(int argc, char** argv)
{
	char option1, mode, option3;
	cout << "Press R for a random configuration, Press F to input a file." << endl;
	cin >> option1;
	int row, col; 																										 //dimensions of grid
	int** grid;
	if(option1 == 'R' || option1 == 'r')                               //generate random file
	{
		float density;
		cout << "Enter the Dimensions of the grid\nNumber of Rows: "; 	 //user defined dimensions
		cin >> row;
		cout << "Number of Columns: ";
		cin >> col;
		cout << "Enter the population density: ";
		cin >> density;
		if(row <= 0 || col <= 0 || density > 1 || density <= 0)
		{
			cout << "Error, please enter valid numbers." << endl;
			return 1;
		}
		grid = randFile(row, col, density);
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
	else
	{
		cout << "Error, please enter a valid option." << endl;
		return 1;
	}
	cout << "Enter C for Classic Mode, D for Doughnut Mode, M for Mirror Mode. "; //promt boundary mode
	cin >> mode;

	Mode *board;
	Classic  *c_board;
	if(mode == 'C' || mode == 'c'){
		 *c_board = new Classic(grid, row, col);
		board = &c_board;
	}
	else if(mode == 'D' || mode == 'd')
	{
		Donut *d_board = new Donut(grid, row, col);
		board = &d_board;

	}
	else if(mode == 'M' || mode == 'm'){
		 Mirror	*m_board = new Mirror(grid, row, col);
			board = &m_board;
	}

	else
	{
		cout << "Error, please enter a valid option." << endl;
		return 1;
	}
	cout << "would you like a pause(P) between generations, would you like to press enter(E) between generations, or would you like to write to a file(F)? ";
	cin >> option3;
	if(option3 == 'P' || option3 == 'p')
	{
		int i = 0;
		while(i > 1000 || !board->isStable())
		{
			cout << "Generation " << i++ << endl;
			displayPause(board);
		}
	}
	else if(option3 == 'E' || option3 == 'e')
	{
		int i = 0;
		while(i > 1000 || !board->isStable())
		{
			cout << "Generation " << i++ << endl;
			display(board);
		}
	}
	else if(option3 == 'F' || option3 == 'f')
	{
		ofstream out;                                                                 //create the out stream
		out.open("rose.out", ofstream::trunc);                                        //open the file, delete contents
		int i = 0;
		while(i > 1000 || !board->isStable())
		{
			out << "Generation " << i << endl;
			out << board->displayString();
			board->generation();
		}
	}
	else
	{
		cout << "Error, please enter a valid option." << endl;
		return 1;
	}
	return 0;
}
int** randFile(int row, int col, float d)
{
	srand(time(0));
	int count = 0;
	int total = row * col;
	int** g = new int*[row];
	for(int i = 0; i < row; i++)
	{
		g[i] = new int[col];
		for(int j = 0; j < col; j++)
		{
			if((count / total) <= d)
			{
				g[i][j] = rand() % 2;
					count += g[i][j];
			}
		}
	}
	return g;
}
void display(Mode* board)
{
	cin.clear();
	board->display();
	board->generation();
	cin.get();
}
void displayPause(Mode* board)
{
	board->display();
	board->generation();
	this_thread::sleep_for (chrono::seconds(1));
}
#endif
#endif
#endif
#endif
