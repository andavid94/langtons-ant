/*
 ** Author: David An
 ** Date: Jan 15 2018
 ** Description: This program will run the Langton's Ant simulation
 */

#include <iostream>
#include <string>
#include "inputValidation.hpp"
#include "Ant.hpp"
#include "menu.hpp"

int main() {
	
	int input = beginGame();
	if (input == 2) return 0;
	int playAgain;
	
	do {
		std::cout << "Enter the desired number of rows for the board (Max = 10)\n";
		int rows = inputValidation(1, 10);
		
		std::cout << "Enter the desired number of columns for the board (Max = 10)\n";
		int columns = inputValidation(1, 10);
		
		std::cout << "Enter the desired number of steps the simulation will run through (Max = 75)\n";
		int steps = inputValidation(1, 75);
		
		std::cout << "Enter the desired starting row for the ant\n";
		int startingRow = inputValidation(1, rows);
		startingRow = startingRow - 1;
		
		std::cout << "Enter the desired starting column for the ant\n";
		int startingColumn = inputValidation(1, columns);
		startingColumn = startingColumn - 1;
		
		// create dynamic 2D char array
		char** board = new char*[rows];
		for (int i = 0; i < rows; i++) {
			board[i] = new char[columns];
		}
		
		// initialize board to contain only spaces
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				board[i][j] = ' ';
			}
		}
		
		// put the ant symbol at the starting location
		board[startingRow][startingColumn] = '*';
		
		// print the board
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				std::cout << board[i][j] << " ";
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}
		
		Ant theAnt(startingRow, startingColumn);
		
		// simulate through the given number of steps
		for (int i = 0; i < steps; i++) {
			// for the first step, have theAnt move up one square
			if (i == 0) {
				board[theAnt.getPrevRow()][theAnt.getPrevColumn()] = '#';
				startingRow = theAnt.getCurrentRow() - 1;  // re-position theAnt
				
				if (startingRow < 0) {
					startingRow = rows - 1; 	// wrap theAnt around the board
				}
				theAnt.setCurrentRow(startingRow);  // reset theAnt's properties
				
				// keep track of the current square's color
				if (board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] == '#') {
					theAnt.setSquareState('#');
				} else {
					theAnt.setSquareState(' ');
				}
				
				// prepare the board to re-print
				board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] = '*';
				
				theAnt.setDirection(up);
			} else if (theAnt.getSquareState() == ' ') {
				board[theAnt.getPrevRow()][theAnt.getPrevColumn()] = '#';
				
				if (theAnt.getDirection() == up) {
					startingColumn = theAnt.getCurrentColumn() + 1;
					
					if (startingColumn >= columns) {
						startingColumn = 0;
					}
					theAnt.setCurrentColumn(startingColumn);
					
					if (board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] == '#') {
						theAnt.setSquareState('#');
					} else {
						theAnt.setSquareState(' ');
					}
					
					board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] = '*';
					
					theAnt.setDirection(right);
				} else if (theAnt.getDirection() == right) {
					startingRow = theAnt.getCurrentRow() + 1;
					
					if (startingRow >= rows) {
						startingRow = 0;
					}
					theAnt.setCurrentRow(startingRow);
					
					if (board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] == '#') {
						theAnt.setSquareState('#');
					} else {
						theAnt.setSquareState(' ');
					}
					
					board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] = '*';
					
					theAnt.setDirection(down);
				} else if (theAnt.getDirection() == down) {
					startingColumn = theAnt.getCurrentColumn() - 1;
					
					if (startingColumn < 0) {
						startingColumn = columns - 1;
					}
					theAnt.setCurrentColumn(startingColumn);
					
					if (board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] == '#') {
						theAnt.setSquareState('#');
					} else {
						theAnt.setSquareState(' ');
					}
					
					board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] = '*';
					
					theAnt.setDirection(left);
				} else if (theAnt.getDirection() == left) {
					startingRow = theAnt.getCurrentRow() - 1;
					
					if (startingRow < 0) {
						startingRow = rows - 1;
					}
					theAnt.setCurrentRow(startingRow);
					
					if (board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] == '#') {
						theAnt.setSquareState('#');
					} else {
						theAnt.setSquareState(' ');
					}
					
					board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] = '*';
					
					theAnt.setDirection(up);
				}
			} else if (theAnt.getSquareState() == '#') {
				board[theAnt.getPrevRow()][theAnt.getPrevColumn()] = ' ';
				
				if (theAnt.getDirection() == up) {
					startingColumn = theAnt.getCurrentColumn() - 1;
					
					if (startingColumn < 0) {
						startingColumn = columns - 1;
					}
					theAnt.setCurrentColumn(startingColumn);
					
					if (board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] == '#') {
						theAnt.setSquareState('#');
					} else {
						theAnt.setSquareState(' ');
					}
					
					board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] = '*';
					
					theAnt.setDirection(left);
				} else if (theAnt.getDirection() == left) {
					startingRow = theAnt.getCurrentRow() + 1;
					
					if (startingRow > rows) {
						startingRow = 0;
					}
					theAnt.setCurrentRow(startingRow);
					
					if (board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] == '#') {
						theAnt.setSquareState('#');
					} else {
						theAnt.setSquareState(' ');
					}
					
					board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] = '*';
					
					theAnt.setDirection(down);
				} else if (theAnt.getDirection() == down) {
					startingColumn = theAnt.getCurrentColumn() + 1;
					
					if (startingColumn >= columns) {
						startingColumn = 0;
					}
					theAnt.setCurrentColumn(startingColumn);
					
					if (board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] == '#') {
						theAnt.setSquareState('#');
					} else {
						theAnt.setSquareState(' ');
					}
					
					board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] = '*';
					
					theAnt.setDirection(right);
				} else if (theAnt.getDirection() == right) {
					startingRow = theAnt.getCurrentRow() - 1;
					
					if (startingRow < 0) {
						startingRow = rows - 1;
					}
					theAnt.setCurrentRow(startingRow);
					
					if (board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] == '#') {
						theAnt.setSquareState('#');
					} else {
						theAnt.setSquareState(' ');
					}
					
					board[theAnt.getCurrentRow()][theAnt.getCurrentColumn()] = '*';
					
					theAnt.setDirection(up);
				} 
			}
			
			// print the board
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					std::cout << board[i][j] << " ";
				}
				std::cout << std::endl;
				std::cout << std::endl;
			}
			
			theAnt.setPrevRow(startingRow);
			theAnt.setPrevColumn(startingColumn);
		}
		
		
		// free the dynamically allocated memory
		for (int i = 0; i < rows; i++) {
			delete [] board[i];
		}
		delete [] board;
		
		playAgain = reprompt();  // ask user if they want to play 
	}
	
	while (playAgain == 1);
	
	return 0;
}



