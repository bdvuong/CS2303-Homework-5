//
// Created by vuong on 9/30/2021.
//

#include "Piece.h"

Piece::Piece(int pieceType, int team, int xPos, int yPos) {
    // 1 for Pawn, 2 for King, 0 for captured
    this->type = pieceType;
    // 1 for Black, 2 for Red, 0 for captured
    this->team = team;
    this->xPos = xPos;
    this->yPos = yPos;
}

Piece::~Piece();
