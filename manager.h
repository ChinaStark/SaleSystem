#pragma once
#include "person.h"
class manager :virtual public person
{
public:
	virtual char* return_ID()
	{

		return "管理员";
	}
	int win;//奖金
};

 