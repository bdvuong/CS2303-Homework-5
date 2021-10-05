/*
 * Board.cpp
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#include <iostream>
#include <fstream>
#include <ctime>
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
    std::ofstream output;
    output.open(filename);
    int tempTeam = -1;
    int tempType = -1;
    for (int col = 0; col < BOARDCOLS; ++col) {
        for (int row = 0; row < BOARDROWS; ++row) {
            tempTeam = checkerBoard[col][row]->getTeam();
            tempType = checkerBoard[col][row]->getType();
            if(tempTeam == 0) {
                output << "-";
            }
            else if(tempTeam == 1 && tempType == 1) {
                output << "b";
            }
            else if(tempTeam == 1 && tempType == 2) {
                output << "B";
            }
            else if(tempTeam == 2 && tempType == 1) {
                output << "r";
            }
            else if(tempTeam == 2 && tempType == 2) {
                output << "R";
            }
        }
        output << "\n";
    }
}

moveSet Board::getPossibleMoves() {
    move2* possibleMoves = 0;
    possibleMoves = new move2[BOARDROWS];

    int numMoves = 0;

    //check for all moves on a team
    for (int i = 0; i < BOARDCOLS; ++i) {
        for (int j = 0; j < BOARDROWS; ++j) {
            if(checkerBoard[i][j]->getTeam() == 1) {
                move2 leftMove = {checkerBoard[i][j]->getXPos(),checkerBoard[i][j]->getYPos(),checkerBoard[i][j]->getXPos() - 1, checkerBoard[i][j]->getYPos() - 1};
                move2 rightMove = {checkerBoard[i][j]->getXPos(),checkerBoard[i][j]->getYPos(),checkerBoard[i][j]->getXPos() + 1, checkerBoard[i][j]->getYPos() + 1};
                if(isValidMove(leftMove, checkerBoard[i][j])){
                    possibleMoves[numMoves] = leftMove;
                    numMoves++;
                }
                if(isValidMove(rightMove, checkerBoard[i][j])) {
                    possibleMoves[numMoves] = rightMove;
                    numMoves++;
                }
            }
            else if(checkerBoard[i][j]->getTeam() == 1){
                move2 leftMove = {checkerBoard[i][j]->getXPos(),checkerBoard[i][j]->getYPos(),checkerBoard[i][j]->getXPos() - 1, checkerBoard[i][j]->getYPos() - 1};
                move2 rightMove = {checkerBoard[i][j]->getXPos(),checkerBoard[i][j]->getYPos(),checkerBoard[i][j]->getXPos() + 1, checkerBoard[i][j]->getYPos() + 1};
                if(isValidMove(leftMove, checkerBoard[i][j])){
                    possibleMoves[numMoves] = leftMove;
                    numMoves++;
                }
                if(isValidMove(rightMove, checkerBoard[i][j])) {
                    possibleMoves[numMoves] = rightMove;
                    numMoves++;
                }
            }

        }
    }
    moveSet moveSet = {possibleMoves, numMoves};
    return moveSet;
}

bool Board::isValidMove(move2 move, Piece* piece) {
    bool isValidMove = false;

    //if piece is a pawn
    if(piece->getType() == 1) {

        //check if this move is diagonal
        if((move.initX == move.toX - 1 || move.initX == move.toX + 1) && (move.toY == move.initY - 1 || move.toY == move.initY + 1)){

            //check for which direction the piece is moving in and if it is the correct direction
            if((piece->getTeam() == 1 && move.toY - move.initY == -1) || (piece->getTeam() == 2 && move.toY - move.initY == 1)) {
                //make sure the piece's move is within the board
                if(move.toX >= 0 && move.toX < BOARDCOLS && move.toY >= 0 && move.toY < BOARDCOLS) {
                    //check for piece

                    //there is no piece here
                    if(checkerBoard[move.toX][move.toY]->getTeam() == 0) {
                        isValidMove = true;
                    }
                    //there is a piece there, check to see if it is on the opposite team
                    else {
                        // if piece is a black piece, check the piece to the diagonal to see if it is a red piece
                        if(piece->getTeam() == 1) {
                            if(checkerBoard[move.toX][move.toY]->getTeam() == 2) {

                                //check to see if the piece can jump
                                int direction = move.toX - move.initX;

                                //if pawn is moving left
                                if(direction == - 1) {

                                    //make sure diagonal is within board constraints
                                    if(move.toX - 1 >= 0 && move.toX - 1 < BOARDCOLS && move.toY - 1 < BOARDROWS && move.toY - 1 >= 0) {

                                        //check if spot is free
                                        if(checkerBoard[move.toX - 1][move.toY - 1]->getTeam() == 0) {
                                            isValidMove = true;
                                        }
                                    }
                                }
                                // else the pawn is moving right
                                else if(direction == 1) {
                                    //make sure diagonal is within board constraints
                                    if(move.toX + 1 >= 0 && move.toX + 1 < BOARDCOLS && move.toY - 1 < BOARDROWS && move.toY - 1 >= 0) {

                                        //check if spot is free
                                        if(checkerBoard[move.toX + 1][move.toY - 1]->getTeam() == 0) {
                                            isValidMove = true;
                                        }
                                    }
                                }
                            }
                        }
                        //else we have a red piece, check for black piece
                        else if(piece->getTeam() == 2) {

                            if(checkerBoard[move.toX][move.toY]->getTeam() == 1) {

                                //check to see if the piece can jump
                                int direction = move.toX - move.initX;

                                //if pawn is moving left
                                if(direction == - 1) {

                                    //make sure diagonal is within board constraints
                                    if(move.toX - 1 >= 0 && move.toX - 1 < BOARDCOLS && move.toY + 1 < BOARDROWS && move.toY + 1 >= 0) {

                                        //check if spot is free
                                        if(checkerBoard[move.toX - 1][move.toY + 1]->getTeam() == 0) {
                                            isValidMove = true;
                                        }
                                    }
                                }
                                    // else the pawn is moving right
                                else if(direction == 1) {
                                    //make sure diagonal is within board constraints
                                    if(move.toX + 1 >= 0 && move.toX + 1 < BOARDCOLS && move.toY + 1 < BOARDROWS && move.toY + 1 >= 0) {

                                        //check if spot is free
                                        if(checkerBoard[move.toX + 1][move.toY + 1]->getTeam() == 0) {
                                            isValidMove = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    //else we have a king
    else if(piece->getType() == 2) {
        //check if this move is diagonal
        if ((move.initX == move.toX - 1 || move.initX == move.toX + 1) &&
            (move.toY == move.initY - 1 || move.toY == move.initY + 1)) {

                //make sure the piece's move is within the board
                if (move.toX >= 0 && move.toX < BOARDCOLS && move.toY >= 0 && move.toY < BOARDCOLS) {

                    //check for piece
                    //there is no piece here
                    if (checkerBoard[move.toX][move.toY]->getTeam() == 0) {
                        isValidMove = true;
                    }
                        //there is a piece there, check to see if it is on the opposite team
                    else {
                        // if piece is a black piece, check the piece to the diagonal to see if it is a red piece
                        if (piece->getTeam() == 1) {
                            if (checkerBoard[move.toX][move.toY]->getTeam() == 2) {

                                //check to see if the piece can jump
                                int direction = move.toX - move.initX;

                                //if king is moving left
                                if (direction == -1) {

                                    //make sure diagonal is within board constraints
                                    if (move.toX - 1 >= 0 && move.toX - 1 < BOARDCOLS && move.toY - 1 < BOARDROWS &&
                                        move.toY - 1 >= 0) {

                                        //check if spot is free
                                        if (checkerBoard[move.toX - 1][move.toY - 1]->getTeam() == 0) {
                                            isValidMove = true;
                                        }
                                    }
                                }
                                    // else the king is moving right
                                else if (direction == 1) {
                                    //make sure diagonal is within board constraints
                                    if (move.toX + 1 >= 0 && move.toX + 1 < BOARDCOLS && move.toY - 1 < BOARDROWS &&
                                        move.toY - 1 >= 0) {

                                        //check if spot is free
                                        if (checkerBoard[move.toX + 1][move.toY - 1]->getTeam() == 0) {
                                            isValidMove = true;
                                        }
                                    }
                                }
                            }
                        }
                            //else we have a red piece, check for black piece
                        else if (piece->getTeam() == 2) {

                            if (checkerBoard[move.toX][move.toY]->getTeam() == 1) {

                                //check to see if the piece can jump
                                int direction = move.toX - move.initX;

                                //if king is moving left
                                if (direction == -1) {

                                    //make sure diagonal is within board constraints
                                    if (move.toX - 1 >= 0 && move.toX - 1 < BOARDCOLS && move.toY + 1 < BOARDROWS &&
                                        move.toY + 1 >= 0) {

                                        //check if spot is free
                                        if (checkerBoard[move.toX - 1][move.toY + 1]->getTeam() == 0) {
                                            isValidMove = true;
                                        }
                                    }
                                }
                                    // else the king is moving right
                                else if (direction == 1) {
                                    //make sure diagonal is within board constraints
                                    if (move.toX + 1 >= 0 && move.toX + 1 < BOARDCOLS && move.toY + 1 < BOARDROWS &&
                                        move.toY + 1 >= 0) {

                                        //check if spot is free
                                        if (checkerBoard[move.toX + 1][move.toY + 1]->getTeam() == 0) {
                                            isValidMove = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

        }
    }
    return isValidMove;
}

void Board::movePiece(move2 move) {
    Piece* initPiece = checkerBoard[move.initX][move.initY];
    Piece* afterMovePiece = checkerBoard[move.toX][move.toY];

    //move piece if spot is open
    if(afterMovePiece->getTeam() == 0) {
        //if piece is black, make new space black
        if(initPiece->getTeam() == 1) {
            checkerBoard[move.toX][move.toY]->setTeam(1);
        }
        //else it is a red piece, so do the same
        else if(initPiece->getTeam() == 2) {
            checkerBoard[move.toX][move.toY]->setTeam(2);
        }

        //make the moved piece the same type of piece
        checkerBoard[move.toX][move.toY]->setType(initPiece->getType());
        //reset the space where the piece was from initially
        checkerBoard[move.initX][move.initY]->setType(0);
        checkerBoard[move.initX][move.initY]->setTeam(0);
    }
    //otherwise, there is a jump
    else {
        int direction = move.toX - move.initX;

        //if black piece, move a black piece
        if(initPiece->getTeam() == 1) {
            checkerBoard[move.toX + direction][move.toY - 1]->setType((initPiece->getType()));
            checkerBoard[move.toX + direction][move.toY - 1]->setTeam(1);
        }
        //otherwise, we have a red piece, so move a red piece
        else if(initPiece->getTeam() == 2) {
            checkerBoard[move.toX + direction][move.toY +1]->setType((initPiece->getType()));
            checkerBoard[move.toX + direction][move.toY + 1]->setTeam(2);
        }
        //reset the original position of the piece and the piece that was jumped
        checkerBoard[move.initX][move.initY]->setTeam(0);
        checkerBoard[move.initX][move.initY]->setType(0);
        checkerBoard[move.toX][move.toY]->setTeam(0);
        checkerBoard[move.toX][move.toY]->setType(0);
    }
}

void Board::updateKings() {
    for (int i = 0; i < BOARDCOLS; ++i) {
        for (int j = 0; j < BOARDROWS; ++j) {
            Piece* piece = checkerBoard[i][j];
            if(piece->getTeam() == 1 && piece->getYPos() == BOARDROWS - 1) {
                checkerBoard[i][j]->setType(2);
            }
            else if(piece->getTeam() == 2 && piece->getYPos() == 0) {
                checkerBoard[i][j]->setType(2);
            }
        }
    }
}

move2 Board::pickRandomMove(int teamTurn) {
    bool ok = false;
    moveSet moveSet = getPossibleMoves();
    move2* moves = moveSet.moves;
    int numMoves = moveSet.size;
    int randomMoveNumber;

    srand(time(NULL));

    //pick a random move and make sure it is for the correct team
    while(!ok) {
        randomMoveNumber = (rand() % numMoves);
        move2 randomMove = moves[randomMoveNumber];
        if(checkerBoard[randomMove.initX][randomMove.initY]->getTeam() == teamTurn) {
            ok = true;
        }
    }
    return moves[randomMoveNumber];
}