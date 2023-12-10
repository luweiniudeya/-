#include"BUS_STATION.h"
int main()
{
	int op = 1;
	BUS_STATION instance_station;
	while (op)
	{
		system("cls");
		printf("请选择你的操作\n");
		printf("1.查询公交线路\n");
		printf("2.查询乘车方案\n");
		printf("3.查询最优乘车方案\n");
		printf("4.后台管理功能\n");
		printf("5.全线路一览\n");
		printf("0.exit\n");
		scanf("%d", &op);
		switch (op)
		{
		case 0: break;
		case 1: {
			int x;
			system("cls");
			printf("请输入以查询几号线线路：");
			scanf("%d", &x);
			cout << endl;
			instance_station.print_thisroute(x);
			getchar(); getchar();
			break;
		}
		case 2: {
			system("cls");
			int x, y;
			printf("请输入以查询从站点x到站点y的乘车方案:");
			scanf("%d%d", &x, &y);
			cout << endl;
			instance_station.inquire(x, y);
			getchar(); getchar();
			break;
		}
		case 3: {
			system("cls");
			int x, y;
			printf("请输入以查询从站点x到站点y的最短乘车方案:");
			scanf("%d%d", &x, &y);
			cout << endl;
			instance_station.bellman_ford(x, y);
			getchar(); getchar();
			break;
		}
		case 4: {
			int subop = 1;
			while (subop)
			{
				system("cls");
				printf("请选择你的操作\n");
				printf("1.增加站点\n");
				printf("2.延长路线\n");
				printf("3.公交站点value修改\n");
				printf("4.公交全新线路增加\n");
				printf("5.公交线路删除\n");
				printf("6.公交系统初始化\n");
				printf("0.返回前台系统\n");
				scanf("%d", &subop);
				switch (subop) {
				case 0:break;
				case 1: {
					string s;
					printf("输入新站点名字:\n");
					cin >> s;
					if (instance_station.add_dot(s))
						printf("添加站点成功,该站点编号为%d\n",instance_station.dotnum);
					else printf("添加站点失败\n");

					getchar(); getchar(); break;
				}
				case 2: {
					printf("请选择延长几号线，并输入站点和newvalue\n");
					int whichroute, newvalue, station;
					scanf("%d%d%d", &whichroute, &station, &newvalue);
					if (instance_station.prolong(whichroute, station, newvalue))
						printf("延长成功\n");
					else printf("延长失败\n");
					getchar(); getchar(); break;
				}
				case 3: {
					int From, To, Newvalue, whichroute;
					printf("请连续输入四个整数 几号线 from顶点 to顶点 new_value\n");
					scanf("%d%d%d%d", &whichroute, &From, &To, &Newvalue);
					if (instance_station.revise_dot(Newvalue, whichroute, From, To))
						printf("修改成功\n");
					else printf("修改失败\n");
					getchar(); getchar(); break;
				}
				case 4: {
					printf("请输入新线路共有n条边，接下来n行 每行三个数分别代表from to value\n");
					printf("该线路编号为%d", instance_station.add_route());
					getchar(); getchar(); break;
				}
				case 5: {
					int whichroute;
					printf("请输入以删除线路几\n");
					scanf("%d", &whichroute);
					if (instance_station.delete_route(whichroute))
						printf("删除成功\n");
					else printf("删除失败\n");
					getchar(); getchar(); break;
				}
				case 6: {
					initialnization(instance_station);
					getchar(); getchar(); break;
				}
				}
			}
			break;
		}
		case 5:
		{
			system("cls");
			route_print(instance_station);
			getchar(); getchar();
			break;
		}
		}
	}
}