#ifndef S_CREATION_F_HPP
#define S_CREATION_F_HPP

#include "Form.hpp"


class ShrubberyCreationForm : public Form
{
public:
	public:
									ShrubberyCreationForm(void);
									ShrubberyCreationForm(ShrubberyCreationForm const &scf);
									ShrubberyCreationForm(std::string name);
		virtual 					~ShrubberyCreationForm(void);
		ShrubberyCreationForm		&operator=(ShrubberyCreationForm const &scf);

		void 						execute(Bureaucrat const &bu) const;
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &scf); 

#endif