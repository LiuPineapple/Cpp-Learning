#include<iostream>
#include<string>

using namespace std;

const int max = 1000;
//设计联系人结构体
struct Person
{
	string m_Name;
	string m_Sex;
	string m_Age;
	string m_Phone;
	string m_Address;
};
//设计通讯录结构体
struct Addressbooks
{
	Person personArray[max];
	//记录通讯录中的人员个数
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
	//创建结构体变量
	Addressbooks adb;
	adb.m_Size = 0;

	int select = 0;
	//菜单调用
	while (true)
	{
		show_menu();
		cout << "请选择将要进行的操作" << endl;
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			add_person(&adb);
			break;
		case 2://显示联系人
			show_addressbooks(&adb);
			break;
		case 3://删除联系人
		{
			string name;
			cout << "请输入要删除的联系人姓名" << endl;
			cin >> name;
			int det = is_person_exist(&adb, name);
			if (det == -1)
			{
				cout << "查无此人!" << endl;
			}
			else
			{
				cout << "找到此人" << endl;
				delete_person(&adb, det);
				cout << "删除成功" << endl;
			}
			system("pause");
			system("cls");
		}
		break;
		case 4://查找联系人
		{
			string name;
			cout << "请输入要查找的联系人姓名" << endl;
			cin >> name;
			int det = is_person_exist(&adb, name);
			if (det == -1)
			{
				cout << "查无此人!" << endl;
			}
			else
			{
				cout << "找到此人!" << endl;
				cout << "姓名:\t性别:\t年龄:\t电话:\t\t住址:\t" << endl;
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
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		default:
			cout << "请输入合适的数字" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}

//定义各种函数
void show_menu()//显示菜单
{
	cout << "*********************" << endl;
	cout << "*** 1、添加联系人 ***" << endl;
	cout << "*** 2、显示联系人 ***" << endl;
	cout << "*** 3、删除联系人 ***" << endl;
	cout << "*** 4、查找联系人 ***" << endl;
	cout << "*** 5、修改联系人 ***" << endl;
	cout << "*** 6、清空联系人 ***" << endl;
	cout << "*** 0、退出通讯录 ***" << endl;
	cout << "*********************" << endl;
}


void add_person(Addressbooks *adb)//功能1，添加联系人
{
	if (adb->m_Size == max)
	{
		cout << "通讯录已满，无法添加" << endl;

	}
	else
	{
		//输入姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		adb->personArray[adb->m_Size].m_Name = name;
		//性别
		int sexx = 0;
	Flag:
		cout << "请输入性别，1 代表男，0 代表女" << endl;
		cin >> sexx;
		if (sexx == 1)
		{
			adb->personArray[adb->m_Size].m_Sex = "男";
		}
		else if (sexx == 0)
		{
			adb->personArray[adb->m_Size].m_Sex = "女";
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
			goto Flag;
		}
		string age;
		cout << "请输入年龄" << endl;
		cin >> age;
		adb->personArray[adb->m_Size].m_Age = age;
		string number;
		cout << "请输入联系电话" << endl;
		cin >> number;
		adb->personArray[adb->m_Size].m_Phone = number;
		string address;
		cout << "请输入家庭地址" << endl;
		cin >> address;
		adb->personArray[adb->m_Size].m_Address = address;
		adb->m_Size++;
		cout << "*******" << endl;
		cout << "添加成功！" << endl;
		cout << "*******" << endl;
		cout << endl;
		system("pause");
		system("cls");
	}
}

void show_addressbooks(Addressbooks * adb)//功能2，显示联系人
{
	if (adb->m_Size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		cout << "姓名:\t性别:\t年龄:\t电话:\t\t住址:\t" << endl;
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

int is_person_exist(Addressbooks * adb, string name)//检测名字是否存在
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

void delete_person(Addressbooks * adb, int det)//删除联系人
{
	for (int i = det; i < adb->m_Size - 1; i++)
	{
		adb->personArray[i] = adb->personArray[i + 1];
	}
	adb->m_Size--;
}

void modify_person(Addressbooks * adb)//修改通讯录
{
	string name;
	cout << "您想修改的联系人姓名为" << endl;
	cin >> name;
	int det = is_person_exist(adb, name);
	if (det != -1)
	{
		cout << "此人的通讯信息为" << endl;
		cout << "姓名:\t性别:\t年龄:\t电话:\t\t住址:\t" << endl;
		cout << adb->personArray[det].m_Name << "\t";
		cout << adb->personArray[det].m_Sex << "\t";
		cout << adb->personArray[det].m_Age << "\t";
		cout << adb->personArray[det].m_Phone << "\t\t";
		cout << adb->personArray[det].m_Address << "\t" << endl;

		string name;
		cout << "请输入新的姓名" << endl;
		cin >> name;
		adb->personArray[det].m_Name = name;
		//性别
		int sexx = 0;
	Flag:
		cout << "请输入新的性别，1 代表男，0 代表女" << endl;
		cin >> sexx;
		if (sexx == 1)
		{
			adb->personArray[det].m_Sex = "男";
		}
		else if (sexx == 0)
		{
			adb->personArray[det].m_Sex = "女";
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
			goto Flag;
		}
		string age;
		cout << "请输入新的年龄" << endl;
		cin >> age;
		adb->personArray[det].m_Age = age;
		string number;
		cout << "请输入新的联系电话" << endl;
		cin >> number;
		adb->personArray[det].m_Phone = number;
		string address;
		cout << "请输入新的家庭地址" << endl;
		cin >> address;
		adb->personArray[det].m_Address = address;
		adb->m_Size++;
		cout << "*******" << endl;
		cout << "添加成功！" << endl;
		cout << "*******" << endl;
		cout << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");

}

void clean_person(Addressbooks * adb)//清空通讯录
{
	int num = 0;
	while (num == 0 || 1)
	{
		cout << "您是否真的要清空? " << endl;
		cout << "输入1为确定清空，输入0为点错了，不要清空 " << endl;
		cin >> num;
		if (num == 1)
		{
			adb->m_Size = 0;
			cout << "成功清空！ " << endl;
			break;
		}
		else if (num == 0)
		{
			system("cls");
			cout << "哇！恭喜你发现了这个彩蛋！" << endl;
			while (true)
			{
				cout << "请给你对派大星学长的喜爱程度做评价，从1星到5星" << endl;
				int star;
				cin >> star;
				if (star >= 1 && star <= 4)
				{
					cout << "打你屁屁！重新填！" << endl;
					cout << endl;
				}
				else if (star == 5)
				{
					system("cls");
					cout << "那你知道派大星学长对你的喜爱程度吗？" << endl;
					system("pause");
					cout << "派大星学长对你的喜爱程度是——" << endl;
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
					cout << "只能输入1到5之间的数哦，知道你想输入999但是不能这么输入哦~" << endl;
				}
			}

			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}