#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("UNDEFINED", "Robotomy Request Form", 72, 45)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, "Robotomy Request Form", 72, 45)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rrf) : Form(rrf.getTarget(), "Robotomy Request Form", 72, 45)
{
	*this = rrf;
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rrf)
{
	(void)rrf;
	return *this;
}

void					RobotomyRequestForm::execute(Bureaucrat const &bu) const
{
	srand(time(0));
	if ((this->getSigned()) && (bu.getGrade() <= this->getExeGrade()))
	{
		if (rand() % 2)
		{
			std::cout << "Robotomy: Successful!" << std::endl;
		}
		else
		{
			std::cout << "Robotomy: Failture!" << std::endl;
		}
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

std::ostream			&operator<<(std::ostream &out, RobotomyRequestForm const &rrf)
{
	out << rrf.getName()+":" << std::endl
	<< "				Target:" + rrf.getTarget() << std::endl
	<< "				Sign grade required: " << rrf.getReqGrade() << std::endl
	<< "				Execution grade required: " << rrf.getExeGrade() << std::endl
	<< "				Status: " << (rrf.getSigned() ? "True" : "False") << std::endl;
	return (out);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return;
}
