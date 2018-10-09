#include "OfficeBlock.hpp"

/*
	Start Constructors
*/

OfficeBlock::OfficeBlock(void) : _intern(NULL), _signer(NULL), _executor(NULL)
{
	return;
}

OfficeBlock::OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executor) : _intern(&intern), _signer(&signer), _executor(&executor)
{
	return;
}

/*
	End Constructors
*/

/*
			Start getters setters
*/

Intern	*OfficeBlock::getIntern() const
{
	return this->_intern;
}

Bureaucrat	*OfficeBlock::getSigner() const
{
	return this->_signer;
}

Bureaucrat	*OfficeBlock::getExecutor() const
{
	return this->_executor;
}

void		OfficeBlock::setIntern(Intern &intern)
{
	this->_intern = &intern;
}

void		OfficeBlock::setSigner(Bureaucrat &signer)
{
	this->_signer = &signer;
}

void		OfficeBlock::setExecutor(Bureaucrat &executor)
{
	this->_executor = &executor;
}

/*
			End getters setters
*/

void		OfficeBlock::doBureaucracy(std::string const formName, std::string const target)
{
	time_t now = time(0);
	tm* localtm = localtime(&now);
	std::string data = asctime(localtm);

	if (!this->_intern)
	{
		throw OfficeBlock::NoInternExeption();
		return;
	}
	if (!this->_signer)
	{
		throw OfficeBlock::NoSignerExeption();
		return;
	}
	if (!this->_executor)
	{
		throw OfficeBlock::NoExecutorExeption();
		return;
	}

	std::cout << "Office ready to work!" << std::endl;

	Form *form = this->_intern->makeForm(formName, target);
	if (!form)
	{
		return ;
	}
	std::cout << *form << std::endl;

	if (this->_signer->getGrade() > form->getReqGrade())
	{
		delete form;
		throw OfficeBlock::SignerGradeTooLowExeption();
		return ;
	}

	std::cout << "Form can be signed!" << std::endl;

	form->beSigned(*this->_signer);

	std::cout << "Form was signed by " + this->_signer->getName() + " on " + data << std::endl;

	std::cout << *form << std::endl;

	if (this->_executor->getGrade() > form->getExeGrade())
	{
		delete form;
		throw OfficeBlock::ExecutorGradeTooLowExeption();
		return ;
	}

	std::cout << "Form can be executed!" << std::endl;

	form->execute(*this->_executor);

	std::cout << "Form was executed by " + this->_executor->getName() +" on " + data << std::endl;
	std::cout << "Good work guys!" << std::endl;
	delete form;
	return;
}

OfficeBlock::~OfficeBlock()
{
	return ;
}

/*
	No Intern Exeption
*/

OfficeBlock::NoInternExeption::NoInternExeption()
{
	return ;
}

OfficeBlock::NoInternExeption::NoInternExeption(NoInternExeption const &tr)
{
	*this = tr;
	return ;
}

OfficeBlock::NoInternExeption &OfficeBlock::NoInternExeption::operator=(NoInternExeption const &tr)
{
	(void)tr;
	return (*this);
}

const char*		OfficeBlock::NoInternExeption::what() const throw()
{
	return ("No Intern in OfficeBlock class.");
}

OfficeBlock::NoInternExeption::~NoInternExeption() throw()
{
	return ;
}

/*
	No Signer Exeption
*/

OfficeBlock::NoSignerExeption::NoSignerExeption()
{
	return ;
}

OfficeBlock::NoSignerExeption::NoSignerExeption(NoSignerExeption const &tr)
{
	*this = tr;
	return ;
}

OfficeBlock::NoSignerExeption &OfficeBlock::NoSignerExeption::operator=(NoSignerExeption const &tr)
{
	(void)tr;
	return (*this);
}

const char*		OfficeBlock::NoSignerExeption::what() const throw()
{
	return ("No Signer in OfficeBlock class.");
}

OfficeBlock::NoSignerExeption::~NoSignerExeption() throw()
{
	return ;
}

/*
	No Executor Exeption
*/

OfficeBlock::NoExecutorExeption::NoExecutorExeption()
{
	return ;
}

OfficeBlock::NoExecutorExeption::NoExecutorExeption(NoExecutorExeption const &tr)
{
	*this = tr;
	return ;
}

OfficeBlock::NoExecutorExeption &OfficeBlock::NoExecutorExeption::operator=(NoExecutorExeption const &tr)
{
	(void)tr;
	return (*this);
}

const char*		OfficeBlock::NoExecutorExeption::what() const throw()
{
	return ("No Executor in OfficeBlock class.");
}

OfficeBlock::NoExecutorExeption::~NoExecutorExeption() throw()
{
	return ;
}

/*
	Executor Low Grade Exeption
*/

OfficeBlock::ExecutorGradeTooLowExeption::ExecutorGradeTooLowExeption()
{
	return ;
}

OfficeBlock::ExecutorGradeTooLowExeption::ExecutorGradeTooLowExeption(ExecutorGradeTooLowExeption const &tr)
{
	*this = tr;
	return ;
}

OfficeBlock::ExecutorGradeTooLowExeption &OfficeBlock::ExecutorGradeTooLowExeption::operator=(ExecutorGradeTooLowExeption const &tr)
{
	(void)tr;
	return (*this);
}

const char*		OfficeBlock::ExecutorGradeTooLowExeption::what() const throw()
{
	return ("Executor grade is too low for this Form.");
}

OfficeBlock::ExecutorGradeTooLowExeption::~ExecutorGradeTooLowExeption() throw()
{
	return ;
}

/*
	Signer Low Grade Exeption
*/

OfficeBlock::SignerGradeTooLowExeption::SignerGradeTooLowExeption()
{
	return ;
}

OfficeBlock::SignerGradeTooLowExeption::SignerGradeTooLowExeption(SignerGradeTooLowExeption const &tr)
{
	*this = tr;
	return ;
}

OfficeBlock::SignerGradeTooLowExeption &OfficeBlock::SignerGradeTooLowExeption::operator=(SignerGradeTooLowExeption const &tr)
{
	(void)tr;
	return (*this);
}

const char*		OfficeBlock::SignerGradeTooLowExeption::what() const throw()
{
	return ("Signer grade is too low for this Form.");
}

OfficeBlock::SignerGradeTooLowExeption::~SignerGradeTooLowExeption() throw()
{
	return ;
}