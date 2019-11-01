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

//构造函数
Speech_Manager::Speech_Manager()
{
	this->init_speech();
	this->create_speaker();
}
//菜单函数
void Speech_Manager::show_menu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
//退出函数
void Speech_Manager::exit_system()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
//初始化容器
void Speech_Manager::init_speech()
{
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_index = 1;
	this->m_speaker.clear();
	this->m_record.clear();
}
//创建v1和m_speaker
void Speech_Manager::create_speaker()
{
	string name_seed = "ABCDEFGHIJKL";
	for (int i = 0; i < name_seed.size(); i++)
	{
        speaker sp;
		string name = "选手";
		sp.m_name = name + name_seed[i];
		//sp.m_name = "选手"+ name_seed[i];是不对的，因为不是string容器没有重载+运算符
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		v1.push_back(i + 10001);
		m_speaker.insert(make_pair(i + 10001, sp));
	}

}
//控制整个比赛
void Speech_Manager::start_speech()
{
	//第一轮比赛
	//1、抽签
	this->m_index = 1;
	this->speech_draw();
	//2、比赛
	this->speech_contest();
	//3、显示晋级结果
	this->show_result();
	//第二轮比赛
	this->m_index++;
	//1、抽签
	this->speech_draw();
	//2、比赛
	this->speech_contest();
	//3、显示最终结果
	this->show_result();
	//4、保存分数


}
//抽签函数
void Speech_Manager::speech_draw()
{
	cout << "第 << " << this->m_index << " >> 轮比赛选手正在抽签" << endl;
	cout << "---------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
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
	cout << "------------- 第" << this->m_index << "轮正式比赛开始：------------- " << endl;

	multimap<double, int, greater<double>> groupScore; //临时容器，保存key分数 value 选手编号

	int num = 0; //记录人员数，6个为1组

	vector <int>v_Src;   //比赛的人员容器
	if (this->m_index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//遍历所有参赛选手
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;  // 600 ~ 1000
														 //cout << score << " ";
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());				//排序
		d.pop_front();												//去掉最高分
		d.pop_back();												//去掉最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f);				//获取总分
		double avg = sum / (double)d.size();									//获取平均分

																				//每个人平均分
																				//cout << "编号： " << *it  << " 选手： " << this->m_Speaker[*it].m_Name << " 获取平均分为： " << avg << endl;  //打印分数
		this->m_speaker[*it].m_score[this->m_index - 1] = avg;

		//6个人一组，用临时容器保存
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{

			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号: " << it->second << " 姓名： " << this->m_speaker[it->second].m_name << " 成绩： " << this->m_speaker[it->second].m_score[this->m_index - 1] << endl;
			}

			int count = 0;
			//取前三名
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
	cout << "------------- 第" << this->m_index << "轮比赛完毕  ------------- " << endl;
	system("pause");
}
//显示结果
void Speech_Manager::show_result()
{
	vector<int> v;
	cout << "--------------第" << this->m_index << "轮比赛的获胜者为----------" << endl;
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
		cout << "选手编号： " << *it << " 姓名： " << m_speaker[*it].m_name << " 得分： " << m_speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_menu();
}
//保存记录
void Speech_Manager::save_record()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // 用输出的方式打开文件  -- 写文件

												 //将每个人数据写入到文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << ","
			<< m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;

	//关闭文件
	ofs.close();
	system("cls");
	cout << "记录已经保存" << endl;
	cout << "比赛进行完毕" << endl;
}
//加载数据
void Speech_Manager::load_record()
{
	ifstream ifs("speech.csv", ios::in); //输入流对象 读取文件

	if (!ifs.is_open())
	{
		this->file_is_empty = true;
		//cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空!" << endl;
		this->file_is_empty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->file_is_empty = false;

	ifs.putback(ch); //读取的单个字符放回去

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
			pos = data.find(",", start); //从0开始查找 ','
			if (pos == -1)
			{
				break; //找不到break返回
			}
			string tmp = data.substr(start, pos - start); //找到了,进行分割 参数1 起始位置，参数2 截取长度
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
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_record.size(); i++)
		{
			cout << "第" << i + 1 << "届 " <<
				"冠军编号：" << this->m_record[i][0] << " 得分：" << this->m_record[i][1] << " "
				"亚军编号：" << this->m_record[i][2] << " 得分：" << this->m_record[i][3] << " "
				"季军编号：" << this->m_record[i][4] << " 得分：" << this->m_record[i][5] << endl;
		}
		this->m_record.clear();
	}
	
	system("pause");
	system("cls");
}
void Speech_Manager::clear_record()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs;
		ofs.open("speech.csv", ios::trunc);
		ofs.close();

		//初始化属性
		this->init_speech();

		//创建选手
		this->create_speaker();

		//获取往届记录
		/*this->load_record();*/


		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}
//析构函数
Speech_Manager::~Speech_Manager()
{

}