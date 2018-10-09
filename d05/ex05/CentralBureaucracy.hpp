#ifndef CENTRALBUREAUCRACY_HPP
#define CENTRALBUREAUCRACY_HPP

#define	OFFICES 20
#define	QUEUE 80

#include	<sys/time.h>
#include	<unistd.h>

#include "OfficeBlock.hpp"

class CentralBureaucracy{
	public:
							CentralBureaucracy(void);
							CentralBureaucracy(CentralBureaucracy const & cb);
							CentralBureaucracy &operator=(CentralBureaucracy const &cb);
		virtual				~CentralBureaucracy(void);

		void				feedSigner(Bureaucrat &signer);
		void				feedExecutor(Bureaucrat &executor);
		void				queueUp(std::string name);
		void				doBureaucracy(void);
	private:
		OfficeBlock			_office[OFFICES];
		std::string			_queue[QUEUE];
};

#endif