#include "stdafx.h"
#include <iostream>
using namespace std;

#define FULLTOWER 1
#define EMPTYTOWER 0

class Tower
{
private: int floor[4];
		 int TopFloor;//标注每个塔当前的顶层是多少

public:
		 int Place;		//绝对坐标

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
			cout << "初始状态IfFull输入错误" << endl;
		}
	}
	void AddFloor(int FloorAdded)//给该塔添加一层
	{
		if (TopFloor == -1 || ( FloorAdded < floor[TopFloor]) )
		{
			TopFloor++;
			floor[TopFloor] = FloorAdded;
		}
		else
		{
			cout << "无法添加" << endl;
			system("pause");
		}
	}
	void DeleteFloor(int &FloorAdded)//删去最顶层并把该层的大小返回给FLoorAdded
	{
		if (TopFloor < 0 )
		{
			cout << "删除错误，此塔为空" << endl;
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
	//生成一座满的四层塔和两座空塔
	Tower tower1 = Tower(FULLTOWER);
	Tower tower2 = Tower(EMPTYTOWER);
	Tower tower3 = Tower(EMPTYTOWER);

	tower1.setPlace(1);
	tower2.setPlace(2);
	tower3.setPlace(3);

	drawTower(&tower1, &tower2, &tower3);
	TowerPush(&tower1, &tower2, &tower3, 4);//借助二塔把一塔全部转移到三塔

	system("pause");
}

void moveTower(Tower *originalTower, Tower *aimTower) //来源塔的第n层移动到目标塔的顶层
{
	int floor = 0;
	originalTower->DeleteFloor(floor);	//删除来源塔的顶层，并把该数值给floor
	aimTower->AddFloor(floor);			//目标塔顶层获得该层
}

void TowerPush(Tower *tower1, Tower *tower2, Tower *tower3, int n) //将一号塔的n层借助二号塔移动到三号塔
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
	cout << "塔一" << "\t" << "塔二" << "\t" << "塔三" << "\t" << endl ;
	cout << "-----------------------分割线---------------------" << endl;
}