/*
 * Tests.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_
#include "Production.h"
#include <stdio.h>


class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();

private:
	bool testReadFile();
	bool testEnqueue();
	bool testMakeLList();
	//pedagogical bool testRemoveFromList();
	bool testPrintHistory();
	bool testFileOutput();
    bool testPrintToFile();

    Board* theBoard = new Board;
    Production* pP = new Production();
};

#endif /* TESTS_H_ */
