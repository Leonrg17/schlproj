/*
 * weapon.h
 *
 *  Created on: May 2, 2020
 *      Author: natev
 */

#ifndef WEAPON_H_
#define WEAPON_H_
#include "weakness.h"
#include <iostream>
#include <string>
using namespace std;

class weapon{
private:
	string name;
	int dicesides;
	int numdice;
	int durability;
	int maxdurability;
	weakness element;
	int price;
	int type;

public:
	weapon(); //default
	int getsides(); //returns sides of dice
	int getnum(); //returns number of dice
	int getmaxdurability(); //returns max durability
	int getdurability(); //returns current durability
	void decrdurability(); //decreases durability
	void adddurability(int i); //adds durability
	weakness getweak(); //returns weakness
	int getprice(); //returns price
	int gettype(); //returns type 0 = physical, 1 = magic;

void setweaponhealth(int k);// allows repair kit to be used
	void notover(); // sets weapon durability to max

	void clearweap(); //resets to default
	void fist(); //makes fist
	void dagger(); //makes single dagger
	void doubledagger(); //makes double daggers
	void mace(); //makes mace
	void spear(); //makes spear
	void crossbow(); //makes crossbow
	void flail(); //makes a flail
	void greatsword(); //makes a greatsword
	void longsword(); //makes a longsword
	void rapier(); //makes rapier
	void devsword(); //makes broken weapon not supposed to use this
	void fire(); //makes a fire spell
	void lightning(); //makes a lightning spell
	void ice(); //makes a ice spell
	void wind(); //makes a wind spell
	void printshop();

	void printsimple();
	friend ostream& operator<<(ostream& ost, weapon w);

};


#endif /* WEAPON_H_ */
