#pragma once
#include "person.h"
class employee:  virtual public person
{
public:
	int sale;//销售额
	virtual char* return_ID()
	{

		return "销售员工";
	}
	friend double operator*(const employee& c1, double v);
};



