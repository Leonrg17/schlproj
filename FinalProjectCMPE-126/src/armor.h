/*
 * armor.h
 *
 *  Created on: May 2, 2020
 *      Author: natev
 */

#ifndef ARMOR_H_
#define ARMOR_H_

#include "weakness.h"
#include <string>
#include <iostream>
using namespace std;

class armor{
private:
	string name;
	int armorclass;
	weakness weak;
	int price;

public:
	armor(); //default constructor
	string getname(); //returns name of armor
	int getAC(); //returns armor class of armor
	weakness getweak(); //returns weakness of armor
	int getprice(); //returns price
	void none(); //makes a set of no armor
	void hide(); //makes hide armor
	void chainmail(); //makes chain mail
	void scalemail(); //makes scale mail
	void halfplate(); //makes half plate
	void plate(); //makes plate mail

	friend ostream& operator<<(ostream& ost, armor a);



};



#endif /* ARMOR_H_ */
