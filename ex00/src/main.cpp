#include "conversion.hpp"

int main(int ac, char **av)
{
	std::string nb;

	if (ac == 1)
	{
		std::cerr << av[0] << " requires at least one argument" << std::endl;
		return (0);
	}
	nb = av[1];
	printChar(nb);
	printInt(nb);
	printFloat(nb);
	printDouble(nb);
	return (0);
}