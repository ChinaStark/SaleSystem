#include "pch.h"
#include "Cfile.h"
#include "SalaSystem.h"
#pragma warning(disable:4996)
//��ȡ��½��Ϣ
void Cfile::ReadLogin()
{
	ifstream ifs("./name_data.txt", ios::in);
	char buf[1024] = { 0 };
	l_num = 0;	//��ʼ���û���ĿΪ0
	l_ls.clear();
	//ȡ����ͷ

	while (!ifs.eof()) //û���ļ���β
	{
		l_user l_tmp;

		ifs.getline(buf, sizeof(buf)); //��ȡһ��
		l_num++;	//�û���Ŀ��һ

		//AfxMessageBox(CString(buf));
		char* sst = strtok(buf, "|"); //�ԡ�|���и�
		if (sst != NULL)
		{
			l_tmp.id = atoi(sst); //��Ʒ�û����
		}
		else
		{
			break;
		}

		sst = strtok(NULL, "|");
		l_tmp.name = sst;	//�û���

		sst = strtok(NULL, "|");
		l_tmp.l_pwd = sst;	//�û�����

		sst = strtok(NULL, "|");
		l_tmp.control = atoi(sst);	//�û�Ȩ��

		l_ls.push_back(l_tmp); //��������ĺ���
	}

	ifs.close(); //�ر��ļ�
}

//�޸�����
void Cfile::WritePwd()
{
	ofstream ofs;	//�����ļ��������
	ofs.open("./name_data.txt"); //���ļ�
	if (l_ls.size() > 0)	//��Ʒ���������ݲ�ִ��
	{

		CString d;
		//ͨ��������ȡ���������ݣ�д���ļ�����"|"�ָ��β�ӻ���
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
	
	

	ofs.close();	//�ر��ļ�
}
//ע���˺�
void Cfile::resiger()
{
	ofstream ofs;	//�����ļ��������
	ofs.open("./name_data.txt",ios::app); //���ļ�
		//�û����������ݲ�ִ��
	
		//ofs << "�û�ID|�û���|����|Ȩ��" << endl; //д���ͷ

		//ͨ��������ȡ���������ݣ�д���ļ����ԡ�|���ָ�����β�ӻ���
		
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
		
	

	ofs.close();//�ر��ļ�
	Cfile::shop_m();
}

// ��ȡ��Ʒ����
void Cfile::ReadDocline()
{
	ls.clear();//ȡ����ͷ
	char p[1024];
	num = 0;
	ifstream in_data("./shop_data.txt", ios::in);
	
	in_data.seekg(0, ios::beg);
	in_data.getline(p, sizeof(p));
	//int i = 1;
	while (!(in_data.eof()))	//û���ļ���β
	{
		
		num++;	//��Ʒ������һ
		msg tmp;
		in_data.getline(p, sizeof(p));
		//AfxMessageBox(CString(buf));
		char* sst = strtok(p, "|");	//��"|"�ָ�
		if (sst != NULL)
		{
			tmp.id = atoi(sst);	//��Ʒid
		}

		else
		{
			break;
		}

		sst = strtok(NULL, "|");
		tmp.name = sst;	//��Ʒ����

		sst = strtok(NULL, "|");
		tmp.price = atoi(sst);	//��Ʒ�۸�

		sst = strtok(NULL, "|");
		tmp.num = atoi(sst);	//��Ʒ��Ŀ

		ls.push_back(tmp);	//��������ĺ���
		
	}
	//exit(0);
	in_data.close();	//�ر��ļ�
	
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
//��Ʒд���ļ�
void Cfile::WirteDocline()
{
	ofstream out_data("./shop_data.txt", ios::out);
	out_data.seekp(0, ios::beg);
	string T = "��ƷID|��Ʒ��|����|���";
	out_data << T << endl;
	if (ls.size() > 0)	//��Ʒ���������ݲ�ִ��
	{
		
		CString d;
		//ͨ��������ȡ���������ݣ�д���ļ�����"|"�ָ��β�ӻ���
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

//�������Ʒ
void Cfile::Addline(CString name, int num, int price)
{
	msg tmp;



	//��Ʒ���ƣ���棬�۸���Ч
	if (!name.IsEmpty() && num > 0 && price > 0)
	{
		tmp.id = ls.size() + 1;	//id�Զ���1
						
		tmp.name = name;
		tmp.num = num;			//���
		tmp.price = price;		//�۸�

		ls.push_back(tmp);			//��������ĺ���
	}

}
void Cfile::mid()
{
	int i = 1;
	ofstream ofs;	//�����ļ��������
	ofs.open("./shop.txt"); //���ļ�
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
//���۶�
void Cfile::shop_m()
{
	ofstream ofs;	//�����ļ��������
	ofs.open("./shop.txt", ios::app); //���ļ�
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
	while(!(ifs.eof()))	//û���ļ���β
	{
		money tmp;

		ifs.getline(buf, sizeof(buf));	//��ȡһ��
		num1++;	//��Ʒ������һ
		
		//AfxMessageBox(CString(buf));
		char *sst = strtok(buf, "|");	//��"|"�ָ�
		tmp.name = sst;
		
		sst = strtok(NULL, "|");
		
		tmp.money_s = atoi(sst);	//��Ʒ����

		
		m.push_back(tmp);	//��������ĺ���
	}
	
	ifs.close();	//�ر��ļ�
}