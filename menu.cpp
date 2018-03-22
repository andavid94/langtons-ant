/*
 ** Author: David An
 ** Date: Jan 15 2018
 ** Description: This program contains both of the menu functions for starting
 ** 			 the simulation, and prompting the user for further action once
 ** 			 the simulation has ended.
 */

#include "menu.hpp"
#include "inputValidation.hpp"
#include <iostream>
#include <string>

int beginGame() {
	
	// begin menu function (prompt user for input)
	std::cout << "Enter 1 to begin Langton's Ant simulation\n";
	std::cout << "Enter 2 to Quit\n";
	std::cout << "Decimal inputs will be rounded down to the nearest integer\n";
	
	// validate user input according to rule: must be 1 or 2
	int beginOrQuit = inputValidation(1, 2);
	
	return beginOrQuit;
}

int reprompt() {
	
	std::cout << "Enter 1 to play again\n";
	std::cout << "Enter 2 to Quit\n";
	
	int playOrQuit = inputValidation(1, 2);
	
	return playOrQuit;
}

