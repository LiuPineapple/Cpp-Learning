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
	//	cout << "ѡ�ֱ�ţ�" << it->first
	//		<< " ������ " << it->second.m_name
	//		<< " �ɼ��� " << it->second.m_score[0] << endl;
	//}

	//�û�ѡ��
	while (true)
	{
		int choice = 0;
		sm.show_menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:  //��ʼ����
			sm.start_speech();
			sm.save_record();
			break;
		case 2:  //�鿴��¼
			sm.load_record();
			sm.show_record();
			break;
		case 3:  //��ռ�¼
			sm.clear_record();
			break;
		case 0: //�˳�ϵͳ
			sm.exit_system();
			break;
		default:
			system("cls"); //����
			break;

		}
	}
	




	system("pause");
	return 0;
}