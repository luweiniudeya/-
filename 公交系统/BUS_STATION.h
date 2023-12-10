#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
const int max_station = 101;//上限100站点
struct EDGE {
	int from;
	int to;
	int value;
	struct EDGE* next;
	EDGE(int from,int to,int value):from(from),to(to),value(value),next(nullptr){}
	~EDGE() { if (next != nullptr)delete next; }
};
struct BUS_STATION {//公交系统资源管理类
	struct EDGE* route[max_station];
	string name[max_station];
	int dotnum;//公交站点数
	int routenum;//公交线路数
	int edgenum;//总边数
	int map[max_station][max_station];//从 i可通过 map[i][j]线路到达j 这里设计不佳 from to间可有多条不同的边 与此相关的dfs算法也应改为不用map的
	BUS_STATION():dotnum(0),routenum(0),edgenum(0)
	{
		memset(map, 0, sizeof(map));
		for (int i = 0; i < max_station; i++)
			route[i] = nullptr;
	}
	~BUS_STATION()
	{
		for (int i = 0; i < max_station; i++)
			if (route[i] == nullptr)
				break;
			else delete route[i];
	}
	void print_thisroute(int num);
	void inquire(int origin, int destination);
	int bellman_ford(int origin, int destination);
	bool revise_dot(int new_value, int whichroute, int begin, int end);
	bool add_dot(string new_name);
	bool delete_route(int whichroute);
	bool prolong(int whichroute, int newstation, int newvalue);
	int add_route();//无输入检查 危险
};
void route_print(BUS_STATION& instance);//这两个函数在设计时没有考虑到可以做为成员函数，现在保持传参使用
void initialnization(BUS_STATION& instance);//无输入检查 危险
void dfs(int* visited, BUS_STATION& instance, int thisnum, vector<int>& dfstack, vector<int>& valuestack, int destination);
void format_print(vector<int>& dfstack, vector<int>& valuestack, BUS_STATION& instance);

