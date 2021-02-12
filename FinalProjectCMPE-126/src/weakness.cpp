/*
 * weakness.cpp
 *
 *  Created on: May 1, 2020
 *      Author: natev
 */
#include "weakness.h"

weakness::weakness()
{
	pierce = 0;
	slash = 0;
	blunt = 0;
	fire = 0;
	wind = 0;
	lightning = 0;
	ice = 0;
}

void weakness::setpierce(int i)
{
	pierce = i;
}

void weakness::setslash(int i)
{
	slash = i;
}

void weakness::setblunt(int i)
{
	blunt = i;
}

void weakness::setfire(int i)
{
	fire = i;
}

void weakness::setwind(int i)
{
	wind = i;
}

void weakness::setlightning(int i)
{
	lightning = i;
}

void weakness::setice(int i)
{
	ice = i;
}

void weakness::clearweak()
{
	pierce = 0;
	slash = 0;
	blunt = 0;
	fire = 0;
	wind = 0;
	lightning = 0;
	ice = 0;
}

void weakness::allweak()
{
	pierce = -1;
	slash = -1;
	blunt = -1;
	fire = -1;
	wind = -1;
	lightning = -1;
	ice = -1;
}

int isweak(weakness target, weakness weapon){
	weakness result;

	result.pierce = target.pierce + weapon.pierce;
	result.slash = target.slash + weapon.slash;
	result.blunt = target.blunt + weapon.blunt;
	result.fire = target.fire + weapon.fire;
	result.wind = target.wind + weapon.wind;
	result.lightning = target.lightning + weapon.lightning;
	result.ice = target.ice + weapon.ice;
	//-2=exploit, -1 = even, 0 = resist
	if(weapon.pierce == -1)
	{
		return result.pierce;
	}
	else if(weapon.slash == -1)
	{
		return result.slash;
	}
	else if(weapon.blunt == -1)
	{
		return result.blunt;
	}
	else if(weapon.fire == -1)
	{
		return result.fire;
	}
	else if(weapon.wind == -1)
	{
		return result.wind;
	}
	else if(weapon.lightning == -1)
	{
		return result.lightning;
	}
	else if(weapon.ice == -1)
	{
		return result.ice;
	}
	return -1;
}
ostream& operator<<(ostream& ost, weakness w)
{
	cout<<"******************************************"<<endl;
	cout<<"affinity: "<<endl<<"-1=weakness/exploit, 0=even, 1=resistant"<<endl;
	cout<<"pierce: "<<w.pierce<<endl;
	cout<<"slash: "<<w.slash<<endl;
	cout<<"blunt: "<<w.blunt<<endl;
	cout<<"fire: "<<w.fire<<endl;
	cout<<"wind: "<<w.wind<<endl;
	cout<<"lightning: "<<w.lightning<<endl;
	cout<<"ice: "<<w.ice<<endl;
	cout<<"******************************************"<<endl;
	return ost;
}
