/* obviously main everything place */
#include <iostream>
#include "dice.h"
#include "battle.h"
#include "enemy.h"
#include "experience.h"
#include "hero.h"
#include "input.h"
#include "npc.h"
#include "render.h"
#include "save.h"
#include "spells.h"
#include "update.h"
#include "world.h"
using namespace std;
int main()
{
	bool hero_choice_1 {false};
	int menu_choice;
	fair_dice fdice1;
	string hero_name;
        do{
		cout << "\nWelcome to The Old Ones\n";
		cout << "\n1) Name Hero\n";
		cout << "\n2) Generate Hero Stats\n";
		cout << "\n3) Test Dice Rolls\n";
		cout << "\n4) Exit\n";
		cout << "\n5) Enemy Test\n";
		cout << "\n6) Experience Test\n";
		cout << "\n7) Npc Test\n";
		cout << "\n8) Spells Test\n";
		cin >> menu_choice;
		switch (menu_choice)
		{
			case 1:
				cout << "\nEnter Hero Name: ";
				cin >> hero_name;
				cout << "\n Hero name is: "<< hero_name << endl;
				break;
			case 2:
				cout << "\n place holder 2" << endl;
				break;
			case 3:
				cout << "\n Enter Number of Dice to be rolled: " << endl;
				cin >> fdice1.number_of_die;
				cout << "\n Enter Number of Sides on dice: " << endl;
				cin >> fdice1.sided_dice;
				cout << "\n Rolling Dice ..." << endl;
				fdice1.roll_dice(fdice1.number_of_die,fdice1.sided_dice);
				/* for(int i = 0; i < fdice1.number_of_die; ++i)
				{
					cout << "\n die #" << i << " :" << fdice1.die[i] << endl;
				}*/
				break;
			case 4:
				cout << "\n Exiting now" << endl;
				hero_choice_1 = true;
				break;
			case 5:
				cout <<"\n Place holder .. choose another choice" << endl;
				break;
			case 6:
				cout <<"\n Place holder .. choose another choice" << endl;
				break;
			case 7:
				cout <<"\n Place holder .. choose another choice" << endl;
				break;
			case 8:
				cout <<"\n Place holder .. choose another choice" << endl;
				break;
			default:
				cout << "\nChoose a correct menu item\n";
			continue;
		}
	}
	while (!hero_choice_1);
return 0;
}
