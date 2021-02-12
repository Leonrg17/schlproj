/*
 * DNDLL.h
 *
 *  Created on: Apr 22, 2020
 *      Author: leon_
 */

#ifndef DNDLL_H_
#define DNDLL_H_
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DND.h"
using namespace std;

class DLL: public dnode{
	dnode* head;
	dnode* tail;

public:

	DLL();


	void insertbeg(character n);

	void printplayersstats();
	void printplayers();

	//play functions
	void gametime();
	bool play();
	void turn();

	//use/attack func
	void usepots(dnode* temp);
	void hit(dnode* temp);

	//status checks
	bool onlyup();
	bool allaun();
	bool alleun();
	bool allalliesdead();
	bool allenemiesdead();


};



#endif /* DNDLL_H_ */
