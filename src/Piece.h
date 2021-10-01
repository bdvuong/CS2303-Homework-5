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
    virtual ~Piece();

    //getters
    int getType();
    int getTeam();
    int getXPos();
    int getYPos();
    //setters
    void setType(int pieceType);
    void setTeam(int team);
    void setXPos(int xPos);
    void setYPos(int yPos);

private:
    int pieceType;
    int team;
    int xPos;
    int yPos;
};


#endif //REFERENCECHECKERS_PIECE_H
