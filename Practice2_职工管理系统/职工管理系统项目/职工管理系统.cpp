#include<iostream>
#include"Worker_Manager.h"
using namespace std;

int main()
{
	worker_manager wm;
	int choice = 0;
	while (true)
	{
		wm.show_menu();
		cout << "请输入要执行的选项" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exit_system();
		case 1:
			wm.add_worker();
			break;
		case 2:
			wm.show_worker();
			break;
		case 3:
			wm.delete_worker();
			break;
		case 4:
			wm.modify_worker();
			break;
		case 5:
			wm.find_worker();
			break;
		case 6:
			wm.Sort_Emp();
			break;
		case 7:
			wm.clean_file();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
