/*
 * item.cpp
 *
 *  Created on: May 1, 2020
 *      Author: leon_
 */
#include "item.h"

item::item(){

	shp = 0;
	mhp = 0;
	lhp = 0;


	repairkit = 0;
	betterrepairkit = 0;

	fragilehammer = 0;
	throwingdaggers = 0;
	magictalisman = 0;
}

int item::setrepairkits(int count){
	int b;
	int option = 0;

	while (option != 3 && count > 0){
		cout<<"you have "<<count<<" point(s)"<<endl;
		cout<<"What kind of repair kit would you like? "<<endl<<endl;
		cout<<"1. small (5pts)"<<endl<<"2. Medium (7pts)"<<endl<<"3. none"<<endl;
		cin>>option;

		if(option !=3){
			cout<<"How many would you like to obtain"<<endl<<endl;
			cin>>b;
		}

		switch(option){
		case 1: if (count - (b*5) < 0){
			cout<< "Not enough points left"<<endl<<endl;
			break;
		}
		else  {
			repairkit = repairkit + b; count = count - (b*5);
			break;
		}

		case 2:if (count - (b*7) < 0){
			cout<< "Not enough points left"<<endl<<endl;
			break;
		}
		else  {
			repairkit = repairkit + b; count = count - (b*7);
			break;
		}
		case 3: break;

		default: cout<<"invalid option..."<<endl;

		}//close switch
	}//close while loop
	return count;
}



int item::setpotions(int count){
	int b;
	int option = 0;

	while(option != 4 && count > 0){
		cout<<"you have "<<count<<" point(s)"<<endl;
		cout<<"What kind of potion would you like? "<<endl<<endl;
		cout<<"1. Small (1pt)"<<endl<<"2. Medium (3pts)"<<endl<<"3. Large (5pts)"<<endl<<"4. none"<<endl;
		cin>>option;

		if(option !=4){
			cout<<"How many would you like to obtain"<<endl<<endl;
			cin>>b;
		}
		switch (option){
		case 1:
			if (count - b < 0){
				cout<< "Not enough points"<<endl;
				break;
			}
			else{
				shp = shp + b; count = count - b;
				break;
			}
		case 2:
			if (count - (b*3) < 0){
				cout<< "Not enough points"<<endl;
				break;
			}
			else{
				mhp = mhp + b; count = count - (b*3);
				break;
			}
		case 3:
			if (count - (b*5) < 0){
				cout<< "Not enough points"<<endl;
				break;
			}
			else{
				lhp = lhp + b; count = count - (b*5);
				break;
			}
		case 4: break;

		default: cout<< "invalid option..."<<endl; break;
		}//close switch
	}//close while loop


	return count;
}

int item::getshp(){
	return shp;
}
int item::getmhp(){
	return mhp;
}

int item::getlhp(){
	return lhp;
}

int item::getrepair(){
	return repairkit;
}

int item::getbetrep(){
	return betterrepairkit;
}

int item::gethammer(){
	return fragilehammer;
}
int item::gettd(){
	return throwingdaggers;
}
int item::getmagital(){
	return magictalisman;
}

int item::setattackitem(int count){
	int b;

	int option = 0;

	while(option != 4 && count > 0){
		cout<<"you have "<<count<<" point(s)"<<endl;
		cout<<"What kind of attack item would you like? "<<endl<<endl;
		cout<<"1. Fragile Hammer (1pt)"<<endl<<"2. Throwing daggers (2pts)"<<endl<<"3. Magical Talisman (5pts)"<<endl<<"4. none"<<endl;
		cin>>option;

		if(option !=4){
			cout<<"How many would you like to obtain"<<endl<<endl;
			cin>>b;
		}
		switch (option){
		case 1:
			if (count - b < 0){
				cout<< "Not enough points"<<endl;
				break;
			}
			else{
				fragilehammer = fragilehammer + b; count = count - b;
				break;
			}
		case 2:
			if (count - (b*2) < 0){
				cout<< "Not enough points"<<endl;
				break;
			}
			else{
				throwingdaggers = throwingdaggers + b; count = count - (b*2);
				break;
			}
		case 3:
			if (count - (b*5) < 0){
				cout<< "Not enough points"<<endl;
				break;
			}
			else{
				magictalisman = magictalisman + b;count = count - (b*5);
				break;
			}
		case 4: break;

		default: cout<< "invalid option..."<<endl; break;
		}//close switch
	}//close while loop
		return count;
	}




void item::useshp(){
	shp--;
}
void item::usemhp(){
	mhp--;
}

void item::uselhp(){
	lhp--;
}

void item::userepair(){
	repairkit--;
}

void item::usebetrep(){
	betterrepairkit--;
}

void item::usehammer(){
	fragilehammer--;
}
void item::usetd(){
	throwingdaggers--;
}
void item::usemagital(){
	magictalisman--;
}
