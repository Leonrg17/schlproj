/*
 * DND.h
 *
 *  Created on: Apr 22, 2020
 *      Author: leon_
 */

#ifndef DND_H_
#define DND_H_
#include <iostream>
#include "character.h"
using namespace std;


class dnode {

public:
	dnode();

	character human;
	dnode *next;
	int players;

};




#endif /* DND_H_ */
