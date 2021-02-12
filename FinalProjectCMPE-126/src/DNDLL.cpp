/*
 * DNDLL.cpp
 *
 *  Created on: Apr 22, 2020
 *      Author: leon_
 */
#include "DNDLL.h"

DLL::DLL(){
	head = NULL;
	tail = NULL;
}

void DLL::insertbeg(character n){

	dnode* temp = new dnode;
	temp->human = n;
	temp->players = players;

	if(players == 0){
		head = temp;
		players++;

	}
	else if(players  == 1){
		tail = temp;
		head->next  = tail;
		players++;
	}
	else if (players >1 ){
		temp->next = head;
		head = temp;
		players++;
	}


}




void DLL::printplayersstats(){
	dnode* temp = head;
	int count = 0;
	while (count != players){

		cout<<temp->human<<" "<<count+1<<endl<<endl;
		temp = temp->next;
		count++;


	}

}
void DLL::printplayers(){
	dnode* temp = head;
	int count = 0;
	while (count != players){

		cout<<temp->human.getname()<<" "<<count+1<<endl<<endl;
		temp = temp->next;
		count++;


	}

}


bool DLL::play(){
	while(!allenemiesdead() && !allalliesdead()){
		return true;
	}

	if(allalliesdead()){
		cout<<"The Enemies have won"<<endl;
	}
	if(allenemiesdead()){
		cout<<"The Allies have won"<<endl;
	}

	return false;
}

void DLL::gametime(){
	dnode* temp = head;

	character n;
	int move;
	int choice;

	//buy phase and player setup

	while (play()){

		if(temp->human.getcondition() != 0  && temp->human.getcondition() != -1 && !onlyup() ){
			cout<<temp->human.getname()<<" make move:"<<endl;
			cout<<"1.attack"<<endl<<"2. use item"<<endl<<"3. Skip turn"<<endl;
			cin>>move;
			switch(move){
			case 1: hit(temp); break;

			case 2:
				cout<<"what item would you like to use?"<<endl;
				cout<<"1. health potion"<<endl<<"2.Repair kit"<<endl<<"3.Consumable"<<endl;
				cin>>choice;
				if(choice == 1){
					usepots(temp);
				}
				if(choice == 2){
					cout<<"1. regular"<<endl<<"2. +"<<endl;
					int j,wep;
					cin>>j;
					cout<<"What weapon?"<<endl;

					temp->human.printweapons();
					cin>>wep;
					temp->human.use_repairkit(j,temp->human.equipped[wep]);
				}
				if (choice == 3){

					int hit;
					cout<<"Who would you like to hit?"<<endl;
					dnode* temp2 = head;
					int count = 0;
					while (count != players){

						cout<<temp2->human.getname()<<" "<<count+1<<endl<<endl;
						temp2 = temp2->next;
						count++;

					}

					cin>>hit;

					int count2= 1;
					temp2 = head;
					while (count2 != hit){
						temp2 = temp2->next;
						count2++;
					}


					cout<<"what consumable would you like to use?"<<endl;
					cout<<"1.Fragile hammer"<<endl<<"2.Throwing Daggers"<<endl<<"3. Magic Talisman"<<endl;
					int c;
					cin>>c;
					switch(c){
					case 1: temp->human.usefrag(temp2->human); break;


					case 2: temp->human.usedagger(temp2->human); break;


					case 3: temp->human.usetalisman(temp2->human); break;

					default: move = 3; cout<<"turn skipped"<<endl; break;
					}

					if(temp2->human.gethealth() <= 0){
						temp2->human.setcondition(0);
						temp2->human.resethealth();
					}
					cout<<temp2->human.getname()<<" has "<<temp2->human.gethealth()<<" HP left."<<endl;
				}//close choice 3




			default: cout<<"turn skipped"<<endl; break;
		}//closes switch

		}

		temp = temp->next;
		if(temp == NULL){
			temp =head;
		}
	else{
		temp->human.deathtrial();
		temp = temp->next;
		if (temp == NULL){
			temp =head;
		}
	}
	}
}

bool DLL::allalliesdead(){
	int count = 0;
	int ally = 0;
	dnode* temp = head;


	while(temp!=NULL){
		if(temp->human.getcondition() == -1 && temp->human.getfaction() == 0 ){
			count++;
		}
		if(temp->human.getfaction() == 0){
			ally++;
		}
		temp =temp->next;
	}
	if(count == ally){
		return true;
	}
	else
		return false;
}

bool DLL::allenemiesdead(){
	int count = 0;
	int enemy = 0;
	dnode* temp = head;


	while(temp!=NULL){
		if(temp->human.getcondition() == -1 && temp->human.getfaction() == 1 ){
			count++;
		}
		if (temp->human.getfaction() == 1 ){
			enemy++;
		}

		temp =temp->next;
	}
	if( count == enemy ){
		return true;
	}
	else
		return false;
}

bool DLL::onlyup(){
	if(alleun()||allaun()) return true;
	else return false;
}

bool DLL::allaun(){
	int count = 0;
	int ally = 0;
	dnode* temp = head;


	while(temp!=NULL){
		if(temp->human.getcondition() == 0 && temp->human.getfaction() == 0 ){
			count++;
		}
		if(temp->human.getfaction() == 0){
			ally++;
		}
		temp =temp->next;
	}
	if(count == ally){
		return true;
	}
	else
		return false;
}

bool DLL::alleun(){
	int count = 0;
	int enemy = 0;
	dnode* temp = head;


	while(temp!=NULL){
		if(temp->human.getcondition() == 0 && temp->human.getfaction() == 1 ){
			count++;
		}
		if (temp->human.getfaction() == 1 ){
			enemy++;
		}

		temp =temp->next;
	}
	if( count == enemy ){
		return true;
	}
	else
		return false;
}

void DLL::hit(dnode* temp){

	int p;
	cout<<"who would you like to attack?: "<<endl;
	dnode* temp2 = head;
	int count = 0;
	while (count != players){

		cout<<temp2->human.getname()<<" "<<count+1<<endl<<endl;
		temp2 = temp2->next;
		count++;
	}
	cin>>p;

	int count2= 1;
	temp2 = head;
	while (count2 != p){
		temp2 = temp2->next;
		count2++;
	}
	temp->human.attack(temp2->human);

	if(temp2->human.gethealth() <= 0){
		temp2->human.setcondition(0);
		temp2->human.resethealth();
	}
	cout<<temp2->human.getname()<<" has "<<temp2->human.gethealth()<<" HP left."<<endl;
}

void DLL::usepots(dnode* temp){
	cout<<"1. small"<<endl<<"2. medium"<<endl<<"3.large"<<endl;
	int j;
	cin>>j;
	temp->human.use_hpitem(j,temp->human);
}
