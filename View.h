#pragma once
#include<iostream>
#include"Q_queue.hpp"
#include<iostream>
#include"View.h"
#include"Data.hpp"
#include"Start.h"
#include"get_road.h"
#include"Vector.h"
using namespace std;
int num_start = 0;
int mp_maney[1000][1000];
int mp_time[1000][1000];
vector<int>vt[1000];
bool check( int len, string ans)
{
	for (int i = 0; i < len; i++)
	{
		if (stars[i].name == ans)
		{ 
			return 1;
		}
	}
	return 0;
}
string cin_st()
{
	string st;
	cout << "请输入您出发的城市：";
	cin >> st;
	return st;
}
string cin_end()
{
	string end;
	cout << "请输入您想查询的城市：";
	cin >> end;
	int ans = 0;
	for (int i : end)ans += (int)i;
	int x = q_sh.get(ans + M);
	//cout << x << endl;
	cout << stars[x].discription << endl;
	system("pause");
	return end;
}

void begin()
{
	bool data_YN = in_data(num_start);
	if (!data_YN)
	{
		return;
	}
	//cout << a.get(-274 + M) << endl;
	cin_line(vt, mp_maney, mp_time);
	system("cls");
}

void body()
{
	string end = cin_end();
	while (!check(num_start, end))
	{
		cout << "对不起，未找到你输入的地名\n请再次输入：";
		cin >> end;
	}
	system("cls");
	string st = cin_st();
	while (!check(num_start, st))
	{
		cout << "对不起，未找到你输入的地名\n请再次输入：";
		cin >> st;
	}
	system("cls");
	choose(st, end, vt, mp_maney, mp_time);
}

