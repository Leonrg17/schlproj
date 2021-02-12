//============================================================================
// Name        : FinalProjectCMPE-126.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "DND.h"
#include "DNDLL.h"
#include "character.h"
#include "item.h"
#include <vector>


void sort(character arr[], int sz);
void filetake(DLL& t);
void manualadd(DLL& t);

int main() {
	int option;
	cout<<"take from file or create new characters? (1. file 2. manual)"<<endl<<endl;
	DLL t;

	cin>>option;
	switch(option){
	case 1: filetake(t);
	break;

	case 2:manualadd(t);
	break;
	}

	t.printplayersstats();

	t.gametime();


	return 0;
}

void sort(character arr[], int sz){
	int maxi = 0;
	character temp;
	for(int i = 0;i<sz;i++){
		maxi = i;
		for (int j = 0;j<sz;j++){
			if(arr[j]<arr[i]){
				maxi = j;
			}
			temp = arr[i];
			arr[i] = arr[maxi];
			arr[maxi] = temp;
		}
	}
}

void filetake(DLL& t){
	fstream fin;
	vector <character> z;
	character temp;
	int sz;

	fin.open("player.txt");
	if(fin.fail()){
		cout<<"file failed to open";
		exit(1);
	}

	while(!fin.eof()){
		fin>>temp;
		z.push_back(temp);
	}
	sz = z.size();
	character*  ch = new character[z.size()];
	for (int i = 0; i<sz;i++){
		cout<<"Choose items for "<<z[i].getname()<<":"<<endl;
		z[i].buyitems();
		ch[i] = z[i];
	}
	sort(ch,sz);

	for(int i =0;i<sz;i++){
			t.insertbeg(ch[i]);
		}

}

void manualadd(DLL& t){
	int count;
	int fact;

	cout<<"how many players are playing?"<<endl;
	cin>>count;

	character*  ch = new character[count];
	string k;

	for (int i =0;i<count;i++){
		cout<<"enter name: "<<endl;
		cin>>k;
		ch[i].setName(k);
		ch[i].buyitems();
		cout<<"choose faction ALLY or ENEMY "<<endl<<"0 for ally or 1 for enemy"<<endl;
		cin>>fact;
		ch[i].setfaction(fact);
		cout<<endl;
		ch[i].chooseclass();

	}

	sort(ch,count);

	for(int i =0;i<count;i++){
		t.insertbeg(ch[i]);
	}
}
