//
// Created by vuong on 9/30/2021.
//

#ifndef REFERENCECHECKERS_PIECE_H
#define REFERENCECHECKERS_PIECE_H


class Piece {
public:
    //constructor
    Piece(int pieceType, int team, int xPos, int yPos);
    //destructor
    Piece::~Piece();

private:
    int type;
    int team;
    int xPos;
    int yPos;
};


#endif //REFERENCECHECKERS_PIECE_H
