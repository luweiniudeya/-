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
				printf("4.����ȫ����·����\n");
				printf("5.������·ɾ��\n");
				printf("6.����ϵͳ��ʼ��\n");
				printf("0.����ǰ̨ϵͳ\n");
				scanf("%d", &subop);
				switch (subop) {
				case 0:break;
				case 1: {
					string s;
					printf("������վ������:\n");
					cin >> s;
					if (instance_station.add_dot(s))
						printf("���վ��ɹ�,��վ����Ϊ%d\n",instance_station.dotnum);
					else printf("���վ��ʧ��\n");

					getchar(); getchar(); break;
				}
				case 2: {
					printf("��ѡ���ӳ������ߣ�������վ���newvalue\n");
					int whichroute, newvalue, station;
					scanf("%d%d%d", &whichroute, &station, &newvalue);
					if (instance_station.prolong(whichroute, station, newvalue))
						printf("�ӳ��ɹ�\n");
					else printf("�ӳ�ʧ��\n");
					getchar(); getchar(); break;
				}
				case 3: {
					int From, To, Newvalue, whichroute;
					printf("�����������ĸ����� ������ from���� to���� new_value\n");
					scanf("%d%d%d%d", &whichroute, &From, &To, &Newvalue);
					if (instance_station.revise_dot(Newvalue, whichroute, From, To))
						printf("�޸ĳɹ�\n");
					else printf("�޸�ʧ��\n");
					getchar(); getchar(); break;
				}
				case 4: {
					printf("����������·����n���ߣ�������n�� ÿ���������ֱ����from to value\n");
					printf("����·���Ϊ%d", instance_station.add_route());
					getchar(); getchar(); break;
				}
				case 5: {
					int whichroute;
					printf("��������ɾ����·��\n");
					scanf("%d", &whichroute);
					if (instance_station.delete_route(whichroute))
						printf("ɾ���ɹ�\n");
					else printf("ɾ��ʧ��\n");
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