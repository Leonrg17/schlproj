/*
 * stats.cpp
 *
 *  Created on: Apr 27, 2020
 *      Author: natev
 */

#include "stats.h"
#include <iostream>

stats::stats()
{
	str = 8;
	mag = 8;
	dex = 8;
	spd = 8;
	def = 8;
	strmod = -1;
	magmod = -1;
	dexmod = -1;
	spdmod = -1;
	defmod = -1;

}

void stats::default_stats()
{
	str = 8;
	mag = 8;
	dex = 8;
	spd = 8;
	def = 8;
	strmod = -1;
	magmod = -1;
	dexmod = -1;
	spdmod = -1;
	defmod = -1;
}

void stats::fighter()
{
	str = 15;
	mag = 8;
	dex = 10;
	spd = 14;
	def = 13;
	setmods();
}
void stats::mage()
{
	str = 8;
	mag = 15;
	dex = 10;
	spd = 14;
	def = 13;
	setmods();
}

void stats::knight()
{
	str = 14;
	mag = 13;
	dex = 10;
	spd = 8;
	def = 15;
	setmods();
}

void stats::rogue()
{
	str = 10;
	mag = 13;
	dex = 14;
	spd = 15;
	def = 8;
	setmods();
}

void stats::DEV()
{
	str = 9999;
	mag = 9999;
	dex = 9999;
	spd = 9999;
	def = 9999;
	setmods();
}
void stats::set_str(int i)
{
	if(i <= 20)
	{
		str = i;
	}
	else
	{
		cout<<"error input more than stat cap"<<endl;
	}
}

void stats::set_mag(int i)
{
	if(i <= 20)
	{
		mag = i;
	}
	else
	{
		cout<<"error input more than stat cap"<<endl;
	}
}

void stats::set_dex(int i)
{
	if(i <= 20)
	{
		dex = i;
	}
	else
	{
		cout<<"error input more than stat cap"<<endl;
	}
}

void stats::set_spd(int i)
{
	if(i <= 20)
	{
		spd = i;
	}
	else
	{
		cout<<"error input more than stat cap"<<endl;
	}
}

void stats::set_def(int i)
{
	if(i <= 20)
	{
		def = i;
	}
	else
	{
		cout<<"error input more than stat cap"<<endl;
	}
}

void stats::icr_str()
{
	if(str < 20)
	{
		str++;
	}
	else
	{
		cout<<"error stats cant go any higher"<<endl;
	}
}

void stats::icr_mag()
{
	if(mag < 20)
	{
		mag++;
	}
	else
	{
		cout<<"error stats cant go any higher"<<endl;
	}
}

void stats::icr_dex()
{
	if(dex < 20)
	{
		dex++;
	}
	else
	{
		cout<<"error stats cant go any higher"<<endl;
	}
}

void stats::icr_spd()
{
	if(spd < 20)
	{
		spd++;
	}
	else
	{
		cout<<"error stats cant go any higher"<<endl;
	}
}

void stats::icr_def()
{
	if(def < 20)
	{
		def++;
	}
	else
	{
		cout<<"error stats cant go any higher"<<endl;
	}
}

ostream& operator<<(ostream &ost, stats s)
{
	cout<<"str: "<<s.str<<" str mod: "<<s.strmod<<endl;
	cout<<"mag: "<<s.mag<<" mag mod: "<<s.magmod<<endl;
	cout<<"dex: "<<s.dex<<" dex mod: "<<s.dexmod<<endl;
	cout<<"spd: "<<s.spd<<" spd mod: "<<s.spdmod<<endl;
	cout<<"def: "<<s.def<<" def mod: "<<s.defmod<<endl;


	return ost;
}

void stats::setmods()
{
	strmod = (str - 10)/2;
	magmod = (mag - 10)/2;
	dexmod = (dex - 10)/2;
	spdmod = (spd - 10)/2;
	defmod = (def - 10)/2;

	if(strmod < 0)
	{
		if(str == 9)
		{
			strmod = -1;
		}
		if(str == 7)
		{
			strmod = -2;
		}
		if(str == 5)
		{
			strmod = -3;
		}
		if(str == 3)
		{
			strmod = -4;
		}
		if(str == 1)
		{
			strmod = -5;
		}
	}
	if(magmod < 0)
	{
		if(mag == 9)
		{
			magmod = -1;
		}
		if(mag == 7)
		{
			magmod = -2;
		}
		if(mag == 5)
		{
			magmod = -3;
		}
		if(mag == 3)
		{
			magmod = -4;
		}
		if(mag == 1)
		{
			magmod = -5;
		}
	}
	if(dexmod < 0)
	{
		if(dex == 9)
		{
			dexmod = -1;
		}
		if(dex == 7)
		{
			dexmod = -2;
		}
		if(dex == 5)
		{
			dexmod = -3;
		}
		if(dex == 3)
		{
			dexmod = -4;
		}
		if(dex == 1)
		{
			dexmod = -5;
		}
	}
	if(spdmod < 0)
	{
		if(spd == 9)
		{
			spdmod = -1;
		}
		if(spd == 7)
		{
			spdmod = -2;
		}
		if(spd == 5)
		{
			spdmod = -3;
		}
		if(spd == 3)
		{
			spdmod = -4;
		}
		if(spd == 1)
		{
			spdmod = -5;
		}
	}
	if(defmod < 0)
	{
		if(def == 9)
		{
			defmod = -1;
		}
		if(def == 7)
		{
			defmod = -2;
		}
		if(def == 5)
		{
			defmod = -3;
		}
		if(def == 3)
		{
			defmod = -2;
		}
		if(def == 1)
		{
			defmod = -1;
		}
	}
}
int stats::getspd(){
	return spd;
}
