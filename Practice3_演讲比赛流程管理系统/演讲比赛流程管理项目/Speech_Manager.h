#pragma once
#include<iostream>
#include<vector>
#include <map>
#include"speaker.h"
using namespace std;

//��ƹ�����
class Speech_Manager
{
public:
	Speech_Manager();
	void show_menu();
	void exit_system();
	void init_speech();
	void create_speaker();
	void start_speech();
	void speech_draw();
	void speech_contest();
	void show_result();
	void save_record();
	void load_record();
	void show_record();
	void clear_record();
	~Speech_Manager();

	vector<int> v1;//��һ�ֲ���ѡ�ֱ��
	vector<int> v2;//��һ�ֽ���ѡ�ֱ��
	vector<int> vVictory;//����ѡ�ֱ��
	map<int, speaker> m_speaker;//��ű���Լ�����ѡ��
	int m_index;//��������
	bool file_is_empty;
	map<int, vector<string>> m_record;
};