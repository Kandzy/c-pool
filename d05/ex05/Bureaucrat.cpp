#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("Undefined")
{
    this->_grade = 150;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, short int grade) : _name(name)
{
	if(grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}else if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else {
		this->_grade = grade;
	}
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &bu)
{
	*this = bu;
	return;
}


Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bu)
{
	if (this != &bu)
	{
		this->_grade = bu._grade;
	}
	return *this;
}

void	Bureaucrat::operator+=(int const i)
{
	if((this->_grade - i) > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}else if (this->_grade - i < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else {
		this->_grade -= i;
	}
}

void	Bureaucrat::operator-=(int const i)
{
	if((this->_grade + i) > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}else if (this->_grade + i < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else {
		this->_grade += i;
	}
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::signForm(Form &form)
{
	try{
		form.beSigned(*this);
		std::cout << "Bureaucrat " + this->getName() + " signs form " + form.getName() + "!" << std::endl;
	}
	catch(std::exception &ex)
	{
		std::cout << "Bureaucrat " + this->getName() + " cannot signs form " + form.getName() + "!" << std::endl << "Reason-> ";
		std::cout << ex.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const &form)
{
	try{
		form.execute(*this);
		std::cout << "Execution of " + form.getName() + " for " + form.getTarget() + " successful!" << std::endl;
	}
	catch(std::exception &ex)
	{
		std::cout << this->getName() + " cant execute " + form.getName() + "." << std::endl 
		<< "Reason: " << ex.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat(void)
{
	return ;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{
	return;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &tr)
{
	*this = tr;
	return ;
}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &bu)
{
	(void)bu;
	return *this;	
}

// WHAT

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exeption: grade too hight! Max grade 1.");
}

// WHAT

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{
	return;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &tr)
{
	*this = tr;
	return ;
}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &bu)
{
	(void)bu;
	return *this;	
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return ;
}

// WHAT

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exeption: grade too low! Min grade 150.");
}

// WHAT

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bu)
{
	out << bu.getName() + " grade: " << bu.getGrade();
	return (out);
}