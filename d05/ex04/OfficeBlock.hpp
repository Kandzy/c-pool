#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include "Bureaucrat.hpp"
#include "Intern.hpp"

class OfficeBlock
{
	public:
							OfficeBlock(void);
							OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executor);
		virtual				~OfficeBlock();

		void				doBureaucracy(std::string const formName, std::string const target);
		void				setIntern(Intern &obj);
		void				setSigner(Bureaucrat &obj);
		void				setExecutor(Bureaucrat &obj);
		Intern				*getIntern();
		Bureaucrat			*getSigner();
		Bureaucrat			*getExecutor();

		class NoInternExeption : public std::exception
		{
			public:
										NoInternExeption();
										NoInternExeption(NoInternExeption const & tr);
										NoInternExeption &operator=(NoInternExeption const &tr);
				virtual					~NoInternExeption() throw();
				virtual const char*		what() const throw();
		};

		class NoSignerExeption : public std::exception
		{
			public:
										NoSignerExeption();
										NoSignerExeption(NoSignerExeption const & tr);
										NoSignerExeption &operator=(NoSignerExeption const &tr);
				virtual					~NoSignerExeption() throw();
				virtual const char*		what() const throw();
		};

		class NoExecutorExeption : public std::exception
		{
			public:
										NoExecutorExeption();
										NoExecutorExeption(NoExecutorExeption const & tr);
										NoExecutorExeption &operator=(NoExecutorExeption const &tr);
				virtual					~NoExecutorExeption() throw();
				virtual const char*		what() const throw();
		};

		class ExecutorGradeTooLowExeption : public std::exception
		{
			public:
										ExecutorGradeTooLowExeption();
										ExecutorGradeTooLowExeption(ExecutorGradeTooLowExeption const & tr);
										ExecutorGradeTooLowExeption &operator=(ExecutorGradeTooLowExeption const &tr);
				virtual					~ExecutorGradeTooLowExeption() throw();
				virtual const char*		what() const throw();
		};

		class SignerGradeTooLowExeption : public std::exception
		{
			public:
										SignerGradeTooLowExeption();
										SignerGradeTooLowExeption(SignerGradeTooLowExeption const & tr);
										SignerGradeTooLowExeption &operator=(SignerGradeTooLowExeption const &tr);
				virtual					~SignerGradeTooLowExeption() throw();
				virtual const char*		what() const throw();
		};

	private:
		Intern				*_intern;
		Bureaucrat			*_signer;
		Bureaucrat			*_executor;
};

#endif