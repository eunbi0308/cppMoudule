#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
*	The choice between a reference(HumanA) and a pointer(HumanB).
*	Because 'HumanA' always has a valid Weapon while 'HumanB' may
*	not always have a Weapon.
*	- 'HumanA' is initialized with a reference to a 'Weapon' object.
*	This means that once 'HumanA' is constructed, it cannot change
*	its weapon. The reference is bound to the 'Weapon'.
*	- 'HumanB' uses a pointer to 'Weapon'. This allows 'HumanB' to
*	intially to have no weapon(nullptr) and the weapon can be changed
*	by calling 'setWeapon()', allowing for flexibility in changing weapons
*	during lifetime of the object.
*/

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack(); 
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	/***************************************************/
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		club.setType("some other type of club");
		bob.attack(); 
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Bim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}