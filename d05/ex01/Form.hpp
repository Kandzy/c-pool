#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form{
	public:
							Form(void);
							Form(Form const & bu);
							Form(std::string name, short int reqGrade, short int exeGrade);
							Form &operator=(Form const &bu);
		virtual				~Form();
		int					getReqGrade(void) const;
		int					getExeGrade(void) const;
		bool				getSigned(void) const;
		std::string			getName(void) const;
		void				beSigned(Bureaucrat const &bu);

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
		const std::string			_name;
		const short int 	_reqGrade;
		const short int 	_exeGrade;
		bool						_signed;

};

std::ostream	&operator<<(std::ostream &out, Form const &bu); 

#endif