#include "Boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

void Boss::show_inf()
{
	cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->get_dep_name()
		<< " \t��λְ�𣺹���˾��������" << endl;
}


string Boss::get_dep_name()
{
	return string("�ϰ�");
}