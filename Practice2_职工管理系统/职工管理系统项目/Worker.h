#pragma once
#include<iostream>
#include<string>
using namespace std;

class worker
{
public:
	virtual void show_inf() = 0;
	virtual string get_dep_name() = 0;

	int m_Id;
	string m_Name;
	int m_DepId;
};