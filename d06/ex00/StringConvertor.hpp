#ifndef STRINGCONVERTOR_HPP
#define STRINGCONVERTOR_HPP

#include <iostream>
#include <string>

class StringConvertor{
	public:
								StringConvertor(void);
								StringConvertor(StringConvertor const & sc);
								StringConvertor(std::string value);
								StringConvertor &operator=(StringConvertor const &sc);
		virtual					~StringConvertor(void);

		std::string				getStringValue(void) const;
		void					setStringValue(std::string value);

								operator char(void) const;
								operator int(void) const;
								operator double(void) const;
								operator float(void) const;

		class StringConversionExeption : public std::exception
		{
			public:
				
									StringConversionExeption(void);
									StringConversionExeption(StringConversionExeption const &sce);
									StringConversionExeption &operator=(StringConversionExeption const &sce);
				virtual 			~StringConversionExeption(void) throw();
				
				virtual const char*	what() const throw();
		};
	
	private:
		std::string				_strVal;
};

#endif