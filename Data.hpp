#pragma once
#include<fstream>
#include<iostream>
#include"Start.h"
#include"Vector.h"
#include"Q_queue.hpp"
#include<string>
#include"Hash.hpp"
using namespace std;

bool in_data( int& len)
{
	ifstream ifs;
	ifs.open("information.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败，请重启" << endl;
		return 0;
	}
	string s;
	bool flag = 0;
	while (getline(ifs, s))
	{
		if (!flag)
		{
			flag = 1;
			//cout << s << endl;
			//if (s == "绵阳")cout << "mianyang" << endl;
			stars[len].name = s;
			int key = 0;
			for (int i = 0; i < s.size(); i++)key += (int)s[i];
			q_sh.add(key + M, len);//中文的话key值为负数，取模会爆于是直接加模数
			len++;
			//cout << s << endl;
			//cout << q_sh.get(key+ M) << endl;
		}
		else
		{
			stars[len - 1].discription = s;
			flag = 0;
		}
	}
	ifs.close();
	return 1;
}

void cin_line(vector<int>vt[],int mp_maney[][1000],int mp_time[][1000])
{
	ifstream ifs;
	ifs.open("data.txt", ios::in);
	
	string s;
	
	while (getline(ifs,s))
	{
		string a, b;
		int t = 0, m = 0;
		int cnt = 1; int len = 1;
		for (char i : s)
		{
			if (i == ' ')
			{
				len = 1;
				cnt++;
				continue;
			}
			if (cnt <= 2)
			{
				if (cnt == 1)
				{
					a += i;
				}
				else
				{
					b += i;
				}
			}
			else
			{	
				if (cnt == 3)
				{
					if (len != 1)
					{
						t *= 10;
					}
					t += i - '0';
					len++;
				}
				else
				{
					if (len != 1)
					{
						m *= 10;
					}
					m += i - '0';
					len++;
				}
				cnt++;
			}
		}
		int ans1 = 0, ans2 = 0;
		for (int i : a)ans1 += (int)i;
		for (int i : b)ans2 += (int)i;
		vt[q_sh.get(ans1 + M)].push_back(q_sh.get(ans2 + M));
		vt[q_sh.get(ans2 + M)].push_back(q_sh.get(ans1 + M));
		mp_maney[q_sh.get(ans1 + M)][q_sh.get(ans2 + M)] = m;
		mp_maney[q_sh.get(ans2 + M)][q_sh.get(ans1 + M)] = m;
		mp_time[q_sh.get(ans1 + M)][q_sh.get(ans2 + M)] = t;
		mp_time[q_sh.get(ans2 + M)][q_sh.get(ans1 + M)] = t;
	}
	ifs.close();
}