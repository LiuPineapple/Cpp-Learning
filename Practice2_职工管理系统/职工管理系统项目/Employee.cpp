#include "Employee.h"

employee::employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

void employee::show_inf()
{
	cout << "职工编号： " << this->m_Id
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->get_dep_name()
		<< " \t岗位职责：完成经理交给的任务" << endl;
}


string employee::get_dep_name()
{
	return string("员工");
}
