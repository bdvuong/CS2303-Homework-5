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
    int tempTeam = -1;
    int tempType = -1;
    for (int col = 0; col < BOARDCOLS; ++col) {
        for (int row = 0; row < BOARDROWS; ++row) {
            tempTeam = checkerBoard[col][row]->getTeam();
            tempType = checkerBoard[col][row]->getType();
            if(tempTeam == 0) {
                std::cout << "-";
            }
            else if(tempTeam == 1 && tempType == 1) {
                std::cout << "b";
            }
            else if(tempTeam == 1 && tempType == 2) {
                std::cout << "B";
            }
            else if(tempTeam == 2 && tempType == 1) {
                std::cout << "r";
            }
            else if(tempTeam == 2 && tempType == 2) {
                std::cout << "R";
            }
        }
        std::cout << "\n";
    }
}
void Board::printToFile(char* filename)
{
    //TODO
}
