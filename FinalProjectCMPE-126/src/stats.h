/*
 * stats.h
 *
 *  Created on: Apr 24, 2020
 *      Author: natev
 */

#ifndef STATS_H_
#define STATS_H_
#include <iostream>
using namespace std;

//incldudes stats and modifiers
class stats{
private:
	int str;
	int mag;
	int dex;
	int spd;
	int def;

public:
	int strmod;
	int magmod;
	int dexmod;
	int spdmod;
	int defmod;
	stats();
	void setmods(); //sets the modifiers

	//stat cap is 20
	void set_str(int i);//sets str to value <= 20
	void set_mag(int i);//sets mag to value <= 20
	void set_dex(int i);//sets dex to value <= 20
	void set_spd(int i);//sets spd to value <= 20
	void set_def(int i);//sets def to value <= 20

	int getspd();

	void fighter(); //gives a fighter stat spread
	void mage(); //makes mage stat spread
	void knight(); //makes knight stat spread
	void rogue(); //makes rogue stat spread
	void DEV(); //not supposed to be used

	void default_stats();//makes a default stat spread
	void icr_str(); //+1 str
	void icr_mag(); //+1 mag
	void icr_dex(); //+1 dex
	void icr_spd(); //+1 spd
	void icr_def(); //+1 def

	friend ostream& operator<<(ostream &ost, stats s); //prints out the stats

};




#endif /* STATS_H_ */
