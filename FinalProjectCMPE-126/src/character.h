/*
 * character.h
 *
 *  Created on: Apr 22, 2020
 *      Author: natev
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_
using namespace std;
#include "stats.h"
#include "weakness.h"
#include "armor.h"
#include "weapon.h"
#include "item.h"
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>

class character{
private:
	string name;
	int health;
	int max_hp;
	int faction; //0 is ally, 1 is enemy, 2 is other
	int points;
	int condition; //1=alive, 0=unconcscious, -1=dead
	int deathsaves; //start with 3 if you get hit while unconcious make a roll, if roll is high enough you survive,  if it isnt you die, if deathsaves=0 you die

	stats s;
	int AC;
	//covers the charater's raw stats like strength, mag, dex, speed, defense, resistance
	//stat caps are 20
	//basic is 10, every 2 points above 10 gives a bonus so if u have 12 strength you get a +1 modifier to strength
	//these modifiers affect attacks of the same type

	item its;
	weakness w;
	//signifies the type of damages that a unit is weak or resistant to
	//types of physical damage: pierce, slash, and blunt (strong against different types of armor)
	//types of magic: fire, ice, lightning, wind, (add more later maybe?) strong against different types of enemies/armor
	//all the values could be represented by integers -1=weak to, 0=even, 1=strong against
	// ex. int wind=-1 (weak to wind)

	armor set;
	//different types of armors give different resistances and weaknesses


	int numequip;
	//weapons have # of uses
	//dmg

	bool magical;
	//denotes if a character can even use magic


	//list of spells that a character can cast
	//i think this might need to be like a "db" class because we would need to be able to store the spell data in this class as well

	//items list[10];

public:

	weapon equipped[10];
	character(); //default constructor
	void makefighter(); //makes fighter character
	void makemage(); //makes mage character
	void makerogue(); //makes a rogue character
	void makeknight(); //makes a knight character
	void makeDEV(); //do not use

	//getters and setters
	void setName(string s); //sets the name
	void setcondition(int i); //sets the condition
	void setfaction(int i); //sets faction
	void resethealth();
	string getname();
	int getAC(); //returns AC
	int getfaction(); //returns faction
	int getcondition(); //returns condition
	int getpoints();
	int getspd();
	int gethealth();
	weakness getweak(); //gets the character weakness


	//armor functions
	void equipArmor(armor a); //equips armor and sets character AC
	void calcAC();//armor ac + def mod (only used in equipArmor)
	void setweak(); //sets character weakness (only used in equipArmor)

	//weapon functions
	void equipWeapon(weapon w); //equips a weapon

	void clear_equip();//deequips everything (resets character to without equipment


	void attack(character& target);
	void selectattk();
	//havent exactly thought of how we're going to do this yet
	//roll a d20, add modifier, if it is higher than the opponents defense, roll dmg denoted by weapon, add modifier for damage
	void takedamage(int taken); //only used in the attack function

	int calcDamage(weapon w);
	int roll(int numdice, int dicesides); //takes in the number of dice and dice sides and returns a result
	int combatdmg(weakness tarweak, weakness element, int damage_done);

	//void next_turn();
	//ends turn


	void use_hpitem(int option,character& temp); //uses specified health item
	void use_repairkit(int option, weapon choice); //uses specified repair item


	void buyarmor();
	void buyweapons();
	void buyitems(); //buys items at beginning
	void deathtrial(); //rolls the deathsave

	void printw();
	void printweapons(); //prints out weapon inventory
	void printarmor(); //prints out armor statistic
	void print_inv(); //prints out item inventory
	void printspread(); //prints out all the weapons stats;

	friend ostream& operator<<(ostream& ost, character ch);
	friend istream& operator >> (istream& in, character& temp);
	bool operator<(character n);


	void usedagger(character& n);
	void usetalisman(character& target);
	void usefrag(character& n);

	void chooseclass();


};



#endif /* CHARACTER_H_ */
