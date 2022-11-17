#include "serial.hpp"

int main(void)
{
	Data data = {45};

	std::cout << deserialize(serialize(&data))->raw << std::endl;
	return (0);
}