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
	cout << "�������������ĳ��У�";
	cin >> st;
	return st;
}
string cin_end()
{
	string end;
	cout << "�����������ѯ�ĳ��У�";
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
		cout << "�Բ���δ�ҵ�������ĵ���\n���ٴ����룺";
		cin >> end;
	}
	system("cls");
	string st = cin_st();
	while (!check(num_start, st))
	{
		cout << "�Բ���δ�ҵ�������ĵ���\n���ٴ����룺";
		cin >> st;
	}
	system("cls");
	choose(st, end, vt, mp_maney, mp_time);
}

