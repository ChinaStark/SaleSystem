#pragma once
 
class person
{
public:
	CString name;//����
	int flag;//����
	int salary;//����
	virtual char* return_ID() = 0;
};

