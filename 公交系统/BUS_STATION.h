#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
const int max_station = 101;//����100վ��
struct EDGE {
	int from;
	int to;
	int value;
	struct EDGE* next;
	EDGE(int from,int to,int value):from(from),to(to),value(value),next(nullptr){}
	~EDGE() { if (next != nullptr)delete next; }
};
struct BUS_STATION {//����ϵͳ��Դ������
	struct EDGE* route[max_station];
	string name[max_station];
	int dotnum;//����վ����
	int routenum;//������·��
	int edgenum;//�ܱ���
	int map[max_station][max_station];//�� i��ͨ�� map[i][j]��·����j ������Ʋ��� from to����ж�����ͬ�ı� �����ص�dfs�㷨ҲӦ��Ϊ����map��
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
	int add_route();//�������� Σ��
};
void route_print(BUS_STATION& instance);//���������������ʱû�п��ǵ�������Ϊ��Ա���������ڱ��ִ���ʹ��
void initialnization(BUS_STATION& instance);//�������� Σ��
void dfs(int* visited, BUS_STATION& instance, int thisnum, vector<int>& dfstack, vector<int>& valuestack, int destination);
void format_print(vector<int>& dfstack, vector<int>& valuestack, BUS_STATION& instance);

