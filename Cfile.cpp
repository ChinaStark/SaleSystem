#include "pch.h"
#include "Cfile.h"
#include "SalaSystem.h"
#pragma warning(disable:4996)
//读取登陆信息
void Cfile::ReadLogin()
{
	ifstream ifs("./name_data.txt", ios::in);
	char buf[1024] = { 0 };
	l_num = 0;	//初始化用户数目为0
	l_ls.clear();
	//取出表头

	while (!ifs.eof()) //没到文件结尾
	{
		l_user l_tmp;

		ifs.getline(buf, sizeof(buf)); //读取一行
		l_num++;	//用户数目加一

		//AfxMessageBox(CString(buf));
		char* sst = strtok(buf, "|"); //以“|”切割
		if (sst != NULL)
		{
			l_tmp.id = atoi(sst); //商品用户编号
		}
		else
		{
			break;
		}

		sst = strtok(NULL, "|");
		l_tmp.name = sst;	//用户名

		sst = strtok(NULL, "|");
		l_tmp.l_pwd = sst;	//用户密码

		sst = strtok(NULL, "|");
		l_tmp.control = atoi(sst);	//用户权限

		l_ls.push_back(l_tmp); //放在链表的后面
	}

	ifs.close(); //关闭文件
}

//修改密码
void Cfile::WritePwd()
{
	ofstream ofs;	//创建文件输出对象
	ofs.open("./name_data.txt"); //打开文件
	if (l_ls.size() > 0)	//商品链表有内容才执行
	{

		CString d;
		//通过迭代器取出链表内容，写入文件，以"|"分割，结尾加换行
		for (list<l_user>::iterator it = l_ls.begin(); it != l_ls.end(); it++)
		{
			CStringA f;
			f = it->name;
			const char* p = (char*)f.GetBuffer(0);
			CStringA F;
			F = it->l_pwd;
			const char* g = (char*)F.GetBuffer(0);
			ofs << it->id << "|";
			ofs << f;
			ofs << "|";
			ofs << g;
			ofs << "|";
			ofs << it->control << endl;
		}
	}
	
	

	ofs.close();	//关闭文件
}
//注册账号
void Cfile::resiger()
{
	ofstream ofs;	//创建文件输出对象
	ofs.open("./name_data.txt",ios::app); //打开文件
		//用户链表有内容才执行
	
		//ofs << "用户ID|用户名|密码|权限" << endl; //写入表头

		//通过迭代器取出链表内容，写入文件，以“|”分隔，结尾加换行
		
	CStringA f;
	f = a1.name;
	const char* p = (char*)f.GetBuffer(0);
	CStringA F;
	F = a1.l_pwd;
	const char* g = (char*)F.GetBuffer(0);
	ofs << a1.id << "|";
	ofs << p;
	ofs <<"|";
	ofs << g;
	ofs<< "|";
	ofs << a1.control << endl;
		
	

	ofs.close();//关闭文件
	Cfile::shop_m();
}

// 读取商品数据
void Cfile::ReadDocline()
{
	ls.clear();//取出表头
	char p[1024];
	num = 0;
	ifstream in_data("./shop_data.txt", ios::in);
	
	in_data.seekg(0, ios::beg);
	in_data.getline(p, sizeof(p));
	//int i = 1;
	while (!(in_data.eof()))	//没到文件结尾
	{
		
		num++;	//商品数量加一
		msg tmp;
		in_data.getline(p, sizeof(p));
		//AfxMessageBox(CString(buf));
		char* sst = strtok(p, "|");	//以"|"分隔
		if (sst != NULL)
		{
			tmp.id = atoi(sst);	//商品id
		}

		else
		{
			break;
		}

		sst = strtok(NULL, "|");
		tmp.name = sst;	//商品名称

		sst = strtok(NULL, "|");
		tmp.price = atoi(sst);	//商品价格

		sst = strtok(NULL, "|");
		tmp.num = atoi(sst);	//商品数目

		ls.push_back(tmp);	//放在链表的后面
		
	}
	//exit(0);
	in_data.close();	//关闭文件
	
}

string CString2string(CString csStrData)
{
	string strRet;

	char ss[2048];
	memset(ss, 0, sizeof(char) * 2048);
	sprintf(ss, "%s", csStrData);

	strRet = ss;
	return strRet;
}
//商品写入文件
void Cfile::WirteDocline()
{
	ofstream out_data("./shop_data.txt", ios::out);
	out_data.seekp(0, ios::beg);
	string T = "商品ID|商品名|单价|库存";
	out_data << T << endl;
	if (ls.size() > 0)	//商品链表有内容才执行
	{
		
		CString d;
		//通过迭代器取出链表内容，写入文件，以"|"分割，结尾加换行
		for (list<msg>::iterator it = ls.begin(); it != ls.end(); it++)
		{
			CStringA f;
			f = it->name;
			const char *p = (char*)f.GetBuffer(0);
			
			out_data << it->id<<"|";
			out_data << p;
			out_data << "|";
			out_data << it->price << "|";
			out_data << it->num << endl;
		}
	}
	out_data.close();
}

//添加新商品
void Cfile::Addline(CString name, int num, int price)
{
	msg tmp;



	//商品名称，库存，价格有效
	if (!name.IsEmpty() && num > 0 && price > 0)
	{
		tmp.id = ls.size() + 1;	//id自动加1
						
		tmp.name = name;
		tmp.num = num;			//库存
		tmp.price = price;		//价格

		ls.push_back(tmp);			//放在链表的后面
	}

}
void Cfile::mid()
{
	int i = 1;
	ofstream ofs;	//创建文件输出对象
	ofs.open("./shop.txt"); //打开文件
	for (list<money>::iterator it = m.begin(); it != m.end(); it++)
	{
		if (i > 1)
		{
			ofs << "\n";
		}
		CStringA f;
		f = it->name;
		const char* p = (char*)f.GetBuffer(0);
		
		ofs << p;
		ofs << "|";
		ofs << it->money_s ;
		i++;
	}
}
//销售额
void Cfile::shop_m()
{
	ofstream ofs;	//创建文件输出对象
	ofs.open("./shop.txt", ios::app); //打开文件
	CStringA f;
	f = a1.name;
	const char* p = (char*)f.GetBuffer(0);
	ofs << "\n";
	ofs << p;
	ofs << "|";
	ofs << 0;
}

void Cfile::read()
{
	
	ifstream ifs("./shop.txt", ios::in);
	num1 = 0;
	m.clear();
	char buf[1024] = { 0 };
	while(!(ifs.eof()))	//没到文件结尾
	{
		money tmp;

		ifs.getline(buf, sizeof(buf));	//读取一行
		num1++;	//商品数量加一
		
		//AfxMessageBox(CString(buf));
		char *sst = strtok(buf, "|");	//以"|"分隔
		tmp.name = sst;
		
		sst = strtok(NULL, "|");
		
		tmp.money_s = atoi(sst);	//商品名称

		
		m.push_back(tmp);	//放在链表的后面
	}
	
	ifs.close();	//关闭文件
}