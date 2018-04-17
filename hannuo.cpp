#include "stdafx.h"
#include <iostream>
using namespace std;

#define FULLTOWER 1
#define EMPTYTOWER 0

class Tower
{
private: int floor[4];
		 int TopFloor;//��עÿ������ǰ�Ķ����Ƕ���

public:
		 int Place;		//��������

public:
	Tower()
	{

	}
	Tower(int IfFull)
	{
		if (IfFull == 1) {
			TopFloor = 3;
			for (int i = 0; i < 4; i++)
				floor[i] = 4 - i;
		}
		else if (IfFull == 0) {
			TopFloor = -1;
			for (int i = 0; i < 4; i++)
				floor[i] = 0;
		}
		else {
			cout << "��ʼ״̬IfFull�������" << endl;
		}
	}
	void AddFloor(int FloorAdded)//���������һ��
	{
		if (TopFloor == -1 || ( FloorAdded < floor[TopFloor]) )
		{
			TopFloor++;
			floor[TopFloor] = FloorAdded;
		}
		else
		{
			cout << "�޷����" << endl;
			system("pause");
		}
	}
	void DeleteFloor(int &FloorAdded)//ɾȥ��㲢�Ѹò�Ĵ�С���ظ�FLoorAdded
	{
		if (TopFloor < 0 )
		{
			cout << "ɾ�����󣬴���Ϊ��" << endl;
			system("pause");
		}
		else
		{
			FloorAdded = floor[TopFloor];
			floor[TopFloor] = 0;
			TopFloor--;
		}
	}

	void setPlace(int n)
	{
		Place = n;
	}

	int getFloor(int n)
	{
		return floor[n];
	}

};

void TowerPush(Tower *tow1, Tower *tow2, Tower *tow3, int n);
void moveTower(Tower *originalTower, Tower *aimTower);
void drawTower(Tower *tower1, Tower *tower2, Tower *tower3);

int main()
{
	//����һ�������Ĳ�������������
	Tower tower1 = Tower(FULLTOWER);
	Tower tower2 = Tower(EMPTYTOWER);
	Tower tower3 = Tower(EMPTYTOWER);

	tower1.setPlace(1);
	tower2.setPlace(2);
	tower3.setPlace(3);

	drawTower(&tower1, &tower2, &tower3);
	TowerPush(&tower1, &tower2, &tower3, 4);//����������һ��ȫ��ת�Ƶ�����

	system("pause");
}

void moveTower(Tower *originalTower, Tower *aimTower) //��Դ���ĵ�n���ƶ���Ŀ�����Ķ���
{
	int floor = 0;
	originalTower->DeleteFloor(floor);	//ɾ����Դ���Ķ��㣬���Ѹ���ֵ��floor
	aimTower->AddFloor(floor);			//Ŀ���������øò�
}

void TowerPush(Tower *tower1, Tower *tower2, Tower *tower3, int n) //��һ������n������������ƶ���������
{
	if (n == 1)
	{
		moveTower(tower1, tower3);
		drawTower(tower1, tower2, tower3);
	}
	else
	{
		TowerPush(tower1, tower3, tower2, n - 1);
		moveTower(tower1, tower3);
		drawTower(tower1, tower2, tower3);
		TowerPush(tower2, tower1, tower3, n - 1);
	}

}

void drawTower(Tower *tower1, Tower *tower2, Tower *tower3)
{
	int i;
	Tower Ttower[3];
	for (i = 1; i <= 3; i++)
	{
		if (tower1->Place == i)
		{
			Ttower[i-1] = *tower1;
		}
		else if (tower2->Place == i)
		{
			Ttower[i - 1] = *tower2;
		}
		else if (tower3->Place == i)
		{
			Ttower[i - 1] = *tower3;
		}
	}

	for (i = 3; i >= 0; i--)
	{
		cout << Ttower[0].getFloor(i) << "\t" << Ttower[1].getFloor(i) << "\t" << Ttower[2].getFloor(i) << "\t" << endl;
	}
	cout << "��һ" << "\t" << "����" << "\t" << "����" << "\t" << endl ;
	cout << "-----------------------�ָ���---------------------" << endl;
}