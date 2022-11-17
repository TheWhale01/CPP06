#include "classes.hpp"

int main(void)
{
	srand(time(NULL));
	Base obj;
	Base *ptr = obj.generate();
	Base ref = *ptr;

	obj.identify(ptr);
	obj.identify(ref);
	delete ptr;
	return (0);
}