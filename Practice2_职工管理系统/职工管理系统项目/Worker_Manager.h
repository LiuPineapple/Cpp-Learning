#pragma once//防止头文件重复包含
#include<iostream>
#include<fstream>
using namespace std;//使用标准命名空间
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
#define filename "worker_file.txt"

class worker_manager
{
public:
	worker_manager();
	void show_menu();
	void exit_system();
	void add_worker();
	void save_file();
	int get_file_num();
	void show_worker();
	void initial_array();
	void delete_worker();
	int find_worker();
	void modify_worker();
	void Sort_Emp();
	void clean_file();

	bool m_is_file_empty;
	int m_number;
	worker ** m_worker_array;
	~worker_manager();
};