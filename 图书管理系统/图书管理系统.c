#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
typedef struct bookimformation
{
	char number[20];
	char name[20];
	char author[20];
	char press[20];
	char category[20];
	float price;
	int quantity;
	int time;
	char account[20];
}bookim;
typedef struct bookgrasp
{
	char number[20];
	char name[20];
	char author[20];
	char press[20];
	char category[20];
	float price;
	char account[20];
}bookgrasp;
typedef struct member
{
	char name[20];
	char ID[20];
	char password[20];
	char sex[20];
	char passwordkey[20];
	char number[20];
	char author[20];
	char press[20];
	char category[20];
	float price;
	int quantity;
	int time;
	char account[20];
}member;
int main()
{
	void menu1();
	void menu2();
	void menu3();
	int check_repeat_book(char[20]);
	void add_book();
	void display_book();
	void search_book();              //�м������������д����
	void delete_book();
	void display_price_low();
	void display_popular();
	void borrow_book(char account[20]);
	void return_book(char account[20]);
	int check_repeat_ID(char idaccount[20]);
	void member_log_up();
	int user_account(char account[20]);
	void find_account();
	int compare_password(char password[20]);
	int member_log_in(char account[20]);
	void admin_watch();
	void bookgrasp_watch();
	void passwordcircle();
	void find_account_circle();
	void about_me();

	int flag1 = 1, flag2 = 1, flag3 = 1;
	char choice1, choice2, choice3, account_choice;

	system("title SYSU-zh");

	while (flag1)
	{
		system("cls");
		fflush(stdin);
		menu1();
		printf("\n���������ѡ��(1-5):\n");
		choice1 = getchar();
		while (choice1 != '1'&&choice1 != '2'&&choice1 != '3'&&choice1 != '4'&&choice1 != '5')
		{
			printf("������ָ������:\n");
			choice1 = getchar();
		}

		if (choice1 == '1')                     //��Աע��
		{
			int flag;
			char account1[20];

			system("cls");
			passwordcircle();
			scanf_s("%s", account1, 20);
			flag = member_log_in(account1);

			if (flag == 2)
			{
				system("cls");
				passwordcircle();
				scanf_s("%s", account1, 20);
				flag = member_log_in(account1);          //��һ�ν��봴�����ڶ��ν����¼
			}
			if (flag == 1)
			{
				while (flag2&&flag3)
				{
					system("cls");
					menu2();
					printf("���������ѡ��(1-8):\n");
					choice2 = getchar();
					while (choice2 != '1'&&choice2 != '2'&&choice2 != '3'&&choice2 != '4'&&
						choice2 != '5'&&choice2 != '6'&&choice2 != '7'&&choice2 != '8')
					{
						printf("������ָ������:\n");
						getchar();
						choice2 = getchar();
					}
					switch (choice2)
					{
					case '1':search_book(); break;
					case '2':borrow_book(account1); break;
					case '3':return_book(account1); break;
					case '4':display_book(); break;
					case '5':display_price_low(); break;
					case '6':display_popular(); break;
					case '7':if (user_account(account1))
					{
						printf("��¼��Ϣ�Ѹı䣬�����µ�¼\n");
						flag3 = 0;
						break;
					}
					case '8':flag2 = 0; printf("�����˳�ϵͳ\n"); break;
					default:break;
					}
				}
			}
			else
			{
				system("cls");
				find_account_circle();
				getchar();
				account_choice = getchar();
				while (account_choice != 'Y'&&account_choice != 'y'&&
					account_choice != 'N'&&account_choice != 'n')
				{
					printf("������ָ���ַ�\n");
					getchar();
					account_choice = getchar();
				}
				if (account_choice == 'Y' || account_choice == 'y')
					find_account();

				flag2 = 1;
				flag3 = 1;
			}
		}
		else if (choice1 == '2')            //��Ա��¼
		{
			system("cls");
			printf("���ڽ����Ա��¼ϵͳ\n");
			member_log_up();
		}
		else if (choice1 == '3')           //����Ա��¼
		{
			char admin_password[20];
			strcpy_s(admin_password, "2666");
			if (compare_password(admin_password))
			{
				printf("������ȷ�����ڵ�¼\n");
				Sleep(1000);
				while (flag2)
				{
					system("cls");
					menu3();
					printf("���������ѡ��(1-8)\n");
					choice3 = getchar();
					while (choice3 != '1'&&choice3 != '2'&&choice3 != '3'&&choice3 != '4'&&
						choice3 != '5'&&choice3 != '6'&&choice3 != '7')
					{
						printf("������ָ������:\n");
						getchar();
						choice3 = getchar();
					}
					switch (choice3)
					{
					case '1':add_book(); break;
					case '2':delete_book(); break;
					case '3':search_book(); break;
					case '4':display_book(); break;
					case '5':admin_watch(); break;
					case '6':display_book(); break;
					case '7':flag2 = 0; printf("�����˳�����Աϵͳ\n"); Sleep(1000); break;
					default:break;
					}
				}
			}
			else
			{
				printf("�����������\n");
			}
			flag2 = 1;
		}
		else if (choice1 == '4')
		{
			system("cls");
			about_me();
			printf("���س����˳�\n");
			getchar();
		}
		else if (choice1 == '5')
		{
			flag1 = 0;
		}
	}

	system("cls");
	printf("���Ѱ�ȫ�˳�ϵͳ����ӭ�ٴ�ʹ�ã����س����رս���\n");
	getchar();
	return 0;
}
void menu1()
{
	system("color FC");
	printf("\n\n");
	printf("\t\t\t\t-------==-------------====-------------==--------\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t     **��ӭ����ͼ�����ϵͳ**    \t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [1] ��Ա��¼                \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t^\t     [2] ��Աע��               \t^\n");
	printf("\t\t\t\t^\t\t\t\t\t\t^\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t$\t     [3] ����Ա��¼              \t$\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t~\t     [4] �������°汾              \t~\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t     [5] �˳�ϵͳ                  \t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t-------==-------------====-------------==--------\n\n");
}   
void menu2()
{
	system("color 74");
	printf("\n\n");
	printf("\t\t\t\t-------==-------------====-------------==--------\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t     ** ��Ա���� **              \t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [1] ����ͼ����Ϣ             \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t^\t     [2] ����ͼ��                 \t^\n");
	printf("\t\t\t\t^\t\t\t\t\t\t^\n");
	printf("\t\t\t\t*\t     [3] �黹ͼ��                 \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t$\t     [4] ����ͼ����Ϣ             \t$\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [5] ��λ�鼮�Ƽ�             \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [6] ͼ�����а�               \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t     [7] ����˻���Ϣ             \t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [8] �˳��û�����             \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t-------==-------------====-------------==--------\n\n");
}
void menu3()
{
	system("color E0");
	printf("\n\n");
	printf("\t\t\t\t-------==-------------====-------------==--------\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t     ** ����Ա���� **              \t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [1] ���ͼ��                \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t^\t     [2] ɾ��ͼ��                 \t^\n");
	printf("\t\t\t\t^\t\t\t\t\t\t^\n");
	printf("\t\t\t\t$\t     [3] ����ͼ����Ϣ             \t$\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [4] ��ʾȫ��ͼ����Ϣ         \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [5] ��ʾ���л�Ա��Ϣ          \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t     [6] ��ʾ���н�����Ϣ          \t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [7] �˳�����Ա����             \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t-------==-------------====-------------==--------\n\n");
}
int check_repeat_book(char number[20])
{
	FILE *p1;
	int i=0, flag = 0,j;                // i���鼮����ţ���һ���飬�ڶ�����...
	bookim bookimfor[100];

	fopen_s(&p1, "D:\\library.txt", "r");
	
	while (!feof(p1))
	{
		fscanf_s(p1, "%s ", &bookimfor[i].number,sizeof(bookimfor[i].number));
		fscanf_s(p1, "%s ", &bookimfor[i].name, sizeof(bookimfor[i].name));
		fscanf_s(p1, "%s ", &bookimfor[i].author, sizeof(bookimfor[i].author));
		fscanf_s(p1, "%s ", &bookimfor[i].press, sizeof(bookimfor[i].press));
		fscanf_s(p1, "%s ", &bookimfor[i].category, sizeof(bookimfor[i].category));
		fscanf_s(p1, "%f ", &bookimfor[i].price);
		fscanf_s(p1, "%d ", &bookimfor[i].quantity);
		fscanf_s(p1, "%d\n", &bookimfor[i].time);
		i++;
	}
	fclose(p1);

	for (j = 0; j < i; j++)
	{
		if (strcmp(bookimfor[j].number,number)==0)
		{
			flag = 1;
		}break;
	}
	if (flag == 1)
		return 1;
	else
		return 0;                                                  
}
void add_book()
{
	FILE *p1;
	bookim newbook;
	int flag;
	char choice;

	system("cls");                  //����
	while (1)
	{
		fflush(stdin);
		flag = 0;

		printf("������ͼ����:\n");
		scanf_s("%s", newbook.number,20);

		if (check_repeat_book(newbook.number))
		{
			printf("�����Ѵ��ڣ��밴�س���������ӡ�\n");
			getchar();
			flag = 1;
		}

		else
		{
			fflush(stdin);
			printf("����������:\n");
			scanf_s("%s", newbook.name, 20);

			printf("����������:\n");
			scanf_s("%s", newbook.author, 20);

			printf("�����������:\n");
			scanf_s("%s", newbook.press, 20);

			printf("�����������ѧ������������..��:\n");
			scanf_s("%s", newbook.category, 20);

			printf("������۸�:\n");
			scanf_s("%f", &newbook.price);

			printf("������ݲ���:\n");
			scanf_s("%d", &newbook.quantity);

			printf("�������ѽ����Ŀ:\n");
			scanf_s("%d", &newbook.time);

			fflush(stdin);
			printf("�Ƿ񱣴��������Y/y����N/n\n");
			getchar();
			choice = getchar();

			while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
			{
				printf("����������\n");
				scanf_s("%c", &choice,2);
			}
			if (choice == 'Y' || choice == 'y')
			{
				fopen_s(&p1, "D:\\library.txt", "a");

				fprintf(p1, "%s ", newbook.number);
				fprintf(p1, "%s ", newbook.name);
				fprintf(p1, "%s ", newbook.author);
				fprintf(p1, "%s ", newbook.press);
				fprintf(p1, "%s ", newbook.category);
				fprintf(p1, "%f ", newbook.price);
				fprintf(p1, "%d ", newbook.quantity);
				fprintf(p1, "%d", newbook.time);
				fclose(p1);
				printf("�������ѱ���\n");
			}
			else
			{
				printf("����Ŀδ����\n");
			}

			printf("�Ƿ���������Ŀ? Y/y����N/n\n");
			getchar();
			choice = getchar();

			while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
			{
				printf("����������\n");
				scanf_s("%c", &choice,2);
			}

			if (choice == 'Y' || choice == 'y' || flag == 1)
				continue;
			else
				break;
		}
	}
}
void display_book()
{
	FILE *p1;
	bookim bookimfor[100];
	int i=0, j;

	system("cls");
	fflush(stdin);

	fopen_s(&p1, "D:\\library.txt", "r");
	
	while (!feof(p1))
	{
		fscanf_s(p1, "%s ", &bookimfor[i].number, sizeof(bookimfor[i].number));
		fscanf_s(p1, "%s ", &bookimfor[i].name, sizeof(bookimfor[i].name));
		fscanf_s(p1, "%s ", &bookimfor[i].author, sizeof(bookimfor[i].author));
		fscanf_s(p1, "%s ", &bookimfor[i].press, sizeof(bookimfor[i].press));
		fscanf_s(p1, "%s ", &bookimfor[i].category, sizeof(bookimfor[i].category));
		fscanf_s(p1, "%f ", &bookimfor[i].price);
		fscanf_s(p1, "%d ", &bookimfor[i].quantity);
		fscanf_s(p1, "%d\n", &bookimfor[i].time);
		i++;
	}
	fclose(p1);

	if (bookimfor[0].quantity == 0)
		printf("�޿��\n");
	else
	{
		printf("|\t\t ��������������ͼ����Ϣ��������������   \t\t   |\n");
		printf("|\t\t\t\t                                      \t   |\n");
		printf("|���   ���� \t    ����\t������       ���    �۸�   �ݲ��� �ѽ�����|\n");
	}
	for (j = 0; j < i; j++)
	{
		printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", bookimfor[j].number,
			bookimfor[j].name,bookimfor[j].author, bookimfor[j].press, 
			bookimfor[j].category,bookimfor[j].price, bookimfor[j].quantity, 
			bookimfor[j].time);
	}
	fflush(stdin);
	printf("���س���������һ���˵�\n");
	system("pause");
}
void search_book()
{
	FILE *p1;
	bookim bookimfor[100];
	char name_compare[20];
	char number_compare[20];
	char author_compare[20];
	char search[20];
	char compare[20];
	int flag1 = 1, flag2 = 1, i, j;
	int select;
	char choice;

	system("cls");
	fflush(stdin);

	fopen_s(&p1, "D:\\library.txt", "r");

	i = 0;
	while (!feof(p1))
	{
		fscanf_s(p1, "%s ", &bookimfor[i].number, sizeof(bookimfor[i].number));
		fscanf_s(p1, "%s ", &bookimfor[i].name, sizeof(bookimfor[i].name));
		fscanf_s(p1, "%s ", &bookimfor[i].author, sizeof(bookimfor[i].author));
		fscanf_s(p1, "%s ", &bookimfor[i].press, sizeof(bookimfor[i].press));
		fscanf_s(p1, "%s ", &bookimfor[i].category, sizeof(bookimfor[i].category));
		fscanf_s(p1, "%f ", &bookimfor[i].price);
		fscanf_s(p1, "%d ", &bookimfor[i].quantity);
		fscanf_s(p1, "%d\n", &bookimfor[i].time);
		i++;
	}
	fclose(p1);

	while (flag1)
	{
		system("cls");
		while(flag2)
		{
			system("cls");
			fflush(stdin);
		
			printf("\n�����������ѯͼ��ķ�ʽ:\n");
			printf("1������   2�����   3��������\n");
			select = getchar();                          //������scanf_s

			printf("��������Ҫ���ҵ���Ϣ:\n");
			switch (select)
			{
			case '1':scanf_s("%s", name_compare, 20); strcpy_s(search, name_compare); flag2 = 0; break;
			case '2':scanf_s("%s", number_compare, 20); strcpy_s(search, number_compare); flag2 = 0; break;
			case '3':scanf_s("%s", author_compare, 20); strcpy_s(search, author_compare); flag2 = 0; break;
			default:break;
			}
			
			
		}
		flag2 = 1;                                     //ǧ����ɾ�������޷���������
		if (bookimfor[0].quantity == 0)
		{
			printf("�����δ�ҵ��Ȿ��\n");
			printf("���س�������");
			getchar(); break;
		}
		else
		{
			for (j = 0; j < i; j++)
			{
				switch (select)
				{
				case '1': strcpy_s(compare, bookimfor[j].name); break;
				case '2': strcpy_s(compare, bookimfor[j].number); break;
				case '3': strcpy_s(compare, bookimfor[j].author); break;
				}

				if (strcmp(search, compare) == 0)
				{
					printf("|\t\t ��������������ͼ����Ϣ��������������   \t\t   |\n");
					printf("|\t\t\t\t                                      \t   |\n");
					printf("|���   ���� \t    ����\t������       ���    �۸�   �ݲ��� �ѽ�����|\n");
					printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", bookimfor[j].number,
						bookimfor[j].name, bookimfor[j].author, bookimfor[j].press,
						bookimfor[j].category, bookimfor[j].price, bookimfor[j].quantity,
						bookimfor[j].time); break;
				}
			}
				if (j >= i)
				{
					printf("û���ҵ�����Ҫ����\n");
				}

				getchar();
				printf("�Ƿ������ѯ��Y/y����N/n\n");
				choice = getchar();

				while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
				{
					printf("����������ָ���ַ�\n");
					getchar();
					printf("�Ƿ������ѯ��Y/y����N/n\n");
					choice = getchar();
				}
				
				if (choice == 'Y' || choice == 'y')
				{
					getchar();                           //����©
					flag1 = 1;
				}
				else
					flag1 = 0;
		}
	}
}
void delete_book()
{
	FILE *p1;
	int i, j, k;
	char choice;
	char search[20];
	bookim bookimfor[100];

	system("cls");
	fflush(stdin);
	while (1)
	{
		fflush(stdin);
		fopen_s(&p1, "D:\\library.txt", "r");
		i = 0;
		while (!feof(p1))
		{
			fscanf_s(p1, "%s ", &bookimfor[i].number, sizeof(bookimfor[i].number));
			fscanf_s(p1, "%s ", &bookimfor[i].name, sizeof(bookimfor[i].name));
			fscanf_s(p1, "%s ", &bookimfor[i].author, sizeof(bookimfor[i].author));
			fscanf_s(p1, "%s ", &bookimfor[i].press, sizeof(bookimfor[i].press));
			fscanf_s(p1, "%s ", &bookimfor[i].category, sizeof(bookimfor[i].category));
			fscanf_s(p1, "%f ", &bookimfor[i].price);
			fscanf_s(p1, "%d ", &bookimfor[i].quantity);
			fscanf_s(p1, "%d\n", &bookimfor[i].time);
			i++;
		}
		fclose(p1);

		printf("����Ҫɾ�����鼮������:\n");
		scanf_s("%s", search, 20);

		if (bookimfor[0].quantity == 0)
		{
			printf("��������κ���Ϣ\n");
			printf("���س����������˵�");
			getchar();
			break;
		}

		else
		{
			for (j = 0; j < i; j++)               // i���鼮����Ŀ
			{
				if (strcmp(bookimfor[j].name, search) != 0)    //������ͬ������һ��ѭ��
				{
					continue;
				}
				if (j >= i)
					printf("�����û���Ȿ��\n");
				else
				{
					printf("ȷ��ɾ���Ȿ�飿Y/y����N/n\n");
					getchar();           //ÿ��choice=getchar() ֮ǰ��Ҫ��һ��
					                     //����choice�޷�����					
					choice = getchar();

					while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
					{
						printf("����������ָ���ַ�\n");						
						printf("ȷ��ɾ���Ȿ�飿Y/y����N/n\n");
						getchar();
						choice = getchar();
					}

					if (choice == 'Y' || choice == 'y')
					{
						for (k = j; k < i - 1; k++)
						{
							bookimfor[k] = bookimfor[k + 1];
						}

						fopen_s(&p1, "D:\\library.txt", "w");
						for (j = 0; j < i - 1; j++)
						{
							fprintf(p1, "%s ", bookimfor[j].number);
							fprintf(p1, "%s ", bookimfor[j].name);
							fprintf(p1, "%s ", bookimfor[j].author);
							fprintf(p1, "%s ", bookimfor[j].press);
							fprintf(p1, "%s ", bookimfor[j].category);
							fprintf(p1, "%f ", bookimfor[j].price);
							fprintf(p1, "%d ", bookimfor[j].quantity);
							fprintf(p1, "%d\n", bookimfor[j].time);
						}
						fclose(p1);
						printf("��������ɾ��\n");
					}
					else
						printf("����δɾ��\n");
				}
			}
			printf("�Ƿ����ɾ����");
			getchar(); 
			choice = getchar();
			while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
			{
				printf("����������ָ���ַ�\n");
				getchar();
				printf("�Ƿ����ɾ����Y/y����N/n\n");
				choice = getchar();
			}
			if (choice == 'Y' || choice == 'y')
				continue;
			else
				break;
			
		}//else����

	}//while����
}
void display_price_low()
{
	FILE *p1;
	float price;
	int count=0, i, j;
	bookim bookimfor[100];

	system("cls");
	fflush(stdin);

	fopen_s(&p1, "D:\\library.txt", "r");
	i = 0;
	while (!feof(p1))
	{
		fscanf_s(p1, "%s ", &bookimfor[i].number, sizeof(bookimfor[i].number));
		fscanf_s(p1, "%s ", &bookimfor[i].name, sizeof(bookimfor[i].name));
		fscanf_s(p1, "%s ", &bookimfor[i].author, sizeof(bookimfor[i].author));
		fscanf_s(p1, "%s ", &bookimfor[i].press, sizeof(bookimfor[i].press));
		fscanf_s(p1, "%s ", &bookimfor[i].category, sizeof(bookimfor[i].category));
		fscanf_s(p1, "%f ", &bookimfor[i].price);
		fscanf_s(p1, "%d ", &bookimfor[i].quantity);
		fscanf_s(p1, "%d\n", &bookimfor[i].time);
		i++;
	}
	fclose(p1);

	printf("��������ͼ۸����ǻ������Ƽ����ڴ˼۸����\n");
	scanf_s("%f", &price);

	if (bookimfor[0].quantity == 0)
	{
		printf("��������κ���Ϣ\n");
	}

	else
	{
		for (j = 0; j < i; j++)
		{
			if (bookimfor[j].price < price)
				count++;
		}

		if (count == 0)
			printf("\nû���ҵ�������۸���͵���\n");
		else
		{
			printf("|\t\t ��������������ͼ����Ϣ��������������   \t\t   |\n");
			printf("|\t\t\t\t                                      \t   |\n");
			printf("|���   ���� \t    ����\t������       ���    �۸�   �ݲ��� �ѽ�����|\n");
			for (j = 0; j < i; j++)
			{
				if (bookimfor[j].price < price)
				{
					printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", bookimfor[j].number,
						bookimfor[j].name, bookimfor[j].author, bookimfor[j].press,
						bookimfor[j].category, bookimfor[j].price, bookimfor[j].quantity,
						bookimfor[j].time);
				}

			}
		}
	}
	printf("\n���س������ز˵�\n");
	getchar();
	system("pause");
}
void display_popular()
{
	FILE *p1;
	int i, j, k;
	bookim bookimfor[100];

	system("cls");
	fflush(stdin);

	fopen_s(&p1, "D:\\library.txt", "r");
	i = 0;
	while (!feof(p1))
	{
		fscanf_s(p1, "%s ", &bookimfor[i].number, sizeof(bookimfor[i].number));
		fscanf_s(p1, "%s ", &bookimfor[i].name, sizeof(bookimfor[i].name));
		fscanf_s(p1, "%s ", &bookimfor[i].author, sizeof(bookimfor[i].author));
		fscanf_s(p1, "%s ", &bookimfor[i].press, sizeof(bookimfor[i].press));
		fscanf_s(p1, "%s ", &bookimfor[i].category, sizeof(bookimfor[i].category));
		fscanf_s(p1, "%f ", &bookimfor[i].price);
		fscanf_s(p1, "%d ", &bookimfor[i].quantity);
		fscanf_s(p1, "%d\n", &bookimfor[i].time);
		i++;
	}
	fclose(p1);

	if (bookimfor[0].quantity == 0)
		printf("��������κ���Ϣ\n");

	for (j = 0; j < i - 1; j++)        // i���鱾���� ð���㷨
	{
		for (k = 0; k < i - 1 - j; k++)
		{
			if (bookimfor[k].time < bookimfor[k + 1].time)
			{
				bookimfor[5] = bookimfor[k];        //�˴��мǲ�����bookimfor[100]��
 				bookimfor[k] = bookimfor[k + 1];    //��Ϊֻ������[99],[100]������
				bookimfor[k + 1] = bookimfor[5];
			}
		}
	}
	
	printf("|\t ��������������ͼ���ܻ�ӭ���а񡪡�����������   \t\t   |\n");
	printf("|\t\t\t\t                                      \t   |\n");
	printf("|���   ���� \t    ����\t������       ���    �۸�   �ݲ��� �ѽ�����|\n");
	for (j = 0; j < i; j++)
	{

		printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", bookimfor[j].number,
				bookimfor[j].name, bookimfor[j].author, bookimfor[j].press,
				bookimfor[j].category, bookimfor[j].price, bookimfor[j].quantity,
				bookimfor[j].time);
	}
	system("pause");
}
void borrow_book(char account[20])
{
	FILE *p1, *p2;
	bookim bookimfor[100];
	char search[20], choice;
	int i, j, flag1=1;

	system("cls");
	fflush(stdin);

	while (flag1)
	{
		fopen_s(&p1, "D:\\library.txt", "r");
		i = 0;
		while (!feof(p1))
		{
			fscanf_s(p1, "%s ", bookimfor[i].number, sizeof(bookimfor[i].number));
			fscanf_s(p1, "%s ", &bookimfor[i].name, sizeof(bookimfor[i].name));
			fscanf_s(p1, "%s ", &bookimfor[i].author, sizeof(bookimfor[i].author));
			fscanf_s(p1, "%s ", &bookimfor[i].press, sizeof(bookimfor[i].press));
			fscanf_s(p1, "%s ", &bookimfor[i].category, sizeof(bookimfor[i].category));
			fscanf_s(p1, "%f ", &bookimfor[i].price);
			fscanf_s(p1, "%d ", &bookimfor[i].quantity);
			fscanf_s(p1, "%d\n", &bookimfor[i].time);
			i++;
		}
		fclose(p1);

		printf("������������ĵ���:\n");
		scanf_s("%s", search, 20);

		if (bookimfor[0].quantity == 0)
		{
			printf("��������κ���Ϣ\n");
			printf("���س������ز˵�");
			getchar();
			break;
		}

		else
		{
			for (j = 0; j < i; j++)
			{
				if (strcmp(search, bookimfor[j].name) == 0)
				{
					bookimfor[j].quantity--;
					bookimfor[j].time++;

					fopen_s(&p2, "D:\\memberbook.txt", "a");

					fprintf(p2, "%s ", bookimfor[j].number);
					fprintf(p2, "%s ", bookimfor[j].name);
					fprintf(p2, "%s ", bookimfor[j].author);
					fprintf(p2, "%s ", bookimfor[j].press);
					fprintf(p2, "%s ", bookimfor[j].category);
					fprintf(p2, "%f", bookimfor[j].price);
					fprintf(p2, "%s\n", account);

					fclose(p2);
					break;
				}
			}
		}
		if (j >= i)
			printf("û���Ȿ�����Ϣ\n");
		else
		{
			fopen_s(&p1, "D:\\library.txt", "w");
			for (j = 0; j < i; j++)
			{
				fprintf(p1, "%s ", bookimfor[j].number);
				fprintf(p1, "%s ", bookimfor[j].name);
				fprintf(p1, "%s ", bookimfor[j].author);
				fprintf(p1, "%s ", bookimfor[j].press);
				fprintf(p1, "%s ", bookimfor[j].category);
				fprintf(p1, "%f ", bookimfor[j].price);
				fprintf(p1, "%d ", bookimfor[j].quantity);
				fprintf(p1, "%d\n", bookimfor[j].time);
			}
			fclose(p1);
			printf("����ɹ�\n");
		}
		printf("�Ƿ�������飿Y/y����N/n  ");

		getchar();
		choice = getchar();
		while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
		{
			printf("������ָ���ַ�\n");
			getchar();
			choice = getchar();
		}
		if (choice == 'Y' || choice == 'y')
			flag1 = 1;
		else
			flag1 = 0;

	}
}
void return_book(char account[20])
{
	FILE *p1, *p2;
	bookim bookimfor[100], bookgrasp[100];
	int i, k, t, n, m, l;
	int flag1=1, flag2;
	char choice;
	char search[20];

	system("cls");
	fflush(stdin);

	while (flag1)
	{
		flag2 = 0;
		fflush(stdin);

		fopen_s(&p1, "D:\\library.txt", "r");
		i = 0;
		while (!feof(p1))
		{
			fscanf_s(p1, "%s ", bookimfor[i].number, sizeof(bookimfor[i].number));
			fscanf_s(p1, "%s ", &bookimfor[i].name, sizeof(bookimfor[i].name));
			fscanf_s(p1, "%s ", &bookimfor[i].author, sizeof(bookimfor[i].author));
			fscanf_s(p1, "%s ", &bookimfor[i].press, sizeof(bookimfor[i].press));
			fscanf_s(p1, "%s ", &bookimfor[i].category, sizeof(bookimfor[i].category));
			fscanf_s(p1, "%f ", &bookimfor[i].price);
			fscanf_s(p1, "%d ", &bookimfor[i].quantity);
			fscanf_s(p1, "%d\n", &bookimfor[i].time);
			i++;
		}
		fclose(p1);

		fopen_s(&p2, "D:\\memberbook.txt", "r");
		k = 0;
		while (!feof(p2))
		{
			fscanf_s(p2, "%s ", &bookgrasp[k].number, sizeof(bookgrasp[k].number));
			fscanf_s(p2, "%s ", &bookgrasp[k].name, sizeof(bookgrasp[k].name));
			fscanf_s(p2, "%s ", &bookgrasp[k].author, sizeof(bookgrasp[k].author));
			fscanf_s(p2, "%s ", &bookgrasp[k].press, sizeof(bookgrasp[k].press));
			fscanf_s(p2, "%s ", &bookgrasp[k].category, sizeof(bookgrasp[k].category));
			fscanf_s(p2, "%f ", &bookgrasp[k].price);
			fscanf_s(p2, "%s\n", &bookgrasp[k].account, sizeof(bookgrasp[k].account));
			k++;
		}
		fclose(p2);

		printf("��Ľ�����Ϣ����:\n");
		printf("|\t\t ��������������ͼ����Ϣ��������������    \t|\n");
		printf("|\t\t\t                                        |\n");
		printf("|���   ���� \t    ����\t������       ���    �۸�\t|\n");
		t = 0;
		while (t < k)
		{
			if (strcmp(bookgrasp[t].account, account) == 0)
			{
				printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f|\n", bookgrasp[t].number,
					bookgrasp[t].name, bookgrasp[t].author, bookgrasp[t].press,
					bookgrasp[t].category, bookgrasp[t].price);
			}
			t++;
		}

		printf("\n������Ҫ�黹������:\n");
		scanf_s("%s", search, 20);

		if (bookimfor[0].quantity == 0)
		{
			printf("��������κ���Ϣ\n���س������ز˵�");
			getchar();
			break;
		}
		else
		{
			for (n = 0; n < i; n++)
			{
				if (strcmp(bookimfor[n].name, search) == 0)
				{
					bookimfor[n].quantity++;

					if (bookgrasp[0].price == 0)
						printf("��û�н�����Ϣ\n");
					else
					{
						for (m = 0; m < k; m++)
						{
							if (strcmp(bookgrasp[m].account, account)==0 && strcmp(bookgrasp[m].name, search)==0)
							{
								flag2 = 1;
								for (l = m; l < k - 1; l++)
								{
									bookgrasp[l] = bookgrasp[l + 1];									
								}
								break;				
							}								
						}

						fopen_s(&p2, "D:\\memberbook.txt", "w");
						for (l = 0; l < k-1; l++)
						{
							fprintf(p2, "%s ", bookgrasp[l].number);
							fprintf(p2, "%s ", bookgrasp[l].name);
							fprintf(p2, "%s ", bookgrasp[l].author);
							fprintf(p2, "%s ", bookgrasp[l].press);
							fprintf(p2, "%s ", bookgrasp[l].category);
							fprintf(p2, "%f ", bookgrasp[l].price);
							fprintf(p2, "%s\n", bookgrasp[l].account);
						}
						fclose(p2);
						break;              //������for
					}

				}
			}

			if (n >= i || flag2 == 0)
				printf("��û�н�����Ϣ\n");
			if (n < i&&flag2 == 1)
			{
				fopen_s(&p1, "D:\\library.txt", "w");
				for (l = 0; l < i; l++)
				{
					fprintf(p1, "%s ", bookimfor[l].number);
					fprintf(p1, "%s ", bookimfor[l].name);
					fprintf(p1, "%s ", bookimfor[l].author);
					fprintf(p1, "%s ", bookimfor[l].press);
					fprintf(p1, "%s ", bookimfor[l].category);
					fprintf(p1, "%f ", bookimfor[l].price);
					fprintf(p1, "%d ", bookimfor[l].quantity);
					fprintf(p1, "%d\n", bookimfor[l].time);
				}
				fclose(p1);
				printf("����ɹ�!\n");
			}
			else			
				printf("����ʧ�ܣ�\n");

			printf("�Ƿ�������飿Y/y����N/n");
			getchar();
			choice = getchar();

			while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
			{
				printf("����������ָ���ַ�\n");
				getchar();
				printf("�Ƿ�������飿Y/y����N/n\n");
				choice = getchar();
			}
			if (choice == 'Y' || choice == 'y')
				flag1 = 1;
			else
				flag1 = 0;							
		}
	}
}
int check_repeat_ID(char idaccount[20])
{
	FILE *p1;
	int i, j;
	int flag1 = 0;
	member member[100];

	system("cls");
	fflush(stdin);

	fopen_s(&p1, "D:\\memimfor.txt", "r");
	i = 0;
	while (!feof(p1))
	{
		fscanf_s(p1, "%s ", member[i].ID, sizeof(member[i].ID));
		fscanf_s(p1, "%s ", member[i].password, sizeof(member[i].password));
		fscanf_s(p1, "%s ", member[i].passwordkey, sizeof(member[i].passwordkey));
		fscanf_s(p1, "%s ", member[i].name, sizeof(member[i].name));
		fscanf_s(p1, "%s ", member[i].sex, sizeof(member[i].sex));
		i++;
	}
	fclose(p1);

	for (j = 0; j < i; j++)
	{
		if (strcmp(member[j].ID, idaccount) == 0)
		{
			flag1 = 1;
			break;
		}
	}
	if (flag1)
		return 1;
	else
		return 0;
}
int compare_password(char password[20])
{
	fflush(stdin);
	char compare[20];
	int i;

	printf("����������:\n");
	scanf_s("%s", compare, 20);

	if (strcmp(compare, password) == 0)
	{
		printf("\a");
		return 1;
	}
	else
	{
		printf("\a");
		return 0;
	}

}
void member_log_up()
{
	FILE *p1;
	member member;
	char choice, choice2;
	int flag=1;

	system("cls");
	while (flag)
	{
		system("cls");
		fflush(stdin);

		printf("����������ע���id:\n");
		scanf_s("%s", member.ID, 20);

		if (compare_password(member.ID))
		{
			printf("���û����Ѿ���ע��\n���س�������ע��");
			getchar();
		}
		else
		{
			flag = 0;

			printf("�������������:\n");
			scanf_s("%s", member.password, 20);
			printf("����������ܳף������������룩:\n");
			scanf_s("%s", member.passwordkey, 20);
			printf("�������������:\n");
			scanf_s("%s", member.name, 20);
			printf("����������Ա�:\n");
			scanf_s("%s", member.sex, 20);

			printf("�Ƿ񱣴����ע����Ϣ��Y/y����N/n\n");
			getchar();
			choice = getchar();

			while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
			{
				printf("����������\n");
				getchar();
				choice = getchar();
			}

			if (choice == 'Y' || choice == 'y' || flag == 1)
			{
				fopen_s(&p1, "D:\\memimfor.txt", "a");
				fprintf(p1, "\n%s ", member.ID);
				fprintf(p1, "%s ", member.password);
				fprintf(p1, "%s ", member.passwordkey);
				fprintf(p1, "%s ", member.name);
				fprintf(p1, "%s ", member.sex);
				fclose(p1);
			}
			else
				printf("�����Ϣδ����\n");

			printf("�Ƿ����ע��?Y/y����N/n\n");
			getchar();
			choice2 = getchar();

			while (choice2 != 'Y'&&choice2 != 'y'&&choice2 != 'N'&&choice2 != 'n')
			{
				printf("����������\n");
				getchar();
				choice2 = getchar();
			}

			if (choice2 == 'Y' || choice2 == 'y')
				flag = 1;
			else
				flag = 0;
		}
	}
}
int user_account(char account[20])
{
	FILE *p1, *p2;
	int flag1 = 0, i, j, n, m, count = 0;
	char choice, newpassword[20], key[20];
	member member[100];
	bookgrasp bookgrasp[100];

	system("cls");
	fflush(stdin);

	fopen_s(&p1, "D:\\memimfor.txt", "r");
	i = 0;
	while (!feof(p1))
	{
		fscanf_s(p1, "%s ", &member[i].ID, sizeof(member[i].ID));
		fscanf_s(p1, "%s ", &member[i].password, sizeof(member[i].password));
		fscanf_s(p1, "%s ", &member[i].passwordkey, sizeof(member[i].passwordkey));
		fscanf_s(p1, "%s ", &member[i].name, sizeof(member[i].name));
		fscanf_s(p1, "%s\n",&member[i].sex, sizeof(member[i].sex));
		i++;
	}
	fclose(p1);

	fopen_s(&p2, "D:\\memberbook.txt", "r");
	j = 0;
	while (!feof(p2))
	{
		fscanf_s(p2, "%s ", &bookgrasp[j].number, sizeof(bookgrasp[j].number));
		fscanf_s(p2, "%s ", &bookgrasp[j].name, sizeof(bookgrasp[j].name));
		fscanf_s(p2, "%s ", &bookgrasp[j].author, sizeof(bookgrasp[j].author));
		fscanf_s(p2, "%s ", &bookgrasp[j].press, sizeof(bookgrasp[j].press));
		fscanf_s(p2, "%s ", &bookgrasp[j].category, sizeof(bookgrasp[j].category));
		fscanf_s(p2 ,"%f ", &bookgrasp[j].price);
		fscanf_s(p2, "%s\n", &bookgrasp[j].account, sizeof(bookgrasp[j].account));
		j++;
	}
	fclose(p2);

	if (bookgrasp[0].price == 0)
	{
		printf("ͼ������޽�����Ϣ\n���س������ز˵�\n");
		getchar();
	}

	else
	{
		for (n = 0; n < j; n++)
		{
			if (strcmp(member[n].ID, account) == 0)
			{
				printf("|\t\t��������������������Ϣ��������������    \t|\n");
				printf("|\t\t                                        \t|\n");
				printf("|\t\t����      �Ա�     ID          ����     \t|\n");
				printf("|\t\t%s        %s     %s         %s        \t|\n"
					, member[n].name, member[n].sex, member[n].ID, member[n].password);
				printf("|\t\t                                        \t|\n");
				printf("*                                       \t\t\t*\n\n\n");
				printf("|\t\t ��������������������Ϣ��������������    \t|\n");
				printf("|\t\t\t                                        |\n");
				printf("|���   ���� \t    ����\t������       ���    �۸�\t|\n");

				for (m = 0; m < j; m++)
				{
					if (strcmp(bookgrasp[m].account, account) == 0)
					{
						printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f|\n", bookgrasp[m].number,
							bookgrasp[m].name, bookgrasp[m].author, bookgrasp[m].press,
							bookgrasp[m].category, bookgrasp[m].price);
						count++;
					}					
				}
				printf("\n�����ڽ���%d����\n", count);
				printf("ͼ�������%d������������\n", j);

				printf("�Ƿ���Ҫ�޸����룿Y/y����N/n\n");
				
				choice = getchar();
				

				while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
				{
					printf("����������\n");
					getchar();
					choice = getchar();
				}
				if (choice == 'Y' || choice == 'y')
				{
					printf("�������ܳ�:\n");
					scanf_s("%s", key, 20);
					if (strcmp(member[n].passwordkey, key) == 0)
					{
						flag1 = 1;
						printf("������������:\n");
						scanf_s("%s", newpassword, 20);
						strcpy_s(member[n].password, newpassword);

						fopen_s(&p1, "D:\\memimfor.txt", "w");
						for (m = 0; m < i; m++)
						{
							fprintf(p1, "%s ", member[m].ID);
							fprintf(p1, "%s ", member[m].password);
							fprintf(p1, "%s ", member[m].passwordkey);
							fprintf(p1, "%s ", member[m].name);
							fprintf(p1, "%s\n", member[m].sex);
						}
						fclose(p1);
					}
					else
						printf("�����ܳ״���\n");

				}
				else
					flag1 = 0;

			}
		}
		if (flag1 == 1)
		{
			printf("�޸�����ɹ������س������ز˵�\n");
			getchar();
			return 1;
		}
		else
			return 0;
	}
	
}
void find_account()
{
	FILE *p1;
	member member[100];
	int flag = 1, i, j=3, n, m, mark = 0;
	char choice = NULL;                 //choice��Ҫ�ȳ�ʼ���������û������ʱ��choice��ֵ
	char blank[10] = "";
	char name[20], key[20], newpassword[20];


	system("cls");
	fflush(stdin);

	fopen_s(&p1, "D:\\memimfor.txt", "r");
	i = 0;
	while (!feof(p1))
	{
		fscanf_s(p1, "%s ", &member[i].ID, sizeof(member[i].ID));
		fscanf_s(p1, "%s ", &member[i].password, sizeof(member[i].password));
		fscanf_s(p1, "%s ", &member[i].passwordkey, sizeof(member[i].passwordkey));
		fscanf_s(p1, "%s ", &member[i].name, sizeof(member[i].name));
		fscanf_s(p1, "%s\n", &member[i].sex, sizeof(member[i].sex));
		i++;
	}
	fclose(p1);

	printf("����������û���:\n");
	scanf_s("%s", name, 20);

	if (strcmp(member[0].ID, blank) == 0)
		printf("���û�������!\n");
	else
	{
		for (n = 0; n < i; n++)
		{
			if (strcmp(member[n].ID, name) == 0)
			{
				mark = 1;
				while (flag)
				{
					printf("����������ܳ�:\n");
					scanf_s("%s", key, 20);
					if (strcmp(member[n].passwordkey, key) == 0)
					{
						printf("|\t\t��������������������Ϣ��������������    \t|\n");
						printf("|\t\t                                        \t|\n");
						printf("|\t\t����      �Ա�     ID          ����     \t|\n");
						printf("|\t\t%s        %s     %s         %s        \t|\n"
							, member[n].name, member[n].sex, member[n].ID, member[n].password);

						printf("�Ƿ��޸����룿Y/y����N/n\n");
						getchar();
						choice = getchar();
						while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
						{
							printf("����������\n");
							getchar();
							choice = getchar();
						}
						if (choice == 'Y' || choice == 'y')
						{
							printf("������������:\n");
							scanf_s("%s", newpassword, 20);
							strcpy_s(member[n].password, newpassword);
							flag = 0;
						}
						else
							flag = 0;							
					}
					else
					{
						j--;
						if (j != 0)
						{
							printf("�㻹��%d�������ܳ׵Ļ���\n", j);
							flag = 1;
						}
						else
						{
							printf("��Ļ����Ѿ�����\n���ڷ��ز˵�\n");
							flag = 0;
						}
					}

				}

			}
			
		}
		if (mark = 0)
			printf("����δע���Ա\n");
		else
		{
			if (choice != 'N'&&choice != 'n'&&choice!='\0')
			{
				fopen_s(&p1, "D:\\memimfor.txt", "w");
				for (m = 0; m < i; m++)
				{
					fprintf(p1, "%s ", member[m].ID);
					fprintf(p1, "%s ", member[m].password);
					fprintf(p1, "%s ", member[m].passwordkey);
					fprintf(p1, "%s ", member[m].name);
					fprintf(p1, "%s\n", member[m].sex);
				}
				fclose(p1);
				printf("���ѳɹ��һ��˻�!\n");
			}
		}
		printf("���س������ز˵�\n");
		getchar();
	}
}
int member_log_in(char account[20])
{
	FILE *p1;
	int flag1 = 0, flag2 = 1, i, n, k = 3;
	member member[100];
	char choice;

	system("cls");
	fflush(stdin);

	fopen_s(&p1, "D:\\memimfor.txt", "r");
	i = 0;
	while (!feof(p1))
	{
		fscanf_s(p1, "%s ", &member[i].ID, sizeof(member[i].ID));
		fscanf_s(p1, "%s ", &member[i].password, sizeof(member[i].password));
		fscanf_s(p1, "%s ", &member[i].passwordkey, sizeof(member[i].passwordkey));
		fscanf_s(p1, "%s ", &member[i].name, sizeof(member[i].name));
		fscanf_s(p1, "%s", &member[i].sex, sizeof(member[i].sex));
		i++;
	}
	fclose(p1);

	for (n = 0; n < i; n++)
	{
		if (strcmp(member[n].ID, account) == 0)
		{
			flag1 = 1;
			break;
		}
	}
	if (flag1 == 1)
	{
		while (flag2)
		{
			if (compare_password(member[n].password))
			{
				printf("������ȷ�����ڽ����Աϵͳ\n");
				return 1;
			}
			else
			{
				k--;
				if (k != 0)
				{
					printf("���������㻹��%d�λ���\n", k);
					flag2 = 1;
				}
				else
				{
					printf("��Ļ���������\n���س������ز˵�\n");
					getchar();
					return 0;
				}
			}
		}
	}
	else
	{
		printf("�㻹û��ע���Ա���Ƿ�����ע��?Y/y����N/n\n");
		getchar();
		choice = getchar();
		while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
		{
			printf("������ָ���ַ�\n");
			getchar();
			choice = getchar();
		}
		if (choice == 'Y' || choice == 'y')
		{
			member_log_up();
			return 2;
		}
		else
			return 0;
	}
}
void admin_watch()
{
	FILE *p1;
	int i, j;
	member member[100];

	system("cls");
	fflush(stdin);
	fopen_s(&p1, "D:\\memimfor.txt", "r");
	i = 0;
	while (!feof(p1))
	{
		fscanf_s(p1, "%s ", &member[i].ID, sizeof(member[i].ID));
		fscanf_s(p1, "%s ", &member[i].password, sizeof(member[i].password));
		fscanf_s(p1, "%s ", &member[i].passwordkey, sizeof(member[i].passwordkey));
		fscanf_s(p1, "%s ", &member[i].name, sizeof(member[i].name));
		fscanf_s(p1, "%s\n", &member[i].sex, sizeof(member[i].sex));
		i++;
	}
	fclose(p1);

	printf("һ����%d����Ա\n\n", i);
	printf("\t|\t  ����������������Ա��Ϣ��������������    \t\t|\n");
	printf("\t|\t                                        \t\t|\n");
	printf("\t|\t����      �Ա�            ID         ����        �ܳ� \t|\n");
	printf("\t|\t                                        \t\t|\n");
	for (j = 0; j < i; j++)
	{
		printf("\t|\t%-5s     %-10s     %-6s      %-5s       %-5s \t|\n"
			, member[j].name, member[j].sex, member[j].ID, member[j].password
		     ,member[j].passwordkey);
	}
	printf("���س������ز˵�\n");
	getchar();
	system("pause");
}
void bookgrasp_watch()
{
	FILE *p2;
	bookgrasp bookgrasp[100];
	int k, j;

	system("cls");
	fflush(stdin);
	fopen_s(&p2, "D:\\memberbook.txt", "r");
	k = 0;
	while (!feof(p2))
	{

		fscanf_s(p2, "%s ", &bookgrasp[k].number, sizeof(bookgrasp[k].number));
		fscanf_s(p2, "%s ", &bookgrasp[k].name, sizeof(bookgrasp[k].name));
		fscanf_s(p2, "%s ", &bookgrasp[k].author, sizeof(bookgrasp[k].author));
		fscanf_s(p2, "%s ", &bookgrasp[k].press, sizeof(bookgrasp[k].press));
		fscanf_s(p2, "%s ", &bookgrasp[k].category, sizeof(bookgrasp[k].category));
		fscanf_s(p2, "%f ", &bookgrasp[k].price);
		fscanf_s(p2, "%s\n", &bookgrasp[k].account, sizeof(bookgrasp[k].account));
		k++;
	}
	fclose(p2);

	if (bookgrasp[0].price == 0)
		printf("������޽��ļ�¼");
	else
	{
		printf("|\t\t ��������������ͼ����Ϣ��������������                 |\n");
		printf("|\t\t                                                      |\n");
		printf("|���   ���� \t    ����\t������       ���    �۸�    ����ID   |\n");
		for (j = 0; j < k; j++)
		{
			printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8s |\n", bookgrasp[j].number,
				bookgrasp[j].name, bookgrasp[j].author, bookgrasp[j].press,
				bookgrasp[j].category, bookgrasp[j].price,bookgrasp[j].account);
		}
	}
	printf("���س������ز˵�\n");
	getchar();
}
void passwordcircle()
{
	system("cls");
	printf("\n\n\n\t\t\t***================================*** \n");
	printf("\t\t\t                                   \n");
	printf("\t\t\t   �˻� (account):");
}
void find_account_circle()
{
	printf("\n\n");
	printf("\t\t=================H-E-L-P=================\n");
	printf("\t\t|                                       |\n");
	printf("\t\t*   �Ƿ�ͨ���ܳ���Ҫ�һ��˻���Y/y N/n   *\n");
	printf("\t\t|                                       |\n");
	printf("\t\t|                                       |\n");
	printf("\t\t----------------------------------------|\n");
}
void about_me()
{
	printf("|-------------------About me-------------------|\n");
	printf("|       ԭ��: Fenrari Yang                     |\n");
	printf("|       ��ַ: GitHubͼ�����ϵͳ����ǵ�c���԰�|\n");
	printf("|                                              |\n");
	printf("|       У��: ulyssesorz(���)                 |\n");
	printf("^                                              ^\n");
	printf("|  ps: �����޸ģ��˰汾����vs2017����������    |\n");
	printf("|----------------------------------------------|\n");
	system("pause");
}