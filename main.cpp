/* obviously main everything place */
#include <iostream>
using namespace std;
int main()
{
	bool hero_choice_1 {false};
        do{
		cout << "\nLoop Still Going.. \nKeep Going?\n";
		cin >> hero_choice_1;
		if ( hero_choice_1 )
		{
			break;
		}
		else
		{
			continue;
		}
	}
	while (!hero_choice_1);
return 0;
}
