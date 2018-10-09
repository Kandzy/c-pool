#include "Form.hpp"

Form::Form(void) : _name("Undefined"), _reqGrade(150), _exeGrade(150), _signed(false)
{
	return ;
}

Form::Form(std::string name, short int reqGrade, short int exeGrade) : _name(name), _reqGrade(reqGrade), _exeGrade(exeGrade), _signed(false)
{
	if(reqGrade > 150 || exeGrade > 150)
	{
		throw Form::GradeTooLowException();
	}
	else if (reqGrade < 1 || exeGrade < 1)
	{
		throw Form::GradeTooHighException();
	}
	return ;
}

Form::Form(Form const &bu) : _reqGrade(bu._reqGrade), _exeGrade(bu._exeGrade)
{
	*this = bu;
	return;
}


Form &Form::operator=(Form const &bu)
{
	if (this != &bu)
	{
		this->_signed = bu._signed;
	}
	return *this;	
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

int	Form::getReqGrade(void) const
{
	return (this->_reqGrade);
}

int	Form::getExeGrade(void) const
{
	return (this->_exeGrade);
}

bool Form::getSigned(void) const
{
	return (this->_signed);
}

void Form::beSigned(Bureaucrat const &bu)
{
	if (bu.getGrade() <= this->_reqGrade)
	{
		this->_signed = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

Form::~Form(void)
{
	return ;
}

Form::GradeTooHighException::GradeTooHighException(void)
{
	return;
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &tr)
{
	*this = tr;
	return ;
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(GradeTooHighException const &bu)
{
	(void)bu;
	return *this;	
}

// WHAT

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Exeption: Form grade too hight!.");
}

// WHAT

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return ;
}

Form::GradeTooLowException::GradeTooLowException(void)
{
	return;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &tr)
{
	*this = tr;
	return ;
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(GradeTooLowException const &bu)
{
	(void)bu;
	return *this;	
}

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return ;
}

// WHAT

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Exeption: grade too low!");
}

// WHAT

std::ostream &operator<<(std::ostream &out, Form const &bu)
{
	out << "Form " + bu.getName() + " required grade: " << bu.getReqGrade() << "execution grade: " << bu.getExeGrade();
	return (out);
}