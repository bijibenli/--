#pragma once
#include"View.h"
void body();
void make_chooce(int ans, string st, string end, vector<int>vt[], int mp_maney[][1000], int mp_time[][1000]);
void choose(string st, string end, vector<int>vt[], int mp_maney[][1000], int mp_time[][1000])
{
	int ans = 0;
	cout << "目前有两种方案选择：1 时间最短   2 费用最低   \n ";
	cout << endl;
	cout << "请输入你选择方案的序号：";
	cin >> ans;
	system("cls");
	make_chooce(ans, st, end, vt, mp_maney, mp_time);
}
void time_road(string st, string en, vector<int>vt[], int mp_time[][1000])
{
	int dis[10000];
	memset(dis, 0x3f3f3f3f, sizeof(dis));
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
	q_queue<pair<int, int>>q;
	q.push(make_pair(0, start));
	while (q.size() != 0)
	{
		pair<int, int>now = q.top();
		vis[now.second]++;
		q.pop();
		for (int i = 0; i < vt[now.second].size(); i++)
		{
			if (vis[vt[now.second][i]])continue;
			if (dis[vt[now.second][i]] > mp_time[now.second][vt[now.second][i]] + now.first)
			{
				dis[vt[now.second][i]] = mp_time[now.second][vt[now.second][i]] + now.first;
				q.push(make_pair(dis[vt[now.second][i]], vt[now.second][i]));
			}
		}
	}
	if (dis[end] == 0x3f3f3f3f)
	{
		cout << "对不起，没有找的对应路径能到达目标地点" << endl;
		body();
	}
	else
	{
		cout << "已为您选择最佳路线：\n\n";
		cout << "          您的起点为：" << st << endl;

		cout << "          最后到达终点：" << en << endl;
		cout << "          时间为：" << dis[end] << "小时" << endl;
		cout << '\n' << "祝您一路顺风" << endl;
		system("pause");

		return;
	}
}
void money_road(string st, string en, vector<int>vt[], int mp_maney[][1000])
{
	int dis[10000];
	memset(dis, 0x3f3f3f3f, sizeof(dis));
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
	q_queue<pair<int, int>>q;
	q.push(make_pair(0, start));
	while (q.size() != 0)
	{
		pair<int, int>now = q.top();
		vis[now.second]++;
		q.pop();
		for (int i = 0; i < vt[now.second].size(); i++)
		{
			if (vis[vt[now.second][i]])continue;
			if (dis[vt[now.second][i]] > mp_maney[now.second][vt[now.second][i]] + now.first)
			{
				dis[vt[now.second][i]] = mp_maney[now.second][vt[now.second][i]] + now.first;
				q.push(make_pair(dis[vt[now.second][i]], vt[now.second][i]));
			}
		}
	}
	if (dis[end] == 0x3f3f3f3f)
	{
		cout << "对不起，没有找的对应路径能到达目标地点" << endl;
		body();
	}
	else
	{
		cout << "已为您选择最佳路线：\n\n";
		cout << "          您的起点为：" << st << endl;

		cout << "          最后到达终点：" << en << endl;
		cout << "          路程为：" << dis[end] << "公里" << endl;
		cout << '\n' << "祝您一路顺风" << endl;
		system("pause");

		return;
	}
}
void make_chooce(int ans, string st, string end, vector<int>vt[], int mp_maney[][1000], int mp_time[][1000])
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
		cout << "对不起，你输入的选项错误,请重新输入。" << endl;
		choose(st, end, vt, mp_maney, mp_time);
		break;
	}
}
