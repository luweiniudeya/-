#include"BUS_STATION.h"
int main()
{
	int op = 1;
	BUS_STATION instance_station;
	while (op)
	{
		system("cls");
		printf("��ѡ����Ĳ���\n");
		printf("1.��ѯ������·\n");
		printf("2.��ѯ�˳�����\n");
		printf("3.��ѯ���ų˳�����\n");
		printf("4.��̨������\n");
		printf("5.ȫ��·һ��\n");
		printf("0.exit\n");
		scanf("%d", &op);
		switch (op)
		{
		case 0: break;
		case 1: {
			int x;
			system("cls");
			printf("�������Բ�ѯ��������·��");
			scanf("%d", &x);
			cout << endl;
			instance_station.print_thisroute(x);
			getchar(); getchar();
			break;
		}
		case 2: {
			system("cls");
			int x, y;
			printf("�������Բ�ѯ��վ��x��վ��y�ĳ˳�����:");
			scanf("%d%d", &x, &y);
			cout << endl;
			instance_station.inquire(x, y);
			getchar(); getchar();
			break;
		}
		case 3: {
			system("cls");
			int x, y;
			printf("�������Բ�ѯ��վ��x��վ��y����̳˳�����:");
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
				printf("��ѡ����Ĳ���\n");
				printf("1.����վ��\n");
				printf("2.�ӳ�·��\n");
				printf("3.����վ��value�޸�\n");
				printf("4.������·����\n");
				printf("5.������·ɾ��\n");
				printf("6.����ϵͳ��ʼ��\n");
				printf("0.����ǰ̨ϵͳ\n");
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