#include "Employee.h"

employee::employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

void employee::show_inf()
{
	cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->get_dep_name()
		<< " \t��λְ����ɾ�����������" << endl;
}


string employee::get_dep_name()
{
	return string("Ա��");
}
