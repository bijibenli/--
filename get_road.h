#pragma once
#include"View.h"
void body();
void make_chooce(int ans, string st, string end, vector<int>vt[], int mp_maney[][1000], int mp_time[][1000]);
void choose(string st,string end, vector<int>vt[], int mp_maney[][1000], int mp_time[][1000])
{
	int ans = 0;
	cout << "Ŀǰ�����ַ���ѡ��1 ʱ�����   2 �������   \n ";
	cout << endl;
	cout << "��������ѡ�񷽰�����ţ�";
	cin >> ans;
	system("cls");
	make_chooce(ans, st, end, vt, mp_maney, mp_time);
}
void time_road(string st, string en, vector<int>vt[], int mp_time[][1000])
{
	vector<int>aaa;
	int vis[1000] = { 0 };
	int ans = 0;
	for (int i : st)
	{
		ans += (int)i;
	}
	int start = q_sh.get(ans+M);
	ans = 0;
	for (int i : en)
	{
		ans += (int)i;
	}
	int end = q_sh.get(ans + M);
	ans = 0;
	int ans1 = 0;
	q_queue<pair<int, int>>q; 
	q.push(make_pair(0, start));
	while (q.size() != 0)
	{
		pair<int, int>now = q.top();
		ans += now.first;
		aaa.push_back(now.second);
		if (now.second == end)
		{
			cout << "��Ϊ��ѡ�����·�ߣ�\n";
			cout << "�������Ϊ��" << st << endl;
			for (int i =1;i<aaa.size()-1;i++)
			{
				cout << "���ᾭ����";
				cout << stars[aaa[i]].name << endl;
				//cout << stars[aaa[i]].discription << endl;
			}
			cout << "��󵽴��յ㣺" << en << endl;
			cout <<"·�̺�ʱΪ��" << ans <<"Сʱ"<< endl;
			cout << '\n' << "ף��һ·˳��" << endl;
			system("pause");
			return;
		}
		vis[now.second]++;
		q.pop();
		for (int i=0;i<vt[now.second].size();i++)
		{
			if (vis[vt[now.second][i]])continue;
			q.push(make_pair(mp_time[now.second][vt[now.second][i]], vt[now.second][i]));
		}
	}
	cout << "�Բ���û���ҵĶ�Ӧ·���ܵ���Ŀ��ص�" << endl;
	body();
}
void money_road(string st, string en, vector<int>vt[], int mp_maney[][1000])
{
	vector<int>aaa;
	int vis[1000] = { 0 };
	int ans = 0;
	for (int i : st)
	{
		ans += (int)i;
	}
	int start = q_sh.get(ans + M);
	ans = 0;
	for (int i : en)
	{
		ans += (int)i;
	}
	int end = q_sh.get(ans + M);
	ans = 0;
	int ans1 = 0;
	q_queue<pair<int, int>>q;
	q.push(make_pair(0, start));
	while (q.size() != 0)
	{
		pair<int, int>now = q.top();
		ans += now.first;
		aaa.push_back(now.second);
		if (now.second == end)
		{
			cout << "��Ϊ��ѡ�����·�ߣ�\n";
			cout << "�������Ϊ��" << st << endl;
			for (int i = 1; i < aaa.size() - 1; i++)
			{
				cout << "���ᾭ����";
				cout << stars[aaa[i]].name << endl;
				//cout << stars[aaa[i]].discription << endl;
			}
			cout << "��󵽴��յ㣺" << en << endl;
			cout << "·��Ϊ��" << ans <<"����" << endl;
			cout << '\n' << "ף��һ·˳��" << endl;
			system("pause");
			
			return;
		}
		vis[now.second]++;
		q.pop();
		for (int i = 0; i < vt[now.second].size(); i++)
		{
			if (vis[vt[now.second][i]])continue;
			q.push(make_pair(mp_maney[now.second][vt[now.second][i]], vt[now.second][i]));
		}
	}
	cout << "�Բ���û���ҵĶ�Ӧ·���ܵ���Ŀ��ص�" << endl;
	body();
}
void make_chooce(int ans, string st, string end,vector<int>vt[],int mp_maney[][1000], int mp_time[][1000])
{
	switch (ans)
	{
	case 1:
		time_road(st, end, vt, mp_time);
		break;
	case 2:
		money_road(st, end, vt, mp_maney);
		break;
	default:
		cout << "�Բ����������ѡ�����,���������롣" << endl;
		choose(st, end, vt, mp_maney, mp_time);
		break;
	}
}
