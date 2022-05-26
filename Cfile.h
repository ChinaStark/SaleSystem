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
	int id;			//商品id
	CString name;	//商品名
	int price;		//商品价格
	int num;		//商品个数
};

using namespace std;
class Cfile
{
public:
	//读取登陆信息
	void ReadLogin();

	//修改密码
	void WritePwd();
	// 读取商品数据
	void ReadDocline();
	//注册账号
	void resiger();
	//商品写入文件
	void WirteDocline();
	//销售额的写入
	void shop_m();
	//读取销售额
	void read();
	//修改销售额
	void mid();
	//添加新商品
	void Addline(CString name, int num, int price);
	list<msg> ls;	//存储商品容器
	int num;         //商品个数

	list<l_user> l_ls;
	int l_num;

	list<money> m;
	int num1;

	l_user a1;
};

