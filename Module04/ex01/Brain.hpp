#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain {
	private:
		std::string _ideas[100];
	
	public:
		Brain();
		Brain(const Brain &src);
		Brain& operator=(const Brain &src);
		~Brain();

		std::string*	getIdeas();
		int						getIdeasNbr() const;

		void	setIdea(std::string idea);
		void	printIdeas() const;
};

#endif