#pragma once
 
class person
{
public:
	CString name;//名字
	int flag;//类型
	int salary;//工资
	virtual char* return_ID() = 0;
};

