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
		int maxRooms;
		float maxTreasure;
		double maxTreas;

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
						//this is maximum number of rooms

						aL = strtol(argv[i], &eptr, 10);
						maxRooms = (int) aL;
						printf("Number of rooms is %d\n",maxRooms);fflush(stdout);
						break;
					case 3:
						//this is maximum amount of treasure

						maxTreas = atof(argv[i]);
						printf("Amount of  treasure is %f\n",maxTreas);fflush(stdout);
						maxTreasure = (float) maxTreas;
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
		//TODO read the board from the file,
		//discover checkers
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

