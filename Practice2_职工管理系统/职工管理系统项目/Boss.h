#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class Boss : public worker
{
public:
	Boss(int id, string name, int did);
	void show_inf();
	string get_dep_name();
};