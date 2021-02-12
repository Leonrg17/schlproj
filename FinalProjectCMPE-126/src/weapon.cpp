/*
 * weapon.cpp
 *
 *  Created on: May 2, 2020
 *      Author: natev
 */

#include "weapon.h"

weapon::weapon()
{
	name = "none";
	dicesides = 0;
	numdice = 0;
	durability = 0;
	maxdurability = 0;
	element = weakness();
	price = 0;
	type = 0;
}

int weapon::getsides()
{
	return dicesides;
}

int weapon::getnum()
{
	return numdice;
}

int weapon::getmaxdurability()
{
	return maxdurability;
}

int weapon::getdurability()
{
	return durability;
}

weakness weapon::getweak()
{
	return element;
}

int weapon::gettype()
{
	return type;
}

int weapon::getprice()
{
	return price;
}
void weapon::decrdurability()
{
	durability--;
}

void weapon::clearweap()
{
	name = "none";
	dicesides = 0;
	numdice = 0;
	durability = 0;
	maxdurability = 0;
	element.clearweak();
	price = 0;
	type = 0;
}

void weapon::fist()
{
	name = "Fist";
	dicesides = 1;
	numdice = 2;
	durability = 100000;
	maxdurability = 100000;
	element.clearweak();
	element.setblunt(-1);
	price = 0;
	type = 0;
}

void weapon::dagger()
{
	name = "Dagger";
	dicesides = 4;
	numdice = 1;
	durability = 40;
	maxdurability = 40;
	element.clearweak();
	element.setslash(-1);
	price = 4;
	type = 0;
}

void weapon::doubledagger()
{
	name = "Double Daggers";
	dicesides = 4;
	numdice = 2;
	durability = 80;
	maxdurability = 80;
	element.clearweak();
	element.setslash(-1);
	price = 8;
	type = 0;
}

void weapon::mace()
{
	name = "Mace";
	dicesides = 6;
	numdice = 1;
	durability = 60;
	maxdurability = 60;
	element.clearweak();
	element.setslash(-1);
	price = 6;
	type = 0;
}

void weapon::spear()
{
	name = "Spear";
	dicesides =  6;
	numdice = 1;
	durability = 50;
	maxdurability = 50;
	element.clearweak();
	element.setpierce(-1);
	price = 8;
	type = 0;
}

void weapon::crossbow()
{
	name = "Crossbow";
	dicesides = 8;
	numdice = 2;
	durability = 25;
	maxdurability = 25;
	element.clearweak();
	element.setpierce(-1);
	price = 10;
	type = 0;
}

void weapon::flail()
{
	name = "Flail";
	dicesides = 8;
	numdice = 1;
	durability = 40;
	maxdurability = 40;
	element.clearweak();
	element.setblunt(-1);
	price = 8;
	type = 0;
}

void weapon::greatsword()
{
	name = "Greatsword";
	dicesides = 6;
	numdice = 2;
	durability = 40;
	maxdurability = 40;
	element.clearweak();
	element.setslash(-1);
	price = 12;
	type = 0;
}

void weapon::longsword()
{
	name = "Longsword";
	dicesides = 6;
	numdice = 2;
	durability = 40;
	maxdurability = 40;
	element.clearweak();
	element.setslash(-1);
	price = 8;
	type = 0;
}

void weapon::rapier()
{
	name = "Rapier";
	dicesides = 8;
	numdice = 1;
	durability = 35;
	maxdurability = 35;
	element.clearweak();
	element.setpierce(-1);
	price = 8;
	type = 0;
}

void weapon::devsword()
{
	name = "Devsword";
	dicesides = 20;
	numdice = 20;
	durability = 100000;
	maxdurability = 100000;
	element.clearweak();
	element.allweak();
	price = 1;
	type = 0;
}

void weapon::fire()
{
	name = "Fire";
	dicesides = 8;
	numdice = 2;
	durability = 5;
	maxdurability = 5;
	element.clearweak();
	element.setfire(-1);
	price = 5;
	type = 1;
}

void weapon::ice()
{
	name = "Ice";
	dicesides = 8;
	numdice = 2;
	durability = 5;
	maxdurability =5;
	element.clearweak();
	element.setice(-1);
	price = 5;
	type = 1;
}

void weapon::lightning()
{
	name = "Lightning";
	dicesides = 6;
	numdice = 3;
	durability = 5;
	maxdurability = 5;
	element.clearweak();
	element.setlightning(-1);
	price = 8;
	type = 1;
}

void weapon::wind()
{
	name = "Wind";
	dicesides = 8;
	numdice = 2;
	durability = 5;
	maxdurability = 5;
	element.clearweak();
	element.setwind(-1);
	price = 5;
	type = 1;
}


void weapon::printsimple()
{
	cout<<"weapon name: "<<name<<" ";
	if (type == 0)
	{
		cout<<"Physical ";
	}
	if (type == 1)
	{
		cout<<"Magic ";
	}
	cout<<"Damage: "<<numdice<<"d"<<dicesides<<endl;
}
ostream& operator<<(ostream& ost, weapon w)
{
	cout<<"******************************************"<<endl;
	cout<<"weapon name: "<<w.name<<endl;
	cout<<"damage: "<<w.numdice<<"d"<<w.dicesides<<endl;
	cout<<"durability: "<<w.durability<<"/"<<w.maxdurability<<endl;
	cout<<w.element;
	return ost;
}


void weapon::setweaponhealth(int k){
	durability = k;
}
void weapon::notover(){
	durability = maxdurability;
}

void weapon::printshop()
{
    cout<<"weapon name: "<<name<<endl;
    if (type == 0)
    {
        cout<<"\tPhysical ";
    }
    if (type == 1)
    {
        cout<<"\tMagic ";
    }
    cout<<"Damage: "<<numdice<<"d"<<dicesides<<endl<<"\tPrice: "<<price<<endl;
}
