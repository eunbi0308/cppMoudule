#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	{
		std::cout << "------------- TEST 1 -------------" << std::endl;
		ClapTrap Biggie = ClapTrap("Biggie");
		ScavTrap Middie = ScavTrap("Middie");
		FragTrap Minie = FragTrap("Minie");

		Minie.attack(Biggie.getName());
		Minie.attack(Middie.getName());
		Biggie.takeDamage(Biggie.getDamage());
		Middie.takeDamage(Middie.getDamage());
		Biggie.beRepaired(1);
		Middie.beRepaired(33);
		/** High five **/
		Minie.highFivesGuys();
		std::cout << std::endl;

		Middie.attack(Biggie.getName());
		Middie.attack(Minie.getName());
		Biggie.takeDamage(Biggie.getDamage());
		Minie.takeDamage(Minie.getDamage());
		/** Gate Keeper mode **/
		Middie.guardGate();
		std::cout << std::endl;

		/** Biggie is dead **/
		Biggie.takeDamage(70);
		/** Should not called **/
		Biggie.beRepaired(10);
		std::cout << std::endl;

		/** Running out energy**/
		for (int i = 0; i <= 96; i++)
			Minie.attack(Biggie.getName());
		/** Out of energy **/
		Minie.attack(Biggie.getName());
		/** Should not called **/
		Minie.highFivesGuys();
	}
	return 0;
}