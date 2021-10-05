/*
 * Tests.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Tests.h"
#include <stdbool.h>

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests()
{
	bool answer = true;

	bool ok1 = testReadFile();
	bool ok2 = testFileOutput();
	bool ok3 = testMakeLList();
	bool ok4 = testEnqueue();
	//pedagogical bool ok5 = testRemoveFromList();
	bool ok6 = testPrintHistory();
    bool ok7 = testPrintToFile();
	answer = ok1 && ok3 && ok4  && ok6 && ok7;
	return answer;
}

bool Tests::testReadFile()
{
	puts("starting testReadFile"); fflush(stdout);
	bool ok = true;
	//the file tells how many rooms there are
	int answer = -1;
	int rightAnswer = 8;

	ok = pP->readFile("gameState.txt", theBoard); //read the file

	theBoard->displayBoard();
	ok = pP->getYesNo("Does the board look right?");
	if(ok)
	{
		puts("testReadfile did pass");
	}
	else
	{
		puts("testReadfile did not pass.");
	}

	return ok;
}
bool Tests::testEnqueue()
{
	bool ok = true;
	if(ok)
	{
		puts("testEnqueue did pass");
	}
	else
	{
		puts("testEnqueue did not pass.");
	}
	return ok;
}
bool Tests::testMakeLList()
{
	bool ok = true;
	if(ok)
	{
		puts("testMakeLList did pass");
	}
	else
	{
		puts("testMakeLList did not pass.");
	}
	return ok;
}
bool Tests::testPrintHistory()
{
	bool ok = true;
	if(ok)
	{
		puts("testPrintHistory did pass");
	}
	else
	{
		puts("testPrintHistory did not pass.");
	}
	return ok;
}
bool Tests::testFileOutput()
{
	bool ok = true;

	FILE* fd = fopen("boardPlay.txt", "w");
	fprintf(fd, "Here goes nothing\n"); fflush(fd);


    fclose(fd);
	if(ok)
	{
		puts("testFileOutput did pass");
	}
	else
	{
		puts("testFileOutput did not pass.");
	}
	return ok;
}

bool Tests::testPrintToFile() {
    bool ok = true;

    char* outputFile = "testOutput.txt";
    this->theBoard->printToFile(outputFile);

    if(pP->getYesNo("Check the file testOutput.txt. Does the file match the board printed in the console previously?")) {
        puts("testPrintToFile passed!");
    }
    else {
        puts("testPrintToFile failed!");
    }

}