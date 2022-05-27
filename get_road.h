#pragma once
#include"View.h"
void body();
void make_chooce(int ans, string st, string end, vector<int>vt[], int mp_maney[][1000], int mp_time[][1000]);
void choose(string st,string end, vector<int>vt[], int mp_maney[][1000], int mp_time[][1000])
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
			cout << "已为您选择最佳路线：\n";
			cout << "您的起点为：" << st << endl;
			for (int i =1;i<aaa.size()-1;i++)
			{
				cout << "将会经过：";
				cout << stars[aaa[i]].name << endl;
				//cout << stars[aaa[i]].discription << endl;
			}
			cout << "最后到达终点：" << en << endl;
			cout <<"路程耗时为：" << ans <<"小时"<< endl;
			cout << '\n' << "祝您一路顺风" << endl;
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
	cout << "对不起，没有找的对应路径能到达目标地点" << endl;
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
			cout << "已为您选择最佳路线：\n";
			cout << "您的起点为：" << st << endl;
			for (int i = 1; i < aaa.size() - 1; i++)
			{
				cout << "将会经过：";
				cout << stars[aaa[i]].name << endl;
				//cout << stars[aaa[i]].discription << endl;
			}
			cout << "最后到达终点：" << en << endl;
			cout << "路程为：" << ans <<"公里" << endl;
			cout << '\n' << "祝您一路顺风" << endl;
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
	cout << "对不起，没有找的对应路径能到达目标地点" << endl;
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
		cout << "对不起，你输入的选项错误,请重新输入。" << endl;
		choose(st, end, vt, mp_maney, mp_time);
		break;
	}
}
