#include"Speech_Manager.h"
#include"speaker.h"
#include<string>
#include<algorithm>
#include<deque>
#include<functional>
#include<iostream>
#include<numeric>
#include<fstream>
using namespace std;

//���캯��
Speech_Manager::Speech_Manager()
{
	this->init_speech();
	this->create_speaker();
}
//�˵�����
void Speech_Manager::show_menu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
//�˳�����
void Speech_Manager::exit_system()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
//��ʼ������
void Speech_Manager::init_speech()
{
	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_index = 1;
	this->m_speaker.clear();
	this->m_record.clear();
}
//����v1��m_speaker
void Speech_Manager::create_speaker()
{
	string name_seed = "ABCDEFGHIJKL";
	for (int i = 0; i < name_seed.size(); i++)
	{
        speaker sp;
		string name = "ѡ��";
		sp.m_name = name + name_seed[i];
		//sp.m_name = "ѡ��"+ name_seed[i];�ǲ��Եģ���Ϊ����string����û������+�����
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		v1.push_back(i + 10001);
		m_speaker.insert(make_pair(i + 10001, sp));
	}

}
//������������
void Speech_Manager::start_speech()
{
	//��һ�ֱ���
	//1����ǩ
	this->m_index = 1;
	this->speech_draw();
	//2������
	this->speech_contest();
	//3����ʾ�������
	this->show_result();
	//�ڶ��ֱ���
	this->m_index++;
	//1����ǩ
	this->speech_draw();
	//2������
	this->speech_contest();
	//3����ʾ���ս��
	this->show_result();
	//4���������


}
//��ǩ����
void Speech_Manager::speech_draw()
{
	cout << "�� << " << this->m_index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "---------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (this->m_index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
	system("pause");
	cout << endl;
}
void Speech_Manager::speech_contest()
{
	cout << "------------- ��" << this->m_index << "����ʽ������ʼ��------------- " << endl;

	multimap<double, int, greater<double>> groupScore; //��ʱ����������key���� value ѡ�ֱ��

	int num = 0; //��¼��Ա����6��Ϊ1��

	vector <int>v_Src;   //��������Ա����
	if (this->m_index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//�������в���ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;  // 600 ~ 1000
														 //cout << score << " ";
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());				//����
		d.pop_front();												//ȥ����߷�
		d.pop_back();												//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);				//��ȡ�ܷ�
		double avg = sum / (double)d.size();									//��ȡƽ����

																				//ÿ����ƽ����
																				//cout << "��ţ� " << *it  << " ѡ�֣� " << this->m_Speaker[*it].m_Name << " ��ȡƽ����Ϊ�� " << avg << endl;  //��ӡ����
		this->m_speaker[*it].m_score[this->m_index - 1] = avg;

		//6����һ�飬����ʱ��������
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{

			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "���: " << it->second << " ������ " << this->m_speaker[it->second].m_name << " �ɼ��� " << this->m_speaker[it->second].m_score[this->m_index - 1] << endl;
			}

			int count = 0;
			//ȡǰ����
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}

			groupScore.clear();

			cout << endl;

		}
	}
	cout << "------------- ��" << this->m_index << "�ֱ������  ------------- " << endl;
	system("pause");
}
//��ʾ���
void Speech_Manager::show_result()
{
	vector<int> v;
	cout << "--------------��" << this->m_index << "�ֱ����Ļ�ʤ��Ϊ----------" << endl;
	if (this->m_index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ� " << *it << " ������ " << m_speaker[*it].m_name << " �÷֣� " << m_speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_menu();
}
//�����¼
void Speech_Manager::save_record()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // ������ķ�ʽ���ļ�  -- д�ļ�

												 //��ÿ��������д�뵽�ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << ","
			<< m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();
	system("cls");
	cout << "��¼�Ѿ�����" << endl;
	cout << "�����������" << endl;
}
//��������
void Speech_Manager::load_record()
{
	ifstream ifs("speech.csv", ios::in); //���������� ��ȡ�ļ�

	if (!ifs.is_open())
	{
		this->file_is_empty = true;
		//cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��!" << endl;
		this->file_is_empty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->file_is_empty = false;

	ifs.putback(ch); //��ȡ�ĵ����ַ��Ż�ȥ

	string data;
	int index = 0;
	while (ifs >> data)
	{
		//cout << data << endl;
		vector<string>v;

		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start); //��0��ʼ���� ','
			if (pos == -1)
			{
				break; //�Ҳ���break����
			}
			string tmp = data.substr(start, pos - start); //�ҵ���,���зָ� ����1 ��ʼλ�ã�����2 ��ȡ����
			v.push_back(tmp);
			start = pos + 1;
		}

		this->m_record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();
}
void Speech_Manager::show_record()
{
	if (this->file_is_empty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_record.size(); i++)
		{
			cout << "��" << i + 1 << "�� " <<
				"�ھ���ţ�" << this->m_record[i][0] << " �÷֣�" << this->m_record[i][1] << " "
				"�Ǿ���ţ�" << this->m_record[i][2] << " �÷֣�" << this->m_record[i][3] << " "
				"������ţ�" << this->m_record[i][4] << " �÷֣�" << this->m_record[i][5] << endl;
		}
		this->m_record.clear();
	}
	
	system("pause");
	system("cls");
}
void Speech_Manager::clear_record()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs;
		ofs.open("speech.csv", ios::trunc);
		ofs.close();

		//��ʼ������
		this->init_speech();

		//����ѡ��
		this->create_speaker();

		//��ȡ�����¼
		/*this->load_record();*/


		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}
//��������
Speech_Manager::~Speech_Manager()
{

}