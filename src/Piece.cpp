//
// Created by vuong on 9/30/2021.
//

#include "Piece.h"

//constructor
Piece::Piece(int pieceType, int team, int xPos, int yPos) {
    // 1 for Pawn, 2 for King, 0 for captured
    this->pieceType = pieceType;
    // 1 for Black, 2 for Red, 0 for captured
    this->pieceTeam = team;
    //where the piece is on the board horizontally
    this->xPos = xPos;
    //where the piece is on the board vertically
    this->yPos = yPos;
}

//destructor
Piece::~Piece() {
    delete[] this;
}

//getters
int Piece::getType(){
    return pieceType;
}
int Piece::getTeam(){
    return pieceTeam;
}
int Piece::getXPos(){
    return xPos;
}
int Piece::getYPos(){
    return yPos;
}

//setters
void Piece::setType(int type){
    pieceType = type;
}
void Piece::setTeam(int team){
    pieceTeam = team;
}
void Piece::setXPos(int x){
    xPos = x;
}
void Piece::setYPos(int y){
    yPos = y;
}