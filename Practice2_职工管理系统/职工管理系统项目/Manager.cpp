#include"Manager.h"

manager::manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

void manager::show_inf()
{
	cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->get_dep_name()
		<< " \t��λְ������ϰ彻��������,���·������Ա��" << endl;
}


string manager::get_dep_name()
{
	return string("����");
}
