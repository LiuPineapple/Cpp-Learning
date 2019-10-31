#include"Manager.h"

manager::manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

void manager::show_inf()
{
	cout << "职工编号： " << this->m_Id
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->get_dep_name()
		<< " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;
}


string manager::get_dep_name()
{
	return string("经理");
}
