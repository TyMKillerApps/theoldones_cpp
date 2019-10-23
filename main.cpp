/* obviously main everything place */
#include <iostream>
using namespace std;
int main()
{
	bool hero_choice_1 {false};
	int menu_choice;
	string hero_name;
        do{
		cout << "\nWelcome to The Old Ones\n";
		cout << "\n1) Name Hero\n";
		cout << "\n2) Generate Hero Stats\n";
		cout << "\n3) Test Dice Rolls\n";
		cout << "\n4) Exit\n";
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
				cout << "\n place holder 3" << endl;
				break;
			case 4:
				cout << "\n Exiting now" << endl;
				hero_choice_1 = true;
				break;
			default:
				cout << "\nChoose a correct menu item\n";
			continue;
		}
	}
	while (!hero_choice_1);
return 0;
}
