#include<iostream>
#include<string>

using namespace std;

const int max = 1000;
//�����ϵ�˽ṹ��
struct Person
{
	string m_Name;
	string m_Sex;
	string m_Age;
	string m_Phone;
	string m_Address;
};
//���ͨѶ¼�ṹ��
struct Addressbooks
{
	Person personArray[max];
	//��¼ͨѶ¼�е���Ա����
	int m_Size;
};

void show_menu();
void add_person(Addressbooks * adb);
void show_addressbooks(Addressbooks * adb);
int is_person_exist(Addressbooks * adb, string name);
void delete_person(Addressbooks * adb, int det);
void modify_person(Addressbooks * adb);
void clean_person(Addressbooks * adb);

int main()
{
	//�����ṹ�����
	Addressbooks adb;
	adb.m_Size = 0;

	int select = 0;
	//�˵�����
	while (true)
	{
		show_menu();
		cout << "��ѡ��Ҫ���еĲ���" << endl;
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			add_person(&adb);
			break;
		case 2://��ʾ��ϵ��
			show_addressbooks(&adb);
			break;
		case 3://ɾ����ϵ��
		{
			string name;
			cout << "������Ҫɾ������ϵ������" << endl;
			cin >> name;
			int det = is_person_exist(&adb, name);
			if (det == -1)
			{
				cout << "���޴���!" << endl;
			}
			else
			{
				cout << "�ҵ�����" << endl;
				delete_person(&adb, det);
				cout << "ɾ���ɹ�" << endl;
			}
			system("pause");
			system("cls");
		}
		break;
		case 4://������ϵ��
		{
			string name;
			cout << "������Ҫ���ҵ���ϵ������" << endl;
			cin >> name;
			int det = is_person_exist(&adb, name);
			if (det == -1)
			{
				cout << "���޴���!" << endl;
			}
			else
			{
				cout << "�ҵ�����!" << endl;
				cout << "����:\t�Ա�:\t����:\t�绰:\t\tסַ:\t" << endl;
				{
					cout << adb.personArray[det].m_Name << "\t";
					cout << adb.personArray[det].m_Sex << "\t";
					cout << adb.personArray[det].m_Age << "\t";
					cout << adb.personArray[det].m_Phone << "\t\t";
					cout << adb.personArray[det].m_Address << "\t" << endl;
				}
			}
			system("pause");
			system("cls");
		}
		break;
		case 5:
			modify_person(&adb);
			break;
		case 6:
			clean_person(&adb);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		default:
			cout << "��������ʵ�����" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}

//������ֺ���
void show_menu()//��ʾ�˵�
{
	cout << "*********************" << endl;
	cout << "*** 1�������ϵ�� ***" << endl;
	cout << "*** 2����ʾ��ϵ�� ***" << endl;
	cout << "*** 3��ɾ����ϵ�� ***" << endl;
	cout << "*** 4��������ϵ�� ***" << endl;
	cout << "*** 5���޸���ϵ�� ***" << endl;
	cout << "*** 6�������ϵ�� ***" << endl;
	cout << "*** 0���˳�ͨѶ¼ ***" << endl;
	cout << "*********************" << endl;
}


void add_person(Addressbooks *adb)//����1�������ϵ��
{
	if (adb->m_Size == max)
	{
		cout << "ͨѶ¼�������޷����" << endl;

	}
	else
	{
		//��������
		string name;
		cout << "����������" << endl;
		cin >> name;
		adb->personArray[adb->m_Size].m_Name = name;
		//�Ա�
		int sexx = 0;
	Flag:
		cout << "�������Ա�1 �����У�0 ����Ů" << endl;
		cin >> sexx;
		if (sexx == 1)
		{
			adb->personArray[adb->m_Size].m_Sex = "��";
		}
		else if (sexx == 0)
		{
			adb->personArray[adb->m_Size].m_Sex = "Ů";
		}
		else
		{
			cout << "������������������" << endl;
			goto Flag;
		}
		string age;
		cout << "����������" << endl;
		cin >> age;
		adb->personArray[adb->m_Size].m_Age = age;
		string number;
		cout << "��������ϵ�绰" << endl;
		cin >> number;
		adb->personArray[adb->m_Size].m_Phone = number;
		string address;
		cout << "�������ͥ��ַ" << endl;
		cin >> address;
		adb->personArray[adb->m_Size].m_Address = address;
		adb->m_Size++;
		cout << "*******" << endl;
		cout << "��ӳɹ���" << endl;
		cout << "*******" << endl;
		cout << endl;
		system("pause");
		system("cls");
	}
}

void show_addressbooks(Addressbooks * adb)//����2����ʾ��ϵ��
{
	if (adb->m_Size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		cout << "����:\t�Ա�:\t����:\t�绰:\t\tסַ:\t" << endl;
		for (int i = 0; i < adb->m_Size; i++)
		{
			cout << adb->personArray[i].m_Name << "\t";
			cout << adb->personArray[i].m_Sex << "\t";
			cout << adb->personArray[i].m_Age << "\t";
			cout << adb->personArray[i].m_Phone << "\t\t";
			cout << adb->personArray[i].m_Address << "\t" << endl;
		}
	}
	system("pause");
	system("cls");
}

int is_person_exist(Addressbooks * adb, string name)//��������Ƿ����
{
	for (int i = 0; i < adb->m_Size; i++)
	{
		if (adb->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void delete_person(Addressbooks * adb, int det)//ɾ����ϵ��
{
	for (int i = det; i < adb->m_Size - 1; i++)
	{
		adb->personArray[i] = adb->personArray[i + 1];
	}
	adb->m_Size--;
}

void modify_person(Addressbooks * adb)//�޸�ͨѶ¼
{
	string name;
	cout << "�����޸ĵ���ϵ������Ϊ" << endl;
	cin >> name;
	int det = is_person_exist(adb, name);
	if (det != -1)
	{
		cout << "���˵�ͨѶ��ϢΪ" << endl;
		cout << "����:\t�Ա�:\t����:\t�绰:\t\tסַ:\t" << endl;
		cout << adb->personArray[det].m_Name << "\t";
		cout << adb->personArray[det].m_Sex << "\t";
		cout << adb->personArray[det].m_Age << "\t";
		cout << adb->personArray[det].m_Phone << "\t\t";
		cout << adb->personArray[det].m_Address << "\t" << endl;

		string name;
		cout << "�������µ�����" << endl;
		cin >> name;
		adb->personArray[det].m_Name = name;
		//�Ա�
		int sexx = 0;
	Flag:
		cout << "�������µ��Ա�1 �����У�0 ����Ů" << endl;
		cin >> sexx;
		if (sexx == 1)
		{
			adb->personArray[det].m_Sex = "��";
		}
		else if (sexx == 0)
		{
			adb->personArray[det].m_Sex = "Ů";
		}
		else
		{
			cout << "������������������" << endl;
			goto Flag;
		}
		string age;
		cout << "�������µ�����" << endl;
		cin >> age;
		adb->personArray[det].m_Age = age;
		string number;
		cout << "�������µ���ϵ�绰" << endl;
		cin >> number;
		adb->personArray[det].m_Phone = number;
		string address;
		cout << "�������µļ�ͥ��ַ" << endl;
		cin >> address;
		adb->personArray[det].m_Address = address;
		adb->m_Size++;
		cout << "*******" << endl;
		cout << "��ӳɹ���" << endl;
		cout << "*******" << endl;
		cout << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");

}

void clean_person(Addressbooks * adb)//���ͨѶ¼
{
	int num = 0;
	while (num == 0 || 1)
	{
		cout << "���Ƿ����Ҫ���? " << endl;
		cout << "����1Ϊȷ����գ�����0Ϊ����ˣ���Ҫ��� " << endl;
		cin >> num;
		if (num == 1)
		{
			adb->m_Size = 0;
			cout << "�ɹ���գ� " << endl;
			break;
		}
		else if (num == 0)
		{
			system("cls");
			cout << "�ۣ���ϲ�㷢��������ʵ���" << endl;
			while (true)
			{
				cout << "�������ɴ���ѧ����ϲ���̶������ۣ���1�ǵ�5��" << endl;
				int star;
				cin >> star;
				if (star >= 1 && star <= 4)
				{
					cout << "����ƨƨ�������" << endl;
					cout << endl;
				}
				else if (star == 5)
				{
					system("cls");
					cout << "����֪���ɴ���ѧ�������ϲ���̶���" << endl;
					system("pause");
					cout << "�ɴ���ѧ�������ϲ���̶��ǡ���" << endl;
					system("pause");
					cout << "         ****        ****        " << endl;
					cout << "       ********    ********      " << endl;
					cout << "      ***********************    " << endl;
					cout << "       *********************     " << endl;
					cout << "         *****************       " << endl;
					cout << "           *************         " << endl;
					cout << "              ******             " << endl;
					cout << "                 *               " << endl;
					break;
				}
				else
				{
					cout << "ֻ������1��5֮�����Ŷ��֪����������999���ǲ�����ô����Ŷ~" << endl;
				}
			}

			break;
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
	system("pause");
	system("cls");
}