#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("UNDEFINED", "Presidential Pardon Form", 25, 5)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, "Presidential Pardon Form", 25, 5)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ppf) : Form(ppf.getTarget(), "Presidential Pardon Form", 25, 5)
{
	*this = ppf;
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &ppf)
{
	(void)ppf;
	return *this;
}

void					PresidentialPardonForm::execute(Bureaucrat const &bu) const
{
	if ((this->getSigned()) && (bu.getGrade() <= this->getExeGrade()))
	{
		std::cout << this->getTarget() + " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
	else if (!this->getSigned())
	{
		throw Form::UnsignedExeprion();
	}
	else
	{
		throw Form::GradeTooLowException();
	}
	return;
}

std::ostream			&operator<<(std::ostream &out, PresidentialPardonForm const &ppf)
{
	out << ppf.getName()+":" << std::endl
	<< "				Target:" + ppf.getTarget() << std::endl
	<< "				Sign grade required: " << ppf.getReqGrade() << std::endl
	<< "				Execution grade required: " << ppf.getExeGrade() << std::endl
	<< "				Status: " << (ppf.getSigned() ? "True" : "False") << std::endl;
	return (out);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return;
}
