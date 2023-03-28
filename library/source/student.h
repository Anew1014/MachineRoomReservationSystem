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
//ѧ����
class Student : public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	
	//ѧ����ѧ�ţ�����������
	Student(int id, string name, string pwd);

	virtual void operMenu();


	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();


	//�鿴����ԤԼ
	void showAlllOrder();


	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCom;
};