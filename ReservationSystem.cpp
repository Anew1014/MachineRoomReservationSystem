#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

//����ѧ���Ӳ˵�����
void studentMenu(Identity*& student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();

		Student* stu = (Student*)student;
		
		int select = 0;
		cin >> select;

		if (select == 1)		//����ԤԼ
		{
			stu->applyOrder();

		}
		else if (select == 2)		//�鿴�ҵ�ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)		//�鿴����ԤԼ
		{
			stu->showAlllOrder();
		}
		else if (select == 4)		//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			//ע����¼
			delete student;
			cout << "ע���ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�����ʦ�Ӳ˵�����
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//�����Ӳ˵�����
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;		//�����û�ѡ��

		cin >> select;

		if (select == 1)		//�鿴����ԤԼ
		{
			tea->showAllOrder();
		}
		else if (select == 2)			//	���ԤԼ
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//�������Ա�Ӳ˵�����
void managerMenu(Identity * &manager)
{
	while (true)
	{
		manager->operMenu();

		Manager* man = (Manager*)manager;

		int select = 0;

		//�����û�ѡ��
		cin >> select;

		if (select == 1)		//�����˺�
		{
			//cout << "�����˺�" << endl;
			man->addPerson();

		}
		else if (select == 2)		//�鿴�˺�
		{
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)		//�鿴����
		{
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)		//���ԤԼ
		{
			//cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;		//���ٶ�������
			cout << "ע���ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//��¼����
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//�����û�����Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж�����
	if (type == 1)	//ѧ������
	{
		cout << "���������ѧ�ţ� " << endl;
		cin >> id;
	}
	else if (type == 2)	//ְ������
	{
		cout << "����������ְ����" << endl;
		cin >> id;
	}
	
	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ��������֤
		int fId;	//�ļ���ȡid
		string fName;		//�ļ���ȡ����
		string fPwd;		//�ļ���ȡ����
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);


				//����ѧ���Ӳ˵�
				studentMenu(person);

				return;
			}

		}
	}
	else if (type == 2)
	{
		//��ʦ������֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//�����ʦ�Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա������֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);

				//�������Ա�Ӳ˵�����
				managerMenu(person);


				return;

			}
		}

	}

	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
		

}


int main()
{
	int select = 0;

	while (true)
	{
		cout << "=============		    ��ӭ��������ԤԼϵͳ		    ==============" << endl;
		cout << endl << "��������������" << endl;
		cout << "\t\t  ----------------------------------------\n";
		cout << "\t\t| ----------------------------------------|\n";
		cout << "\t\t| ------------1. ѧ      ��---------------|\n";
		cout << "\t\t| ----------------------------------------|\n";
		cout << "\t\t| ------------2. ��      ʦ---------------|\n";
		cout << "\t\t| ----------------------------------------|\n";
		cout << "\t\t| ------------3. ��  ��   Ա--------------|\n";
		cout << "\t\t| ----------------------------------------|\n";
		cout << "\t\t| ------------0. ��      ��---------------|\n";
		cout << "\t\t| ----------------------------------------|\n";
		cout << "\t\t  ----------------------------------------\n";
		cout << "��������ѡ��";

		cin >> select;


		//�����û���ѡ��ѡ��ͬ�Ĺ��ܽӿ�
		switch (select)
		{
		case 1:		//ѧ������
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:		//��ʦ����
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:		//����Ա����
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:		//�˳�ϵͳ
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			system("cls");
			return 0;
			break;	
		default:
			cout << "�������������ѡ��! " << endl;
			system("pause");
			system("cls");
			break;
	}
	

	}

	
	return 0;
}