/*
 * Production.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Production.h"


Production::Production() {
	// TODO Auto-generated constructor stub

}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

bool Production::prod(int argc, char* argv[])
{
	printf("Starting Production\n");
	bool answer = false;

	if(argc <=1) //no interesting information
	{
		puts("Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d interesting arguments.\n", argc-1);
		fflush(stdout);
		char filename[FILENAMELENGTHALLOWANCE];
		char* eptr=(char*) malloc(sizeof(char*));
		long aL=-1L;
		int maxMoves;
		float maxTreasure;
		char* startingPlayer;

		for(int i = 1; i<argc; i++) //don't want to read argv[0]
				{//argv[i] is a string

					switch(i)
					{
					case 1:
						//this is filename
						printf("The length of the filename is %d.\n",(int)strlen(argv[i]));
						printf("The proposed filename is %s.\n", argv[i]);
						if(strlen(argv[i])>=FILENAMELENGTHALLOWANCE)
						{
							puts("Filename is too long.");
							fflush(stdout);
							answer = false;
						}
						else
						{
							strcpy(filename, argv[i]);
							printf("Filename was %s.\n", filename);
							fflush(stdout);
						}
						break;
					case 2:
						//this is maximum number of moves

						aL = strtol(argv[i], &eptr, 10);
						maxMoves = (int) aL;
						printf("Number of moves is %d\n",maxMoves);fflush(stdout);
						break;
					case 3:
						//this is which player starts first

						startingPlayer = argv[i];
						printf("Starting player is %s\n",startingPlayer);fflush(stdout);
						break;

					default:
						puts("Unexpected argument count."); fflush(stdout);
						answer = false;
						break;
					}//end of switch
				}//end of for loop on argument count
				puts("after reading arguments"); fflush(stdout);

		//we'll want to read the file
	    Board* theBoard = new Board();

		puts("Before read file"); fflush(stdout);
		answer = readFile(filename, theBoard); //read the file
		puts("Back from read file"); fflush(stdout);
        int playerNumber = -1;
        if(!strcmp(startingPlayer, "red")) {
            playerNumber = 2;
        }
        else {
            playerNumber = 1;
        }

        for (int i = 0; i < maxMoves; ++i) {
            move2 randomMove = theBoard->pickRandomMove(playerNumber);
            theBoard->movePiece(randomMove);
            //promote kings
            theBoard->promoteKings();
            //change turns
            if(playerNumber == 1) {
                playerNumber = 2;
            }
            else if(playerNumber == 2) {
                playerNumber = 1;
            }
            theBoard->displayBoard();
            //theBoard->printToFile("output.txt");
        }

	}
	return answer;
}

bool Production::readFile(char* filename, Board* theBoard)
{
	bool ok = true;
	char temp = '-';
	FILE* fp = fopen(filename, "r"); //read the file

	if (fp == NULL)
	{
		puts("Error! opening file");

	}
	else
	{
        puts("Scanning file to find pieces");
		//discover checkers and initialize board
        for (int col = 0; col < BOARDCOLS; ++col) {
            for (int row = 0; row < BOARDROWS; ++row) {
                fscanf(fp, " %c", &temp);
                switch(temp) {
                    //empty space
                    case '-':
                        theBoard->checkerBoard[col][row] = new Piece(0,0,row,col);
                        break;
                    //black pieces
                    //black pawn
                    case 'b':
                        theBoard->checkerBoard[col][row] = new Piece(1,1,row,col);
                        break;
                    //black king
                    case 'B':
                        theBoard->checkerBoard[col][row] = new Piece(2,1,row,col);
                        break;
                    //red piece
                    //red pawn
                    case 'r':
                        theBoard->checkerBoard[col][row] = new Piece(1,2,row,col);
                        break;
                    //red king
                    case 'R':
                        theBoard->checkerBoard[col][row] = new Piece(2,2,row,col);
                        break;
                }
            }
        }
        theBoard->displayBoard();
		//make instances of class checker as needed
		//board needs to keep track of instances of checkers
		//checkers might also know where they are...
		fscanf(fp,"%c", &temp); //red checker, black, none?
        //notice, this reads only one character, and <CR> is a character

	}
	fclose(fp);

	return ok;
}

bool Production::getYesNo(char* query)
{
   bool answer = true; //so far
   char said = 'x';
   do
   {
	 printf("%s (y/n):",query);
     fflush(stdout);
     fflush(stdin);
     scanf("%c",&said);
   }while((said!= 'y')&&(said!='n'));
   if(said=='n')
   {
	   answer=false;
   }


   return answer;
}

