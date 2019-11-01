#include<iostream>
using namespace std;
#include"Speech_Manager.h"
#include"speaker.h"
#include<ctime>

int main()
{
	srand((unsigned int)time(NULL));
	Speech_Manager sm;
	//for (map<int, speaker>::iterator it = sm.m_speaker.begin(); it != sm.m_speaker.end(); it++)
	//{
	//	cout << "选手编号：" << it->first
	//		<< " 姓名： " << it->second.m_name
	//		<< " 成绩： " << it->second.m_score[0] << endl;
	//}

	//用户选择
	while (true)
	{
		int choice = 0;
		sm.show_menu();
		cout << "请输入您的选择" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:  //开始比赛
			sm.start_speech();
			sm.save_record();
			break;
		case 2:  //查看记录
			sm.load_record();
			sm.show_record();
			break;
		case 3:  //清空记录
			sm.clear_record();
			break;
		case 0: //退出系统
			sm.exit_system();
			break;
		default:
			system("cls"); //清屏
			break;

		}
	}
	




	system("pause");
	return 0;
}