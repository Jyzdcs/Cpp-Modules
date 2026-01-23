#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <iostream>

class ClapTrap {
	protected:
		std::string 		_name;
		unsigned int		_health;
		unsigned int		_energy;
		unsigned int		_attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& src);
		ClapTrap& operator=(ClapTrap const& src);
		virtual ~ClapTrap();

		std::string	getName() const;
		int					getHealth() const;
		int					getEnergy() const;
		int					getAttackDamage() const;

		void				setName(std::string name);

		void takeDamage(unsigned int amount);
		void beReparaied(unsigned int amount);

		virtual void attack(const std::string& target);
};

#endif