#pragma once
#include<iostream>
#include "Worker.h"
using namespace std;

class employee : public worker
{
public:
	employee(int id, string name, int did);
	void show_inf();
	string get_dep_name();
};

