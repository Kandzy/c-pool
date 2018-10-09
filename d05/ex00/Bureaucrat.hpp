#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	public:
								Bureaucrat(void);
								Bureaucrat(std::string const name, short int grade);
								Bureaucrat(Bureaucrat const & bu);
								Bureaucrat &operator=(Bureaucrat const &bu);
		virtual					~Bureaucrat(void);

		std::string				getName(void) const;
		int						getGrade(void) const;
		void					operator+=(int const i);
		void					operator-=(int const i);

		class GradeTooHighException : public std::exception {
			public:
										GradeTooHighException(void);
										GradeTooHighException(GradeTooHighException const & tr);
										GradeTooHighException &operator=(GradeTooHighException const &tr);
				virtual					~GradeTooHighException(void)  throw();
				virtual const char*		what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
										GradeTooLowException(void);
										GradeTooLowException(GradeTooLowException const & tr);
										GradeTooLowException &operator=(GradeTooLowException const &tr);
				virtual					~GradeTooLowException(void)  throw();
				virtual const char*		what() const throw();
		};
	private:
		const std::string		_name;
		short int		_grade;

};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bu); 

#endif