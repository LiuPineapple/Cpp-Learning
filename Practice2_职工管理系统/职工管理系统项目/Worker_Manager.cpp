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
		//cout << "ϵͳ��Ŀǰ������ְ����Ϣ" << endl;
		this->m_number = 0;
		this->m_worker_array = NULL;
		this->m_is_file_empty = true;
		ifs.close();
		return;
	}
	int num = this->get_file_num();
	this->m_number = num;  //���³�Ա���� 
	this->m_is_file_empty = false;
	this->m_worker_array = new worker *[this->m_number];
	//��ʼ��ְ��
	this->initial_array();
}
void worker_manager::show_menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void worker_manager::exit_system()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void worker_manager::add_worker()
{
	cout << "����������ְ�������� " << endl;

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
			cout << "�������" << i + 1 << "����Ա���ı��" << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;

			cin >> work_select;
			worker *worker = NULL;
			switch (work_select)
			{
			case 1:
				worker = new employee(id, name, work_select);
				break;
			case 2: //����
				worker = new manager(id, name, 2);
				break;
			case 3:  //�ϰ�
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
		cout << "��ӳɹ�" << add_num << "����ְ��" << endl;
		this->m_is_file_empty = false;

	}
	else
	{
		cout << "��������" << endl;
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
		//��¼����
		num++;
	}
	ifs.close();

	return num;
}
void worker_manager::show_worker()
{
	if (this->m_is_file_empty)
	{
		cout << "ϵͳ�в�����ְ����Ϣ" << endl;
	}
	else
	{
		for (int i = 0; i < m_number; i++)
		{
			//���ö�̬���ýӿ�
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
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		if (dId == 1)  // 1��ͨԱ��
		{
			worker = new employee(id, name, dId);
		}
		else if (dId == 2) //2����
		{
			worker = new manager(id, name, dId);
		}
		else //�ܲ�
		{
			worker = new Boss(id, name, dId);
		}
		//�����������
		this->m_worker_array[index] = worker;
		index++;
	}
}
int worker_manager::find_worker()
{
	int index = -1;
	if (this->m_is_file_empty)
	{
		cout << "ϵͳ�в�����ְ����Ϣ" << endl;
	}
	else
	{
		cout << "���������������ķ�ʽ��1Ϊ���������ң�2Ϊ����Ų���" << endl;
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			cout << "����������������ְ������" << endl;
			string worker_name;
			cin >> worker_name;
			for (int i = 0; i < m_number; i++)
			{
				if (m_worker_array[i]->m_Name == worker_name)
				{
					index = i;
					cout << "�ҵ�����,������ϢΪ" << endl;
					m_worker_array[i]->show_inf();
					system("pause");
					system("cls");
					return index;
				}


			}
			cout << "δ�ҵ����ˣ�" << endl;
			break;
		}
		case 2:
		{
			cout << "����������������ְ�����" << endl;
			int worker_id;
			cin >> worker_id;
			for (int i = 0; i < m_number; i++)
			{
				if (m_worker_array[i]->m_Id == worker_id)
				{
					index = i;
					cout << "�ҵ�����,������ϢΪ" << endl;
					m_worker_array[i]->show_inf();
					system("pause");
					system("cls");
					return index;
				}


			}
			cout << "δ�ҵ����ˣ�" << endl;
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
		cout << "�Ƿ�ȷ��ɾ����1����ȷ��ɾ����0����ɾ��" << endl;
		int if_dele;
		cin >> if_dele;
		if (if_dele == 1)
		{
			if (index = m_number)
			{
				m_worker_array[index] = NULL;
				m_number--;
				save_file();
				cout << "ɾ���ɹ���" << endl;
			}
			else
			{
				for (int i = index; i < m_number - 1; i++)
				{
					m_worker_array[i] = m_worker_array[i + 1];
					m_number--;
				}
				save_file();
				cout << "ɾ���ɹ���" << endl;
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
		cout << "�������µ�Ա�����" << endl;
		cin >> newId;
		cout << "�������µ�Ա��������" << endl;
		cin >> newName;
		cout << "��ѡ���µ�Ա����λ��" << endl;
		cout << "1����ְͨ��" << endl;
		cout << "2������" << endl;
		cout << "3���ϰ�" << endl;

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

		cout << "�޸ĳɹ���" << endl;

		//���浽�ļ���
		this->save_file();
		system("pause");
		system("cls");
	}
	
}
void worker_manager::Sort_Emp()
{
	if (this->m_is_file_empty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < m_number; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_number; j++)
			{
				if (select == 1) //����
				{
					if (m_worker_array[minOrMax]->m_Id > m_worker_array[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else  //����
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

		cout << "����ɹ�,�������Ϊ��" << endl;
		this->save_file();
		this->show_worker();
	}

}
void worker_manager::clean_file()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
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
		cout << "��ճɹ���" << endl;
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