#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "Identity.h"
#include <string>
#include <vector>
#include "computerRoom.h"
#include "globalFile.h"
#include "orderFile.h"
//学生类
class Student : public Identity
{
public:
	//默认构造
	Student();
	
	//学生的学号，姓名，密码
	Student(int id, string name, string pwd);

	virtual void operMenu();


	//申请预约
	void applyOrder();

	//查看自身预约
	void showMyOrder();


	//查看所有预约
	void showAlllOrder();


	//取消预约
	void cancelOrder();

	//学生学号
	int m_Id;

	//机房容器
	vector<ComputerRoom> vCom;
};