#ifndef DIAMONDTRAP_HPP
# define DIAMNONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string _name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const& src);
		DiamondTrap& operator=(DiamondTrap const& src);
		~DiamondTrap();

		void	whoAmI();
};


#endif