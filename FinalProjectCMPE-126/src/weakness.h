/*
 * weakness.h
 *
 *  Created on: May 1, 2020
 *      Author: natev
 */

#ifndef WEAKNESS_H_
#define WEAKNESS_H_
#include <iostream>
#include <string>
using namespace std;


//ints that signify weaknesses -1 for weak, 0 for even, 1 for resist
class weakness{
private:
	int pierce;
	int slash;
	int blunt;
	int fire;
	int wind;
	int lightning;
	int ice;

public:
	//-1 = weakness/exploit, 0 = even, 1 = resistant
	weakness(); //default constructor
	void clearweak(); //makes no weaknesses
	void allweak(); //makes all weaknesses
	void setpierce(int i); //sets pierce weakness
	void setslash(int i); //sets slash weakness
	void setblunt(int i); //sets blunt weakness
	void setfire(int i); //sets fire weakness
	void setwind(int i); //sets wind weakness
	void setlightning(int i); //sets lightning weakness
	void setice(int i); //setss ice weakness

	friend ostream& operator <<(ostream& ost, weakness w);
	friend int isweak(weakness target, weakness weapon); //-2=exploit, -1 = even, 0 = resist


};



#endif /* WEAKNESS_H_ */
