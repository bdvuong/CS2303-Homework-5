/*
 * Board.h
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <stdio.h>
#include "Piece.h"

typedef struct {
    int initX;
    int initY;
    int toX;
    int toY;
} move2;

typedef struct {
    move2* moves;
    int size;
} moveSet;

class Board {
public:
	Board();
	virtual ~Board();
	void displayBoard();
	void printToFile(char* filename);
    moveSet getPossibleMoves();
    bool isValidMove(move2 move, Piece *piece);
    void movePiece(move2 move);
    move2 pickRandomMove(int teamTurn);
    void promoteKings();

    Piece* checkerBoard[8][8];
};

#endif /* BOARD_H_ */
