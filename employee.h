#pragma once
#include "person.h"
class employee:  virtual public person
{
public:
	int sale;//���۶�
	virtual char* return_ID()
	{

		return "����Ա��";
	}
	friend double operator*(const employee& c1, double v);
};



