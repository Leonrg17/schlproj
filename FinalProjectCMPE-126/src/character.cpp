/*
 * character.cpp
 *
 *  Created on: Apr 29, 2020
 *      Author: natev
 */

#include "character.h"
#include "item.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

character::character()
{
	name = "-";
	health = 10;
	max_hp = 10;
	faction = 0;
	points = 25;
	condition = 1;
	deathsaves = 3;
	s.default_stats();
	AC = 0;
	w.clearweak();
	set.none();
	weapon zz;
	zz.fist();
	equipped[0] = zz;
	numequip = 1;
	magical = true;

}

void character::makefighter()
{
	health = 35;
	max_hp = 35;
	s.fighter();
	magical = false;
}

void character::makemage()
{
	health = 30;
	max_hp = 30;
	s.mage();
	magical = true;
}


void character::makerogue()
{
	health = 35;
	max_hp = 35;
	s.rogue();
	magical = true;
}

void character::makeknight()
{
	health = 40;
	max_hp = 40;
	s.knight();
	magical = true;
}

void character::makeDEV()
{
	health = 9999;
	max_hp = 9999;
	s.DEV();
	magical = true;
}

weakness character::getweak()
{
	return w;
}
void character::setName(string s)
{
	name = s;
}

void character::setcondition(int i)
{

	switch(i){
	case 1:condition = 1; break;
	case 0:condition = 0; break;
	case -1:condition = -1; break;

	default: condition = 0;break;
	}
}

void character::setfaction(int i)
{
	if(i == 0)
	{
		faction = i;
	}
	else if (i == 1)
	{
		faction = i;
	}
}

int character::getAC()
{
	return AC;
}

void character::equipArmor(armor a)
{
	set = a;
	calcAC();
	setweak();
}

void character::equipWeapon(weapon w){
	equipped[numequip] = w;
	numequip++;
}
void character::setweak()
{
	w = set.getweak();
}

void character::clear_equip()
{
	set.none();
	numequip = 1;
}

void character::calcAC()
{
	int total;
	total = set.getAC() + s.defmod;
	AC = total;
}
int character::roll(int numdice, int dicesides){
	srand(time(NULL));
	int result = 0;
	for(int i = 0; i<numdice; i++)
	{
		result = result + (rand() % dicesides + 1);
	}
	return result;
}

void character::attack(character& target)
{
	int choice;
	cout<<"Select weapon"<<endl;
	printw();
	cin>>choice;
	weapon used;
	used = equipped[choice -1];
	equipped[choice - 1].decrdurability();
	int damagedone;
	damagedone = calcDamage(used);
	weakness weap;
	weakness t;
	weap = used.getweak();
	t = target.getweak();
	int effectiveness;
	effectiveness = isweak(t, weap);
	//-2=exploit, -1 = even, 0 = resist
	if(effectiveness == -2)
	{
		cout<<"EXPLOIT! ";
		damagedone = damagedone * 2;
	}
	if(effectiveness == -1)
	{
		cout<<"EVEN! ";
	}
	if(effectiveness == 0)
	{
		cout<<"RESIST! ";
		damagedone = damagedone / 2;
	}

	int HIT;
	HIT = roll(1,20) + s.dexmod;
	int tarAC;
	tarAC=target.getAC();

	if(HIT>tarAC)
	{
		target.takedamage(damagedone);
		cout<<damagedone<<" damage done"<<endl;
	}

	else
	{
		cout<<"MISS"<<endl;
	}

}

void character::takedamage(int taken)
{
	health = health - taken;
}

int character::calcDamage(weapon w)
{
	int total = 0;
	int dicedmg;
	int dicenum;
	int ty;
	ty = w.gettype();
	dicedmg = w.getsides();
	dicenum = w.getnum();
	total = roll(dicenum, dicedmg);
	if(ty == 0)
	{
		total = total + s.strmod;
	}
	if(ty == 1)
	{
		total = total + s.magmod;
	}
	return total;
}

void character::use_repairkit(int option, weapon choice){

	if(option == 1){
		if(its.getrepair() == 0){
			cout<<"You do not have any repair kits"<<endl<<endl;
		}
		else{
			if(choice.getdurability() < choice.getmaxdurability()){
				choice.setweaponhealth(5);
				its.userepair();
			}
			else{
				choice.notover();
				its.userepair();
				cout<<"your weapon durability is at max"<<endl<<endl;
				cout<<"repair kit -1 "<<endl;
			}
		}
	}

	else if (option == 2){
		if(its.getbetrep() == 0){
			cout<<"You do not have any Repair kit+s"<<endl<<endl;
		}
		else{
			if(choice.getdurability() < choice.getmaxdurability()){
				choice.setweaponhealth(10);
				its.usebetrep();
			}
			else{
				choice.notover();
				its.usebetrep();
				cout<<"your weapon durability is at max"<<endl<<endl;
				cout<<"better repair kit -1 "<<endl;
			}
		}
	}


}

void character::buyitems(){
	int option;
	while(option != 6){

		cout<< "you have "<<points<< " points left"<<endl<<endl;
		cout<< "What would you like to purchase for your adventure? "<<endl<<endl;
		cout<< "1. Armor sets"<<endl<< "2. Weapons"<<endl<<"3. Potions"<<endl<<"4. Repair kits"<<endl<<"5. Consumables"<<endl<<"6. Nothing"<<endl;
		cin>>option;
		switch (option){
		case 1: buyarmor();
		if(points == 0) option = 6;
		break;

		case 2: buyweapons();
		if(points == 0) option = 6;
		break;

		case 3: points = its.setpotions(points);
		if(points == 0) option = 6;
		break;

		case 4: points = its.setrepairkits(points);
		if(points == 0) option = 6;
		break;

		case 5: points = its.setattackitem(points);
		if(points == 0) option = 6;
		break;

		case 6: break;

		default: cout<<"invalid option..."<<endl;
		break;
		}

	}

	cout<<"The adventure begins..."<<endl<<endl;

}

void character::use_hpitem(int option,character& temp){

	if(option == 1){
		if(its.getshp() == 0){
			cout<<"You do not have any small health potions"<<endl<<endl;
		}
		else{
			if(temp.health < max_hp){
				temp.health ++;
				its.useshp();
				cout<<"health has been restored"<<endl;
			}
			else{
				temp.health = max_hp;
				its.useshp();
				cout<<"your health is at max"<<endl<<endl;
			}
			cout<<"small health potion -1 "<<endl;
		}
	}

	if(option == 2){
		if(its.getmhp() == 0){
			cout<<"You do not have any medium health potions"<<endl<<endl;
		}
		else{
			if(temp.health+3<=max_hp){
				temp.health = health + 3;
				its.usemhp();
				cout<<"health has been restored"<<endl;
			}
			else{
				temp.health = max_hp;
				its.usemhp();
				cout<<"your health is at max"<<endl<<endl;
			}
			cout<<"medium health potion -1 "<<endl;
		}
	}

	if(option == 3){
		if(its.getlhp() == 0){
			cout<<"You do not have any large health potions"<<endl<<endl;
		}
		else{
			if(temp.health+5<=max_hp){
				temp.health = health + 5;
				its.uselhp();
				cout<<"health has been restored"<<endl;
			}
			else{
				temp.health = max_hp;
				its.uselhp();
				cout<<"your health is at max"<<endl<<endl;
			}
			cout<<"large health potion -1 "<<endl;
		}
	}

}


int character::getcondition(){
	return condition;
}
int character::getfaction(){
	return faction;
}


ostream& operator<<(ostream& ost, character ch)
{
	cout<<"******************************************"<<endl;
	cout<<"Character name: "<<ch.name<<endl;
	cout<<"Health: "<<ch.health<<"/"<<ch.max_hp<<endl;
	if(ch.faction == 0)
	{
		cout<<"Faction: Ally"<<endl;
	}
	if(ch.faction == 1)
	{
		cout<<"Faction: Enemy"<<endl;
	}
	if(ch.condition == 1)
	{
		cout<<"Condition: Alive"<<endl;
	}
	if(ch.condition == 0)
	{
		cout<<"Condition: Unconscious"<<endl;
	}
	if(ch.condition == -1)
	{
		cout<<"Condition: Dead"<<endl;
	}
	cout<<"Remaining Deathsaves: "<<ch.deathsaves<<endl;
	cout<<"Armor Class: "<<ch.AC<<endl;
	if(ch.magical)
	{
		cout<<"You can use magic"<<endl;
	}
	else
	{
		cout<<"You cannot use magic"<<endl;
	}
	cout<<ch.s;
	cout<<ch.w;


	return ost;
}

void character::printarmor()
{
	cout<<"ARMOR:"<<endl;
	cout<<set;
}
void character::printweapons(){
	cout<<"WEAPON LIST: "<<endl;
	cout<<"----------------------------------------"<<endl;
	for(int i=0;i<numequip;i++)
	{
		cout<<"Weapon "<<i+1<<endl;
		cout<<equipped[i];
	}

}

void character::printw()
{
	for(int i = 0; i<numequip; i++)
	{
		cout<<i+1<<". ";
		equipped[i].printsimple();
	}
}

void character::print_inv(){
	cout<<"You Currently have: "<<endl;
	cout<<"Small Health pot(s): "<<its.getshp()<<endl;
	cout<<"Medium Health pot(s): "<<its.getmhp()<<endl;
	cout<<"Large Health pot(s): "<<its.getlhp()<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"Repair kit(s): "<<its.getrepair()<<endl;
	cout<<"Repair kit+(s): "<<its.getbetrep()<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"Fragile Hammer(s): "<<its.gethammer()<<endl;
	cout<<"Throwing dagger kit(s): "<<its.gettd()<<endl;
	cout<<"Magical talisman: "<<its.getmagital()<<endl;
}

void character::deathtrial(){
    int x;
    x= roll(1,20);
    if (deathsaves  <= 0){
        condition = -1;
    }
    else
    {
    if(x>10){
        condition = 1;
        health = 5;
        deathsaves--;
    }
    else{
        condition = 0;
        deathsaves--;
    }
    }


}

int character::getpoints(){
	return points;
}


void character::usedagger(character& n){
	n.takedamage(4);
}
void character::usefrag(character& n){
	n.takedamage(2);
}

void character::usetalisman(character& target){
	weakness element;
	weakness tarweak;
	int damagedone = 5;
	tarweak = target.getweak();
	cout<<"choose talisman damage type"<<endl<<"1. Fire"<<endl<<"2. Wind"<<endl<<"3. Ice"<<endl<<"4. Lightning";
	int choice;
	cin>>choice;
	if(choice == 1)
	{
		element.setfire(-1);
		damagedone = combatdmg(tarweak, element, damagedone);
		target.takedamage(damagedone);
		cout<<damagedone<<" damage done"<<endl;

	}
	if(choice == 2)
	{
		element.setwind(-1);
		damagedone = combatdmg(tarweak, element, damagedone);
		target.takedamage(damagedone);
		cout<<damagedone<<" damage done"<<endl;
	}
	if(choice == 3)
	{
		element.setice(-1);
		damagedone = combatdmg(tarweak, element, damagedone);
		target.takedamage(damagedone);
		cout<<damagedone<<" damage done"<<endl;

	}
	if(choice == 4)
	{
		element.setlightning(-1);
		damagedone = combatdmg(tarweak, element, damagedone);
		target.takedamage(damagedone);
		cout<<damagedone<<" damage done"<<endl;

	}
}

string character::getname(){
	return name;
}

int character::getspd(){
	return s.getspd();
}

bool character::operator<(character n){
	if (n.s.getspd()  < s.getspd()){
		return true;
	}
	else
		return false;
}

void character::buyweapons()
{
	int choice = 0;
	while(choice != -1)
	{
		choice = 0;
		weapon temp;
		cout<<"Select weapon to buy: enter -1 to exit"<<endl;
		printspread();
		cin>>choice;
		switch(choice){
		case 1:
		{
			temp.dagger();
			equipWeapon(temp);
			points = points - temp.getprice();
			cout<<"points remaining: "<<points<<endl<<"Purchase again? (1. yes | -1. no)"<<endl;
			cin>>choice;
			break;
		}
		case 2:
		{
			temp.doubledagger();
			equipWeapon(temp);
			points = points - temp.getprice();
			cout<<"points remaining: "<<points<<endl<<"Purchase again? (1. yes | -1. no)"<<endl;
			cin>>choice;
			break;
		}
		case 3:
		{
			temp.mace();
			equipWeapon(temp);
			points = points - temp.getprice();
			cout<<"points remaining: "<<points<<endl<<"Purchase again? (1. yes | -1. no)"<<endl;
			cin>>choice;
			break;
		}

		case 4:
		{
			temp.spear();
			equipWeapon(temp);
			points = points - temp.getprice();
			cout<<"points remaining: "<<points<<endl<<"Purchase again? (1. yes | -1. no)"<<endl;
			cin>>choice;
			break;
		}

		case 5:
		{
			temp.crossbow();
			equipWeapon(temp);
			points = points - temp.getprice();
			cout<<"points remaining: "<<points<<endl<<"Purchase again? (1. yes | -1. no)"<<endl;
			cin>>choice;
			break;
		}
		case 6:
		{
			temp.flail();
			equipWeapon(temp);
			points = points - temp.getprice();
			cout<<"points remaining: "<<points<<endl<<"Purchase again? (1. yes | -1. no)"<<endl;
			cin>>choice;
			break;
		}
		case 7:
		{
			temp.greatsword();
			equipWeapon(temp);
			points = points - temp.getprice();
			cout<<"points remaining: "<<points<<endl<<"Purchase again? (1. yes | -1. no)"<<endl;
			cin>>choice;
			break;
		}
		case 8:
		{
			temp.longsword();
			equipWeapon(temp);
			points = points - temp.getprice();
			cout<<"points remaining: "<<points<<endl<<"Purchase again? (1. yes | -1. no)"<<endl;
			cin>>choice;
			break;
		}
		case 9:
		{
			temp.rapier();
			equipWeapon(temp);
			points = points - temp.getprice();
			cout<<"points remaining: "<<points<<endl<<"Purchase again? (1. yes | -1. no)"<<endl;
			cin>>choice;
			break;

		}
		case 10:
		{
			temp.fire();
			equipWeapon(temp);
			points = points - temp.getprice();
			cout<<"points remaining: "<<points<<endl<<"Purchase again? (1. yes | -1. no)"<<endl;
			cin>>choice;
			break;
		}
		case 11:
		{
			temp.ice();
			equipWeapon(temp);
			points = points - temp.getprice();
			cout<<"points remaining: "<<points<<endl<<"Purchase again? (1. yes | -1. no)"<<endl;
			cin>>choice;
			break;
		}
		case 12:
		{
			temp.lightning();
			equipWeapon(temp);
			points = points - temp.getprice();
			cout<<"points remaining: "<<points<<endl<<"Purchase again? (1. yes | -1. no)"<<endl;
			cin>>choice;
			break;
		}
		case 13:
		{
			temp.wind();
			equipWeapon(temp);
			points = points - temp.getprice();
			cout<<"points remaining: "<<points<<endl<<"Purchase again? (1. yes | -1. no)"<<endl;
			cin>>choice;
			break;
		}
		default:
			cout<<"Thank you for your purchase"<<endl;
			break;
		}
	}
}

void character::chooseclass(){

	int option;

	cout<< "choose class: "<<endl;
	cout<<"1. Fighter"<<endl<<"2. Mage"<<endl<<"3. Rogue"<<endl<<"4. knight"<<endl;
	cin>>option;
	switch (option){
	case 1: this->makefighter(); break;

	case 2: this->makemage(); break;

	case 3: this->makerogue(); break;

	case 4: this->makeknight(); break;

	case 9999: cout<<"nice hacks"<<endl<<endl;
		this->makeDEV(); break;

	default: cout<<"invalid option..."<<endl<<"defaulting to fighter"<<endl;
	this->makefighter(); break;

	}
}

int character::gethealth(){
	return health;
}

void character::resethealth(){
	health = 0;
}



void character::buyarmor(){
	int ar;
	cout<<"what armor set would you like?"<<endl;
	cout<<"1. hide"<<endl <<"2.chainmail "<<endl<<"3. scalemail"<<endl <<"4.halfplate "<<endl <<"5.plate "<<endl<<"6. None"<<endl;
	cin>>ar;
	switch(ar){
	case 1:
		if(points >= 5){
			this->set.hide(); calcAC(); setweak();
			points = points -set.getprice();}
		else {cout<<"You cannot afford this armor set"<<endl;}
		break;

	case 2: if(points >= 13){
		this->set.chainmail(); calcAC();setweak();
		points = points -set.getprice();}
	else {cout<<"You cannot afford this armor set"<<endl;}
	break;

	case 3: if(points >= 15){
		this->set.scalemail(); calcAC(); setweak();
		points = points -set.getprice();}
	else{ cout<<"You cannot afford this armor"<<endl;}
	break;

	case 4:
		if(points >= 18){
			this->set.plate(); calcAC(); setweak();
			points = points - set.getprice();}
		else{ cout<<"You cannot afford this armor"<<endl;}
		break;

	case 5:
		if(points >= 18){
			this->set.plate(); calcAC(); setweak();
			points = points - set.getprice();}
		else{ cout<<"You cannot afford this armor"<<endl;}
		break;


	default:
		this->set.none();
		calcAC();
		setweak();
		cout<<"Your Armor has been set to none"<<endl;
		break;

	}
}


istream& operator >> (istream& in, character& temp){

	string s;
	int set;
	getline(in, s);
	stringstream con(s);
	con>>temp.name>>temp.faction>>set;

	switch (set){
		case 1: temp.makefighter(); break;

		case 2: temp.makemage(); break;

		case 3: temp.makerogue(); break;

		case 4: temp.makeknight(); break;

		case 9999: cout<<"nice hacks"<<endl<<endl;
			temp.makeDEV(); break;

		default:
		temp.makefighter(); break;

		}

	return in;
}

void character::printspread()
{
	weapon temp;
	cout<<"1. ";
	temp.dagger();
	temp.printshop();
	cout<<"2. ";
	temp.doubledagger();
	temp.printshop();
	cout<<"3. ";
	temp.mace();
	temp.printshop();
	cout<<"4. ";
	temp.spear();
	temp.printshop();
	cout<<"5. ";
	temp.crossbow();
	temp.printshop();
	cout<<"6. ";
	temp.flail();
	temp.printshop();
	cout<<"7. ";
	temp.greatsword();
	temp.printshop();
	cout<<"8. ";
	temp.longsword();
	temp.printshop();
	cout<<"9. ";
	temp.rapier();
	temp.printshop();
	cout<<"10. ";
	temp.fire();
	temp.printshop();
	cout<<"11. ";
	temp.ice();
	temp.printshop();
	cout<<"12. ";
	temp.lightning();
	temp.printshop();
	cout<<"13. ";
	temp.wind();
	temp.printshop();
	//	cout<<"14. ";
	//	temp.devsword();
	//	temp.printshop();
}

int character::combatdmg(weakness tarweak, weakness element, int damage_done)
{
	int effectiveness;
	effectiveness = isweak(tarweak, element);
	if(effectiveness == -2)
	{
		cout<<"EXPLOIT! ";
		return damage_done * 2;
	}
	if(effectiveness == -1)
	{
		cout<<"EVEN! ";
		return damage_done;
	}
	if(effectiveness == 0)
	{
		cout<<"RESIST! ";
		return damage_done / 2;
	}

	return damage_done;
}
