#pragma once
#include<iostream>
#include<vector>
#include <map>
#include"speaker.h"
using namespace std;

//设计管理类
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

	vector<int> v1;//第一轮参赛选手编号
	vector<int> v2;//第一轮晋级选手编号
	vector<int> vVictory;//晋级选手编号
	map<int, speaker> m_speaker;//存放编号以及具体选手
	int m_index;//比赛轮数
	bool file_is_empty;
	map<int, vector<string>> m_record;
};