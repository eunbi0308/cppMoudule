#include "ClapTrap.hpp"

int	main()
{
	ClapTrap Biggie = ClapTrap("Biggie");
	ClapTrap Minie = ClapTrap("Minie");

	Minie.attack(Biggie.getName());
	Biggie.takeDamage(Biggie.getDamage());
	Biggie.beRepaired(1);
	Biggie.attack(Minie.getName());
	Minie.takeDamage(0);
	Minie.attack(Biggie.getName());
	Biggie.takeDamage(Biggie.getDamage());

	/** Biggie is dead **/
	Biggie.takeDamage(11);
	/** Should not called **/
	Biggie.beRepaired(8);
	Biggie.attack(Minie.getName());

	/** Running out energy**/
	for (int i = 0; i < 8; i++)
		Minie.attack(Biggie.getName());
	/** Out of energy **/
	Minie.attack(Biggie.getName());
	return 0;
}