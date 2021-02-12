/*
 * item.h
 *
 *  Created on: May 1, 2020
 *      Author: leon_
 */

#ifndef ITEM_H_
#define ITEM_H_
#include<iostream>
using namespace std;


class item{

	//healing
	int shp;
	int mhp;
	int lhp;

	//repair
	int repairkit;
	int betterrepairkit;

	//attack
	int fragilehammer;
	int throwingdaggers;
	int magictalisman;

public:

	item(); //default constructor

	int setpotions(int count); // sets number of potions and returns points consumed

	int setrepairkits(int count);// sets number of repait kits and returns points consumed

	int setattackitem(int count); // sets number of attack items and returns points consumed


	int getshp();
	int getmhp();
	int getlhp();
	int getrepair();
	int getbetrep();
	int gethammer();
	int gettd();
	int getmagital();


	void useshp();
	void usemhp();
	void uselhp();
	void userepair();
	void usebetrep();
	void usehammer();
	void usetd();
	void usemagital();

};


#endif /* ITEM_H_ */
