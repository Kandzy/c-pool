#include <iostream>
#include "Data.hpp"
#include "unistd.h"

void 	*serialize(void)
{
	char	*serial = new char [20];
	char	set[] = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int i = 0;
	srand(clock());
	for (; i < 8; i++)
	{
		serial[i] = set[rand() % 62];
	}
	for (; i < 12; i++)
	{ 
		serial[i] = (rand() % 256 - 128);
	}
	for (; i < 20; i++) 
	{ 
		serial[i] = set[rand() % 62]; 
	}
	return (reinterpret_cast<void*>(serial));
}

Data 	*deserialize(void	*raw)
{
	Data *data = new Data;
	
	char *serial = reinterpret_cast<char*>(raw);
	data->n = 0;
	int i = 0;
	for (; i < 8; i++)
	{
		data->s1.push_back(serial[i]);
	}
	for (; i < 12; i++)
	{
		data->n ^= static_cast<unsigned char>(serial[i]);
		if (i != 11)
		{
			data->n <<= 8;
		}
	}
	for (; i < 20; i++) 
	{ 
		data->s2.push_back(serial[i]);
	}
	return data;
}

int	main()
{
	void* serialized;
	serialized = serialize();
	Data *d = deserialize(serialized);
	std::cout << d->s1 << std::endl << d->n << std::endl << d->s2 << std::endl;
	delete d;
	return (0);
}

// int	main()
// {
// 	void* serialized;
// 	serialized = serialize();
// 	Data *d = deserialize(serialized);
// 	int a = 0;
// 	int b = 0;
// 	int c = 0;
// 	int e = 0;
// 	int i = 0;
// 	while (++i < 1000000)
// 	{
// 		serialized = serialize();
// 		d = deserialize(serialized);
// 		// std::cout << d->s1 << std::endl << d->n << std::endl << d->s2 << std::endl;
// 		if (d->n > 1073741823)
// 		{
// 			a++;
// 		}
// 		if (d->n < 1073741823 && d->n > 0)
// 		{
// 			b++;
// 		}
// 		if (d->n > -1073741823 && d->n < 0)
// 		{
// 			c++;
// 		}
// 		if (d->n < -1073741823)
// 		{
// 			e++;
// 		}
// 	}
// 	std::cout << "a = " << a << " b = " << b << " c = " << c << " e = " << e << std::endl; 
// 	return (0); 
// }