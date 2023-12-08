#include"BUS_STATION.h"
void BUS_STATION::inquire(int origin, int destination)
{
	vector<int>dfstack;
	vector<int>valuestack;
	int visited[max_station];
	memset(visited, 0, sizeof(visited));
	dfstack.push_back(origin);
	dfs(visited, *this, origin, dfstack, valuestack, destination);
}
bool BUS_STATION::revise_dot(int new_value, int whichroute, int begin, int end)
{
	EDGE* edgeptr = this->route[whichroute];
	while (edgeptr != nullptr)
	{
		if (edgeptr->from == begin && edgeptr->to == end)
		{
			edgeptr->value = new_value;
			return 1;
		}
	}
	return 0;
}
bool BUS_STATION::add_dot(string new_name)
{
	if (dotnum >= max_station - 1)
		return 0;
	this->name[dotnum] = new_name;
	dotnum++;
	return 1;
}
bool BUS_STATION::delete_route(int whichroute)
{
	return 1;
}
int BUS_STATION::bellman_ford(int origin, int destination)
{
	//返回origin到destination最短路径的值
	//并调用print函数输出该最短路径
	int dis[max_station];
	int pre[max_station];
	int which[max_station];
	memset(dis, 0x3f, sizeof(dis));
	memset(which, 0, sizeof(which));
	dis[origin] = 0;
	memset(pre, 0, sizeof(pre));
	EDGE* edgeptr = nullptr;
	for (int i = 0; i < this->dotnum - 1; i++)
	{
		//n-1次松弛操作
		for (int j = 1; j <= this->routenum; j++)
		{
			edgeptr = this->route[j];
			while (edgeptr != nullptr)
			{
				if (dis[edgeptr->to] > dis[edgeptr->from] + edgeptr->value)
				{
					dis[edgeptr->to] = dis[edgeptr->from] + edgeptr->value;
					pre[edgeptr->to] = edgeptr->from;
					which[edgeptr->to] = j;//which表示通过哪个线路到达to
				}
				edgeptr = edgeptr->next;
			}
		}
	}
	printf("最短路径长为%d\n", dis[destination]);
	vector<int>stack;
	vector<int>valuestack;
	stack.push_back(destination);
	int whilenum = destination;
	while (pre[whilenum] != origin)
	{
		stack.push_back(pre[whilenum]);
		whilenum = pre[whilenum];
	}
	stack.push_back(origin);
	int left = 0, right = stack.size() - 1;
	int temp;
	while (left < right)//反转
	{
		temp = stack[left];
		stack[left] = stack[right];
		stack[right] = temp;
		left++;
		right--;
	}
	for (int i = 1; i < stack.size(); i++)
	{
		valuestack.push_back(which[stack[i]]);
	}
	format_print(stack,valuestack,*this);
	return dis[destination];
}
void dfs(int* visited, BUS_STATION& instance, int thisnum, vector<int>&dfstack, vector<int>&valuestack,int destination)
{
	visited[thisnum] = 1;
	if (thisnum == destination)
	{
		format_print(dfstack, valuestack, instance);
		valuestack.pop_back();
		dfstack.pop_back();
		visited[thisnum] = 0;
		return;
	}
	for (int i = 1; i <= instance.dotnum; i++)
		if (visited[i] == 0 && instance.map[thisnum][i] != 0)//访问i
		{
			dfstack.push_back(i);
			valuestack.push_back(instance.map[thisnum][i]);
			dfs(visited, instance, i, dfstack, valuestack, destination);
		}
	if(dfstack.size()>0)
		dfstack.pop_back();
	if (valuestack.size() > 0)
		valuestack.pop_back();
	visited[thisnum] = 0;
}
void format_print(vector<int>&dfstack, vector<int>&valuestack,BUS_STATION&instance)
{
	if (dfstack.size() == 0 || valuestack.size() == 0)
	{
		printf("error\n");
		return;
	}
	for (int i = 0; i < valuestack.size(); i++)
		printf("  %d  ", valuestack[i]);
	cout << endl;
	printf("%d", dfstack[0]);
	for (int i = 1; i < dfstack.size(); i++)
		printf("--->%d",dfstack[i]);
	cout << endl;
	cout << instance.name[dfstack[0]];
	for (int i = 1; i < dfstack.size(); i++)
	{
		printf("--->");
		cout << instance.name[dfstack[i]];	
	}
	cout << endl << endl;
}
void BUS_STATION::print_thisroute(int num)
{
	printf("ROUTE %d :", num);
	EDGE* edgeptr = route[num];
	cout << name[edgeptr->from];
	while (edgeptr != nullptr)
	{
		printf("--->");
		cout << name[edgeptr->to];
		edgeptr = edgeptr->next;
	}
	cout << endl;
}
void route_print(BUS_STATION& instance)
{
	for (int i = 1; i <= instance.routenum; i++)
	{
		printf("ROUTE %d :\n", i);
		EDGE* edgeptr = instance.route[i];
		while (edgeptr != nullptr)
		{
			printf("  %d  ", edgeptr->value);
			edgeptr = edgeptr->next;
		}
		cout << endl;
		edgeptr = instance.route[i];
		printf("%d", edgeptr->from);
		while (edgeptr != nullptr)
		{
			printf("--->%d", edgeptr->to);
			edgeptr = edgeptr->next;
		}
		cout << endl;
		edgeptr = instance.route[i];
		cout << instance.name[edgeptr->from];
		while (edgeptr != nullptr)
		{
			printf("--->");
			cout << instance.name[edgeptr->to];
			edgeptr = edgeptr->next;
		}
		printf("\n\n");
	}
}
void initialnization(BUS_STATION& instance)
{
	//首先对instance做资源检查 下面操作二选一即可
	//或者这样做 非空实例直接返回 抛出异常
	//for(int i=0;i<max_station;i++)
	//	if (instance.route[i] != nullptr)
	//	{
	//		//throw("error");
	//		return;
	//	}
	//或者这样做 非空实例释放所有资源
	if (instance.route[1] != nullptr)
	{
		instance.edgenum = 0;
		memset(instance.map, 0, sizeof(instance.map));
		for (int i = 0; i < max_station; i++)
			if (instance.route[i] == nullptr)
				break;
			else {
				delete instance.route[i];
				instance.route[i] = nullptr;
			}
	}
	scanf("%d", &instance.dotnum);
	for (int i = 1; i <= instance.dotnum; i++)
		cin >> instance.name[i];
	scanf("%d", &instance.routenum);

	int x, y, from, to, value;
	int fornum;
	EDGE* edgeptr = nullptr;
	for (int i = 1; i <= instance.routenum; i++)
	{
		//这种存储方式要求表头是起点 链尾是终点 所以输入要有序，这里输入为起点先录入即尾插法
		scanf("%d", &fornum);
		scanf("%d%d%d", &from, &to, &value);
		instance.map[from][to] = i;
		instance.route[i] = new EDGE(from, to, value);
		instance.edgenum++;
		edgeptr = instance.route[i];
		for (int j = 1; j < fornum; j++)
		{
			scanf("%d%d%d", &from, &to, &value);
			instance.map[from][to] = i;
			edgeptr->next = new EDGE(from, to, value);
			edgeptr = edgeptr->next;
			instance.edgenum++;
		}
	}
}