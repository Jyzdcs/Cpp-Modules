#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const& src);
		FragTrap& operator=(FragTrap const& src);
		virtual ~FragTrap();

		void	attack(const std::string& target);
		void	highFiveGuys(void);
};

#endif