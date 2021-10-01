//
// Created by vuong on 9/30/2021.
//

#include "Piece.h"

//constructor
Piece::Piece(int pieceType, int team, int xPos, int yPos) {
    // 1 for Pawn, 2 for King, 0 for captured
    this->pieceType = pieceType;
    // 1 for Black, 2 for Red, 0 for captured
    this->team = team;
    //where the piece is on the board horizontally
    this->xPos = xPos;
    //where the piece is on the board vertically
    this->yPos = yPos;
}

//destructor
Piece::~Piece() {

}

//getters
int Piece::getType(){
    return pieceType;
}
int Piece::getTeam(){
    return team;
}
int Piece::getXPos(){
    return xPos;
}
int Piece::getYPos(){
    return yPos;
}

//setters
void Piece::setType(int pieceType){
    pieceType = pieceType;
}
void Piece::setTeam(int team){
    team = team;
}
void Piece::setXPos(int xPos){
    xPos = xPos;
}
void Piece::setYPos(int yPos){
    yPos = yPos;
}