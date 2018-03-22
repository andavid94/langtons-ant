/*
 ** Author: David An
 ** Date: Jan 15 2018
 ** Description: Ant.hpp is the Ant class declaration file
 */

#ifndef Ant_hpp
#define Ant_hpp

enum Direction { up, right, down, left };

class Ant {

private:
	Direction direction;
	char squareState;
	int prevRow;
	int prevCol;
	int currentRow;
	int currentColumn;

public:
	Ant();
	Ant(int row, int column);
	void setDirection(Direction direction);
	Direction getDirection();
	void setSquareState(char state);
	char getSquareState();
	void setPrevRow(int prevRow);
	int getPrevRow();
	void setPrevColumn(int prevColumn);
	int getPrevColumn();
	void setCurrentRow(int currentRow);
	int getCurrentRow();
	void setCurrentColumn(int currentColumn);
	int getCurrentColumn();
	
};

#endif 
