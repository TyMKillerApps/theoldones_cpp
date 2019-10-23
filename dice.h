/* dice class collections */
#include <cstdlib>

class fair_dice
{
	public: int sided_dice;
	public: int number_of_die;
	/*int randomNumber = rand();*/
	void roll_dice( int number_of_die, int sided_dice)
	{
		int i = 0;
		do
		{
		int randomNumber = rand();
		std::cout << ((randomNumber %(sided_dice)) +1) << std::endl;
		++i;
		}
		while(i < number_of_die);
	}
};
