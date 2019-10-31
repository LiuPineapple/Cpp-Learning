#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class manager :public worker
{
public:
	manager(int id, string name, int did);
	void show_inf();
	string get_dep_name();
};