#pragma once
#include <list>
#include <iostream>
#include <fstream>
struct money
{
	CString name;
	int money_s;
};
struct l_user
{
	int id;				
	CString name;	
	CString l_pwd;			
	int control;
	int mon;
};
struct msg
{
	int id;			//��Ʒid
	CString name;	//��Ʒ��
	int price;		//��Ʒ�۸�
	int num;		//��Ʒ����
};

using namespace std;
class Cfile
{
public:
	//��ȡ��½��Ϣ
	void ReadLogin();

	//�޸�����
	void WritePwd();
	// ��ȡ��Ʒ����
	void ReadDocline();
	//ע���˺�
	void resiger();
	//��Ʒд���ļ�
	void WirteDocline();
	//���۶��д��
	void shop_m();
	//��ȡ���۶�
	void read();
	//�޸����۶�
	void mid();
	//�������Ʒ
	void Addline(CString name, int num, int price);
	list<msg> ls;	//�洢��Ʒ����
	int num;         //��Ʒ����

	list<l_user> l_ls;
	int l_num;

	list<money> m;
	int num1;

	l_user a1;
};

