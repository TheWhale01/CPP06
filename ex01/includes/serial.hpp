#pragma once
#include <stdint.h>
#include <iostream>

typedef struct 
{
	public:
		int raw;
} Data;

Data *deserialize(uintptr_t raw);

uintptr_t serialize(Data *ptr);