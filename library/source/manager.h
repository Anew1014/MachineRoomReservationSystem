#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include <fstream>
#include "globalFile.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerRoom.h"

class Manager : public Identity
{
public:
	Manager();

	Manager(string name, string pwd);

	//菜单界面
	void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空信息
	void cleanFile();

	//检测重复 学号/职工号
	bool checkRepeat(int id, int type);

	//初始化容器
	void initVector();

	//学生容器
	vector<Student> vStu;

	//老师容器
	vector<Teacher> vTea;

	//机房信息容器
	vector<ComputerRoom> vCom;
};

