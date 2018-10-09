#include "Form.hpp"

Form::Form(void) : _name("Undefined"), _reqGrade(150), _exeGrade(150), _signed(false)
{
	return ;
}

Form::Form(std::string target, std::string name, short int reqGrade, short int exeGrade) : _name(name), _reqGrade(reqGrade), _exeGrade(exeGrade), _signed(false), _target(target)
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

std::string	Form::getTarget() const
{
	return (this->_target);
}

Form::~Form(void)
{
	return ;
}

//TO HIGHT EXEPTION

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

// end WHAT

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return ;
}

// TOO LOW EXEPTION

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

// end WHAT

// SignedExeption

Form::UnsignedExeprion::UnsignedExeprion(void)
{
	return;
}

Form::UnsignedExeprion::UnsignedExeprion(UnsignedExeprion const &se)
{
	*this = se;
	return ;
}

Form::UnsignedExeprion &Form::UnsignedExeprion::operator=(UnsignedExeprion const &se)
{
	(void)se;
	return *this;	
}

Form::UnsignedExeprion::~UnsignedExeprion(void) throw()
{
	return ;
}

// WHAT

const char* Form::UnsignedExeprion::what() const throw()
{
	return ("Exeption: form not signed!");
}

// end WHAT

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << form.getName()+":" << std::endl
	<< "				Target:" + form.getTarget() << std::endl
	<< "				Sign grade required: " << form.getReqGrade() << std::endl
	<< "				Execution grade required: " << form.getExeGrade() << std::endl
	<< "				Status: " << (form.getSigned() ? "True" : "False") << std::endl;
	return (out);
}