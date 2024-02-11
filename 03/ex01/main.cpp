#include "ScavTrap.hpp"

int	main()
{
	{
		std::cout << "------------- TEST 1 -------------" << std::endl;
		ScavTrap Biggie = ScavTrap("Biggie");
		ScavTrap Minie = ScavTrap("Minie");

		Minie.attack(Biggie.getName());
		Biggie.takeDamage(Biggie.getDamage());
		Biggie.beRepaired(1);
		Biggie.attack(Minie.getName());
		Minie.takeDamage(Minie.getDamage());
		Minie.attack(Biggie.getName());
		Biggie.takeDamage(Biggie.getDamage());

		/** Biggie is dead **/
		Biggie.takeDamage(70);
		/** Should not called **/
		Biggie.beRepaired(10);
		/** Running out energy**/
		for (int i = 0; i <= 47; i++)
			Minie.attack(Biggie.getName());
		/** Out of energy **/
		Minie.attack(Biggie.getName());
	}
	{
		std::cout << std::endl;
		std::cout << "------------- TEST 2 -------------" << std::endl;
		ClapTrap Biggie = ClapTrap("Biggie");
		ScavTrap Minie = ScavTrap("Minie");

		Minie.attack(Biggie.getName());
		Biggie.takeDamage(Biggie.getDamage());
		Biggie.beRepaired(1);
		Biggie.attack(Minie.getName());
		Minie.takeDamage(Minie.getDamage());
		Minie.attack(Biggie.getName());
		Biggie.takeDamage(Biggie.getDamage());

		/** Gate Keeper mode **/
		// Biggie.guardGate(); <- Impossible
		Minie.guardGate();
		/** Biggie is dead **/
		Biggie.takeDamage(70);
		/** Should not called **/
		Biggie.beRepaired(10);
		/** Running out energy**/
		for (int i = 0; i <= 47; i++)
			Minie.attack(Biggie.getName());
		/** Out of energy **/
		Minie.attack(Biggie.getName());
		/** Should not called **/
		Minie.guardGate();
	}
	return 0;
}