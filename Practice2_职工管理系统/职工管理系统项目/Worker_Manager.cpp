#include"Worker_Manager.h"


worker_manager::worker_manager()
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		this->m_number = 0;
		this->m_worker_array = NULL;
		this->m_is_file_empty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "系统中目前不存在职工信息" << endl;
		this->m_number = 0;
		this->m_worker_array = NULL;
		this->m_is_file_empty = true;
		ifs.close();
		return;
	}
	int num = this->get_file_num();
	this->m_number = num;  //更新成员属性 
	this->m_is_file_empty = false;
	this->m_worker_array = new worker *[this->m_number];
	//初始化职工
	this->initial_array();
}
void worker_manager::show_menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void worker_manager::exit_system()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void worker_manager::add_worker()
{
	cout << "请输入增加职工数量： " << endl;

	int add_num = 0;
	cin >> add_num;
	if (add_num > 0)
	{
		int new_num = this->m_number + add_num;
		worker **newspace = new worker *[new_num];
		if (this->m_worker_array != NULL)
		{
			for (int i = 0; i < this->m_number; i++)
			{
				newspace[i] = this->m_worker_array[i];
			}
		}
		for (int i = 0; i < add_num; i++)
		{
			int id;
			string name;
			int work_select;
			cout << "请输入第" << i + 1 << "个新员工的编号" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;

			cin >> work_select;
			worker *worker = NULL;
			switch (work_select)
			{
			case 1:
				worker = new employee(id, name, work_select);
				break;
			case 2: //经理
				worker = new manager(id, name, 2);
				break;
			case 3:  //老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newspace[this->m_number + i] = worker;

		}
		delete[] this->m_worker_array;
		this->m_worker_array = newspace;
		this->m_number = new_num;
		cout << "添加成功" << add_num << "名新职工" << endl;
		this->m_is_file_empty = false;

	}
	else
	{
		cout << "输入有误" << endl;
	}
	this->save_file();
	system("pause");
	system("cls");
}
void worker_manager::save_file()
{
	ofstream ofs;
	ofs.open(filename, ios::out);
	for (int i = 0; i < this->m_number; i++)
	{
		ofs << this->m_worker_array[i]->m_Id << " "
			<< this->m_worker_array[i]->m_Name << " "
			<< this->m_worker_array[i]->m_DepId << endl;
	}
	ofs.close();
}
int worker_manager::get_file_num()
{
	ifstream ifs;
	ifs.open(filename, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}
void worker_manager::show_worker()
{
	if (this->m_is_file_empty)
	{
		cout << "系统中不存在职工信息" << endl;
	}
	else
	{
		for (int i = 0; i < m_number; i++)
		{
			//利用多态调用接口
			this->m_worker_array[i]->show_inf();
		}
	}
	system("pause");
	system("cls");
}
void worker_manager:: initial_array()
{
	ifstream ifs;
	ifs.open(filename, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		worker * worker = NULL;
		//根据不同的部门Id创建不同对象
		if (dId == 1)  // 1普通员工
		{
			worker = new employee(id, name, dId);
		}
		else if (dId == 2) //2经理
		{
			worker = new manager(id, name, dId);
		}
		else //总裁
		{
			worker = new Boss(id, name, dId);
		}
		//存放在数组中
		this->m_worker_array[index] = worker;
		index++;
	}
}
int worker_manager::find_worker()
{
	int index = -1;
	if (this->m_is_file_empty)
	{
		cout << "系统中不存在职工信息" << endl;
	}
	else
	{
		cout << "请输入您想搜索的方式，1为按姓名查找，2为按编号查找" << endl;
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			cout << "请输入您想搜索的职工姓名" << endl;
			string worker_name;
			cin >> worker_name;
			for (int i = 0; i < m_number; i++)
			{
				if (m_worker_array[i]->m_Name == worker_name)
				{
					index = i;
					cout << "找到此人,此人信息为" << endl;
					m_worker_array[i]->show_inf();
					system("pause");
					system("cls");
					return index;
				}


			}
			cout << "未找到此人！" << endl;
			break;
		}
		case 2:
		{
			cout << "请输入您想搜索的职工编号" << endl;
			int worker_id;
			cin >> worker_id;
			for (int i = 0; i < m_number; i++)
			{
				if (m_worker_array[i]->m_Id == worker_id)
				{
					index = i;
					cout << "找到此人,此人信息为" << endl;
					m_worker_array[i]->show_inf();
					system("pause");
					system("cls");
					return index;
				}


			}
			cout << "未找到此人！" << endl;
			break;
		}

		default:
			break;
		}
		

	}
	system("pause");
	system("cls");
	return index;
}
void worker_manager::delete_worker()
{
	int index = find_worker();
	if (index != -1)
	{
		cout << "是否确定删除？1代表确定删除，0代表不删除" << endl;
		int if_dele;
		cin >> if_dele;
		if (if_dele == 1)
		{
			if (index = m_number)
			{
				m_worker_array[index] = NULL;
				m_number--;
				save_file();
				cout << "删除成功！" << endl;
			}
			else
			{
				for (int i = index; i < m_number - 1; i++)
				{
					m_worker_array[i] = m_worker_array[i + 1];
					m_number--;
				}
				save_file();
				cout << "删除成功！" << endl;
			}
			
		}
		system("pause");
		system("cls");
	}

}
void worker_manager::modify_worker()
{
	int index = find_worker();
	if (index != -1)
	{
		int newId;
		string newName;
		int dSelect;
		cout << "请输入新的员工编号" << endl;
		cin >> newId;
		cout << "请输入新的员工姓名：" << endl;
		cin >> newName;
		cout << "请选择新的员工岗位：" << endl;
		cout << "1、普通职工" << endl;
		cout << "2、经理" << endl;
		cout << "3、老板" << endl;

		cin >> dSelect;
		worker *worker = NULL;
		switch (dSelect)
		{
		case 1:
			worker = new employee(newId, newName, dSelect);
			break;
		case 2:
			worker = new manager(newId, newName, dSelect);
			break;
		case 3:
			worker = new Boss(newId, newName, dSelect);
			break;
		default:
			break;
		}
		this->m_worker_array[index] = worker;

		cout << "修改成功！" << endl;

		//保存到文件中
		this->save_file();
		system("pause");
		system("cls");
	}
	
}
void worker_manager::Sort_Emp()
{
	if (this->m_is_file_empty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < m_number; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_number; j++)
			{
				if (select == 1) //升序
				{
					if (m_worker_array[minOrMax]->m_Id > m_worker_array[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else  //降序
				{
					if (m_worker_array[minOrMax]->m_Id < m_worker_array[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				worker * temp = m_worker_array[i];
				m_worker_array[i] = m_worker_array[minOrMax];
				m_worker_array[minOrMax] = temp;
			}

		}

		cout << "排序成功,排序后结果为：" << endl;
		this->save_file();
		this->show_worker();
	}

}
void worker_manager::clean_file()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(filename, ios::trunc);
		ofs.close();

		if (this->m_number != NULL)
		{
			for (int i = 0; i < this->m_number; i++)
			{
				if (this->m_worker_array[i] != NULL)
				{
					delete this->m_worker_array[i];
				}
			}
			this->m_number = 0;
			delete[] this->m_worker_array;
			this->m_worker_array = NULL;
			this->m_is_file_empty = true;
		}
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}



worker_manager::~worker_manager()
{
	if (m_worker_array != NULL)
	{
		delete[] m_worker_array;
		m_worker_array = NULL;
	}
}