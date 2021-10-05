/*
 * Board.cpp
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#include <iostream>
#include "Board.h"
#include "Production.h"

Board::Board() {
	// TODO Auto-generated constructor stub

}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

void Board::displayBoard()
{
    for (int col = 0; col < BOARDCOLS; ++col) {
        for (int row = 0; row < BOARDROWS; ++row) {
            std::cout << checkerBoard[col][row]->getTeam();
        }
        std::cout << "\n";

    }
}
void Board::printToFile(char* filename)
{
    //TODO
}
