#ifndef PRESIDENTIALPARDONF_HPP
#define PRESIDENTIALPARDONF_HPP

#include "Form.hpp"


class PresidentialPardonForm : public Form
{
	public:
									PresidentialPardonForm(void);
									PresidentialPardonForm(PresidentialPardonForm const &ppf);
									PresidentialPardonForm(std::string name);
		virtual 					~PresidentialPardonForm(void);
		PresidentialPardonForm		&operator=(PresidentialPardonForm const &ppf);

		void 						execute(Bureaucrat const &bu) const;
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &ppf); 

#endif