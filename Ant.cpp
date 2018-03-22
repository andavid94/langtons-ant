/*
 ** Author: David An
 ** Date: Jan 15 2018
 ** Description: Ant.cpp contains all of the Ant class's methods that
 ** 			 are used in the Langton's ant simulation
 */

#include "Ant.hpp"
#include <iostream>

Ant::Ant() {
	
}

Ant::Ant(int row, int column) {
	setDirection(up);
	setSquareState(' ');
	setPrevRow(row);
	setPrevColumn(column);
	setCurrentRow(row);
	setCurrentColumn(column);
}

// sets the direction/orientation of the Ant
void Ant::setDirection(Direction dir) {
	direction = dir;
}

// returns the current direction of the Ant
Direction Ant::getDirection() {
	return direction;
}

// sets the current square color
void Ant::setSquareState(char newState) {
	squareState = newState;
}

// returns the current square color
char Ant::getSquareState() {
	return squareState;
}

// sets the Ant's previous row 
void Ant::setPrevRow(int rowInput) {
	prevRow = rowInput;
}

// returns the Ant's previous row
int Ant::getPrevRow() {
	return prevRow;
}

// sets the Ant's previous column
void Ant::setPrevColumn(int colInput) {
	prevCol = colInput;
}

// returns the Ant's previous column
int Ant::getPrevColumn() {
	return prevCol;
}

// sets the Ant's current row
void Ant::setCurrentRow(int currRow) {
	currentRow = currRow;
}

// returns the Ant's current row
int Ant::getCurrentRow() {
	return currentRow;
}

// sets the Ant's current column
void Ant::setCurrentColumn(int currCol) {
	currentColumn = currCol;
}

// returns the Ant's current column
int Ant::getCurrentColumn() {
	return currentColumn;
}


