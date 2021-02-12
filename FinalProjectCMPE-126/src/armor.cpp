/*
 * armor.cpp
 *
 *  Created on: May 2, 2020
 *      Author: natev
 */

#include "armor.h"

armor::armor()
{
	name = "none";
	armorclass = 0;
	weak.clearweak();
	price = 0;
}

int armor::getAC()
{
	return armorclass;
}
weakness armor::getweak()
{
	return weak;
}
string armor::getname()
{
	return name;
}
int armor::getprice()
{
	return price;
}

void armor::none()
{
	name = "none";
	armorclass = 0;
	weak.clearweak();
	price = 0;
}

void armor::hide()
{
	name = "Hide";
	armorclass = 12;
	weak.clearweak();
	weak.setslash(-1);
	weak.setblunt(1);
	weak.setfire(-1);
	weak.setice(1);
	price = 5;
}

void armor::chainmail()
{
	name = "Chain Mail";
	armorclass = 16;
	weak.clearweak();
	weak.setpierce(-1);
	weak.setslash(1);
	weak.setlightning(-1);
	price = 13;
}

void armor::scalemail()
{
	name = "Scale Mail";
	armorclass = 14;
	weak.clearweak();
	weak.setpierce(-1);
	weak.setslash(1);
	weak.setfire(1);
	weak.setwind(1);
	weak.setice(1);
	weak.setlightning(1);
	price = 15;
}
void armor::halfplate()
{
	name = "Half Plate";
	armorclass = 15;
	weak.clearweak();
	weak.setpierce(1);
	weak.setslash(1);
	weak.setfire(-1);
	weak.setlightning(1);
	price = 15;
}

void armor::plate()
{
	name = "Plate";
	armorclass = 18;
	weak.clearweak();
	weak.setpierce(1);
	weak.setslash(1);
	weak.setblunt(-1);
	weak.setfire(1);
	weak.setlightning(-1);
	weak.setice(1);
	weak.setwind(1);
	price = 18;
}

ostream& operator<<(ostream& ost, armor a)
{
	cout<<"******************************************"<<endl;
	cout<<"armor name: "<<a.name<<endl;
	cout<<"armor class: "<<a.armorclass<<endl;
	cout<<a.weak;
	return ost;
}
