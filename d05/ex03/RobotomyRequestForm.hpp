#ifndef ROBOTOMYREQUESTFORMF_HPP
#define ROBOTOMYREQUESTFORMF_HPP

#include "Form.hpp"


class RobotomyRequestForm : public Form
{
	public:
									RobotomyRequestForm(void);
									RobotomyRequestForm(RobotomyRequestForm const &rrf);
									RobotomyRequestForm(std::string name);
		virtual 					~RobotomyRequestForm(void);
		RobotomyRequestForm		&operator=(RobotomyRequestForm const &rrf);

		void 						execute(Bureaucrat const &bu) const;
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &rrf); 

#endif