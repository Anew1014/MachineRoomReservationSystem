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

	//�˵�����
	void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//�����Ϣ
	void cleanFile();

	//����ظ� ѧ��/ְ����
	bool checkRepeat(int id, int type);

	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//������Ϣ����
	vector<ComputerRoom> vCom;
};

