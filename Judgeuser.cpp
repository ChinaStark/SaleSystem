
#include "strafx.h"
#include"Judgeuser.h"
#include "pch.h"

int flag = 0;
CString cstr_name;
void set_judge(int num, CString name)
{
	
	if (num == 1)//№ЬАн
	{
		flag = 1;
	}
	else
		flag = 2;
	cstr_name = name;
}
int out_judge()
{
	return flag;
}

CString out_cstr_name()
{
	return cstr_name;
}