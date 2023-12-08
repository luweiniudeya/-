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
				printf("4.公交线路增加\n");
				printf("5.公交线路删除\n");
				printf("6.公交系统初始化\n");
				printf("0.返回前台系统\n");
				scanf("%d", &subop);
				switch (subop) {
				case 0:break;
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6: {
					initialnization(instance_station);
					getchar(); getchar(); break;
				}
				}
			}
			getchar(); getchar();
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