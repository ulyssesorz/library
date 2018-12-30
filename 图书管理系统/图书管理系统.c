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
	void search_book();              //有几个缓存问题有待理解
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
		printf("\n请输入你的选择(1-5):\n");
		choice1 = getchar();
		while (choice1 != '1'&&choice1 != '2'&&choice1 != '3'&&choice1 != '4'&&choice1 != '5')
		{
			printf("请输入指定数字:\n");
			choice1 = getchar();
		}

		if (choice1 == '1')                     //会员注册
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
				flag = member_log_in(account1);          //第一次进入创建，第二次进入登录
			}
			if (flag == 1)
			{
				while (flag2&&flag3)
				{
					system("cls");
					menu2();
					printf("请输入你的选择(1-8):\n");
					choice2 = getchar();
					while (choice2 != '1'&&choice2 != '2'&&choice2 != '3'&&choice2 != '4'&&
						choice2 != '5'&&choice2 != '6'&&choice2 != '7'&&choice2 != '8')
					{
						printf("请输入指定数字:\n");
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
						printf("登录信息已改变，请重新登录\n");
						flag3 = 0;
						break;
					}
					case '8':flag2 = 0; printf("正在退出系统\n"); break;
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
					printf("请输入指定字符\n");
					getchar();
					account_choice = getchar();
				}
				if (account_choice == 'Y' || account_choice == 'y')
					find_account();

				flag2 = 1;
				flag3 = 1;
			}
		}
		else if (choice1 == '2')            //会员登录
		{
			system("cls");
			printf("正在进入会员登录系统\n");
			member_log_up();
		}
		else if (choice1 == '3')           //管理员登录
		{
			char admin_password[20];
			strcpy_s(admin_password, "2666");
			if (compare_password(admin_password))
			{
				printf("密码正确，正在登录\n");
				Sleep(1000);
				while (flag2)
				{
					system("cls");
					menu3();
					printf("请输入你的选择(1-8)\n");
					choice3 = getchar();
					while (choice3 != '1'&&choice3 != '2'&&choice3 != '3'&&choice3 != '4'&&
						choice3 != '5'&&choice3 != '6'&&choice3 != '7')
					{
						printf("请输入指定数字:\n");
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
					case '7':flag2 = 0; printf("正在退出管理员系统\n"); Sleep(1000); break;
					default:break;
					}
				}
			}
			else
			{
				printf("密码输入错误\n");
			}
			flag2 = 1;
		}
		else if (choice1 == '4')
		{
			system("cls");
			about_me();
			printf("按回车键退出\n");
			getchar();
		}
		else if (choice1 == '5')
		{
			flag1 = 0;
		}
	}

	system("cls");
	printf("你已安全退出系统，欢迎再次使用，按回车键关闭界面\n");
	getchar();
	return 0;
}
void menu1()
{
	system("color FC");
	printf("\n\n");
	printf("\t\t\t\t-------==-------------====-------------==--------\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t     **欢迎进入图书管理系统**    \t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [1] 会员登录                \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t^\t     [2] 会员注册               \t^\n");
	printf("\t\t\t\t^\t\t\t\t\t\t^\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t$\t     [3] 管理员登录              \t$\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t~\t     [4] 关于最新版本              \t~\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t     [5] 退出系统                  \t|\n");
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
	printf("\t\t\t\t|\t     ** 会员界面 **              \t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [1] 查找图书信息             \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t^\t     [2] 借阅图书                 \t^\n");
	printf("\t\t\t\t^\t\t\t\t\t\t^\n");
	printf("\t\t\t\t*\t     [3] 归还图书                 \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t$\t     [4] 所有图书信息             \t$\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [5] 价位书籍推荐             \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [6] 图书排行榜               \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t     [7] 你的账户信息             \t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [8] 退出用户界面             \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t-------==-------------====-------------==--------\n\n");
}
void menu3()
{
	system("color E0");
	printf("\n\n");
	printf("\t\t\t\t-------==-------------====-------------==--------\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t     ** 管理员界面 **              \t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [1] 添加图书                \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t^\t     [2] 删减图书                 \t^\n");
	printf("\t\t\t\t^\t\t\t\t\t\t^\n");
	printf("\t\t\t\t$\t     [3] 查找图书信息             \t$\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [4] 显示全部图书信息         \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [5] 显示所有会员信息          \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t|\t     [6] 显示所有借阅信息          \t|\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t*\t     [7] 退出管理员界面             \t*\n");
	printf("\t\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t\t-------==-------------====-------------==--------\n\n");
}
int check_repeat_book(char number[20])
{
	FILE *p1;
	int i=0, flag = 0,j;                // i是书籍的序号，第一本书，第二本书...
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

	system("cls");                  //清屏
	while (1)
	{
		fflush(stdin);
		flag = 0;

		printf("请输入图书编号:\n");
		scanf_s("%s", newbook.number,20);

		if (check_repeat_book(newbook.number))
		{
			printf("该数已存在，请按回车键重新添加。\n");
			getchar();
			flag = 1;
		}

		else
		{
			fflush(stdin);
			printf("请输入书名:\n");
			scanf_s("%s", newbook.name, 20);

			printf("请输入作者:\n");
			scanf_s("%s", newbook.author, 20);

			printf("请输入出版社:\n");
			scanf_s("%s", newbook.press, 20);

			printf("请输入类别（文学，理工，生活，情感..）:\n");
			scanf_s("%s", newbook.category, 20);

			printf("请输入价格:\n");
			scanf_s("%f", &newbook.price);

			printf("请输入馆藏量:\n");
			scanf_s("%d", &newbook.quantity);

			printf("请输入已借出数目:\n");
			scanf_s("%d", &newbook.time);

			fflush(stdin);
			printf("是否保存此书名？Y/y或者N/n\n");
			getchar();
			choice = getchar();

			while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
			{
				printf("请重新输入\n");
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
				printf("该书名已保存\n");
			}
			else
			{
				printf("该书目未保存\n");
			}

			printf("是否继续添加书目? Y/y或者N/n\n");
			getchar();
			choice = getchar();

			while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
			{
				printf("请重新输入\n");
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
		printf("无库存\n");
	else
	{
		printf("|\t\t ———————图书信息———————   \t\t   |\n");
		printf("|\t\t\t\t                                      \t   |\n");
		printf("|编号   书名 \t    作者\t出版社       类别    价格   馆藏量 已借阅数|\n");
	}
	for (j = 0; j < i; j++)
	{
		printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", bookimfor[j].number,
			bookimfor[j].name,bookimfor[j].author, bookimfor[j].press, 
			bookimfor[j].category,bookimfor[j].price, bookimfor[j].quantity, 
			bookimfor[j].time);
	}
	fflush(stdin);
	printf("按回车键返回上一级菜单\n");
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
		
			printf("\n请输入你想查询图书的方式:\n");
			printf("1、书名   2、编号   3、作者名\n");
			select = getchar();                          //不能用scanf_s

			printf("请输入你要查找的信息:\n");
			switch (select)
			{
			case '1':scanf_s("%s", name_compare, 20); strcpy_s(search, name_compare); flag2 = 0; break;
			case '2':scanf_s("%s", number_compare, 20); strcpy_s(search, number_compare); flag2 = 0; break;
			case '3':scanf_s("%s", author_compare, 20); strcpy_s(search, author_compare); flag2 = 0; break;
			default:break;
			}
			
			
		}
		flag2 = 1;                                     //千万不能删，否则无法继续查找
		if (bookimfor[0].quantity == 0)
		{
			printf("书库中未找到这本书\n");
			printf("按回车键继续");
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
					printf("|\t\t ———————图书信息———————   \t\t   |\n");
					printf("|\t\t\t\t                                      \t   |\n");
					printf("|编号   书名 \t    作者\t出版社       类别    价格   馆藏量 已借阅数|\n");
					printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", bookimfor[j].number,
						bookimfor[j].name, bookimfor[j].author, bookimfor[j].press,
						bookimfor[j].category, bookimfor[j].price, bookimfor[j].quantity,
						bookimfor[j].time); break;
				}
			}
				if (j >= i)
				{
					printf("没有找到你想要的书\n");
				}

				getchar();
				printf("是否继续查询？Y/y或者N/n\n");
				choice = getchar();

				while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
				{
					printf("请重新输入指定字符\n");
					getchar();
					printf("是否继续查询？Y/y或者N/n\n");
					choice = getchar();
				}
				
				if (choice == 'Y' || choice == 'y')
				{
					getchar();                           //不能漏
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

		printf("输入要删除的书籍的名称:\n");
		scanf_s("%s", search, 20);

		if (bookimfor[0].quantity == 0)
		{
			printf("书库中无任何信息\n");
			printf("按回车键返回主菜单");
			getchar();
			break;
		}

		else
		{
			for (j = 0; j < i; j++)               // i是书籍的数目
			{
				if (strcmp(bookimfor[j].name, search) != 0)    //书名不同进行下一次循环
				{
					continue;
				}
				if (j >= i)
					printf("书库中没有这本书\n");
				else
				{
					printf("确定删除这本书？Y/y或者N/n\n");
					getchar();           //每个choice=getchar() 之前都要加一个
					                     //否则choice无法接收					
					choice = getchar();

					while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
					{
						printf("请重新输入指定字符\n");						
						printf("确定删除这本书？Y/y或者N/n\n");
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
						printf("该书名已删除\n");
					}
					else
						printf("该书未删除\n");
				}
			}
			printf("是否继续删除？");
			getchar(); 
			choice = getchar();
			while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
			{
				printf("请重新输入指定字符\n");
				getchar();
				printf("是否继续删除？Y/y或者N/n\n");
				choice = getchar();
			}
			if (choice == 'Y' || choice == 'y')
				continue;
			else
				break;
			
		}//else结束

	}//while结束
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

	printf("请输入最低价格，我们会向你推荐低于此价格的书\n");
	scanf_s("%f", &price);

	if (bookimfor[0].quantity == 0)
	{
		printf("书库中无任何信息\n");
	}

	else
	{
		for (j = 0; j < i; j++)
		{
			if (bookimfor[j].price < price)
				count++;
		}

		if (count == 0)
			printf("\n没有找到比这个价格更低的书\n");
		else
		{
			printf("|\t\t ———————图书信息———————   \t\t   |\n");
			printf("|\t\t\t\t                                      \t   |\n");
			printf("|编号   书名 \t    作者\t出版社       类别    价格   馆藏量 已借阅数|\n");
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
	printf("\n按回车键返回菜单\n");
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
		printf("书库中无任何信息\n");

	for (j = 0; j < i - 1; j++)        // i是书本总数 冒泡算法
	{
		for (k = 0; k < i - 1 - j; k++)
		{
			if (bookimfor[k].time < bookimfor[k + 1].time)
			{
				bookimfor[5] = bookimfor[k];        //此处切记不能用bookimfor[100]，
 				bookimfor[k] = bookimfor[k + 1];    //因为只声明到[99],[100]不存在
				bookimfor[k + 1] = bookimfor[5];
			}
		}
	}
	
	printf("|\t ———————图书受欢迎排行榜———————   \t\t   |\n");
	printf("|\t\t\t\t                                      \t   |\n");
	printf("|编号   书名 \t    作者\t出版社       类别    价格   馆藏量 已借阅数|\n");
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

		printf("请输入你想借阅的书:\n");
		scanf_s("%s", search, 20);

		if (bookimfor[0].quantity == 0)
		{
			printf("书库中无任何信息\n");
			printf("按回车键返回菜单");
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
			printf("没有这本书的信息\n");
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
			printf("借书成功\n");
		}
		printf("是否继续借书？Y/y或者N/n  ");

		getchar();
		choice = getchar();
		while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
		{
			printf("请输入指定字符\n");
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

		printf("你的借阅信息如下:\n");
		printf("|\t\t ———————图书信息———————    \t|\n");
		printf("|\t\t\t                                        |\n");
		printf("|编号   书名 \t    作者\t出版社       类别    价格\t|\n");
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

		printf("\n请输入要归还的书名:\n");
		scanf_s("%s", search, 20);

		if (bookimfor[0].quantity == 0)
		{
			printf("书库中无任何信息\n按回车键返回菜单");
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
						printf("你没有借阅信息\n");
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
						break;              //跳出大for
					}

				}
			}

			if (n >= i || flag2 == 0)
				printf("你没有借阅信息\n");
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
				printf("还书成功!\n");
			}
			else			
				printf("还书失败！\n");

			printf("是否继续还书？Y/y或者N/n");
			getchar();
			choice = getchar();

			while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
			{
				printf("请重新输入指定字符\n");
				getchar();
				printf("是否继续还书？Y/y或者N/n\n");
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

	printf("请输入密码:\n");
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

		printf("请输入你想注册的id:\n");
		scanf_s("%s", member.ID, 20);

		if (compare_password(member.ID))
		{
			printf("该用户名已经被注册\n按回车键重新注册");
			getchar();
		}
		else
		{
			flag = 0;

			printf("请输入你的密码:\n");
			scanf_s("%s", member.password, 20);
			printf("请输入你的密匙（以免忘了密码）:\n");
			scanf_s("%s", member.passwordkey, 20);
			printf("请输入你的姓名:\n");
			scanf_s("%s", member.name, 20);
			printf("请输入你的性别:\n");
			scanf_s("%s", member.sex, 20);

			printf("是否保存这次注册信息？Y/y或者N/n\n");
			getchar();
			choice = getchar();

			while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
			{
				printf("请重新输入\n");
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
				printf("你的信息未保存\n");

			printf("是否继续注册?Y/y或者N/n\n");
			getchar();
			choice2 = getchar();

			while (choice2 != 'Y'&&choice2 != 'y'&&choice2 != 'N'&&choice2 != 'n')
			{
				printf("请重新输入\n");
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
		printf("图书馆中无借书信息\n按回车键返回菜单\n");
		getchar();
	}

	else
	{
		for (n = 0; n < j; n++)
		{
			if (strcmp(member[n].ID, account) == 0)
			{
				printf("|\t\t———————个人信息———————    \t|\n");
				printf("|\t\t                                        \t|\n");
				printf("|\t\t姓名      性别     ID          密码     \t|\n");
				printf("|\t\t%s        %s     %s         %s        \t|\n"
					, member[n].name, member[n].sex, member[n].ID, member[n].password);
				printf("|\t\t                                        \t|\n");
				printf("*                                       \t\t\t*\n\n\n");
				printf("|\t\t ———————借阅信息———————    \t|\n");
				printf("|\t\t\t                                        |\n");
				printf("|编号   书名 \t    作者\t出版社       类别    价格\t|\n");

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
				printf("\n你正在借阅%d本书\n", count);
				printf("图书馆中有%d本书正被借阅\n", j);

				printf("是否想要修改密码？Y/y或者N/n\n");
				
				choice = getchar();
				

				while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
				{
					printf("请重新输入\n");
					getchar();
					choice = getchar();
				}
				if (choice == 'Y' || choice == 'y')
				{
					printf("请输入密匙:\n");
					scanf_s("%s", key, 20);
					if (strcmp(member[n].passwordkey, key) == 0)
					{
						flag1 = 1;
						printf("请输入新密码:\n");
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
						printf("输入密匙错误\n");

				}
				else
					flag1 = 0;

			}
		}
		if (flag1 == 1)
		{
			printf("修改密码成功！按回车键返回菜单\n");
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
	char choice = NULL;                 //choice需要先初始化，否则用户名输错时，choice无值
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

	printf("请输入你的用户名:\n");
	scanf_s("%s", name, 20);

	if (strcmp(member[0].ID, blank) == 0)
		printf("此用户不存在!\n");
	else
	{
		for (n = 0; n < i; n++)
		{
			if (strcmp(member[n].ID, name) == 0)
			{
				mark = 1;
				while (flag)
				{
					printf("请输入你的密匙:\n");
					scanf_s("%s", key, 20);
					if (strcmp(member[n].passwordkey, key) == 0)
					{
						printf("|\t\t———————个人信息———————    \t|\n");
						printf("|\t\t                                        \t|\n");
						printf("|\t\t姓名      性别     ID          密码     \t|\n");
						printf("|\t\t%s        %s     %s         %s        \t|\n"
							, member[n].name, member[n].sex, member[n].ID, member[n].password);

						printf("是否修改密码？Y/y或者N/n\n");
						getchar();
						choice = getchar();
						while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
						{
							printf("请重新输入\n");
							getchar();
							choice = getchar();
						}
						if (choice == 'Y' || choice == 'y')
						{
							printf("请输入新密码:\n");
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
							printf("你还有%d次输入密匙的机会\n", j);
							flag = 1;
						}
						else
						{
							printf("你的机会已经用完\n正在返回菜单\n");
							flag = 0;
						}
					}

				}

			}
			
		}
		if (mark = 0)
			printf("你尚未注册会员\n");
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
				printf("你已成功找回账户!\n");
			}
		}
		printf("按回车键返回菜单\n");
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
				printf("输入正确，正在进入会员系统\n");
				return 1;
			}
			else
			{
				k--;
				if (k != 0)
				{
					printf("密码有误，你还有%d次机会\n", k);
					flag2 = 1;
				}
				else
				{
					printf("你的机会已用完\n按回车键返回菜单\n");
					getchar();
					return 0;
				}
			}
		}
	}
	else
	{
		printf("你还没有注册会员，是否现在注册?Y/y或者N/n\n");
		getchar();
		choice = getchar();
		while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
		{
			printf("请输入指定字符\n");
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

	printf("一共有%d名会员\n\n", i);
	printf("\t|\t  ———————会员信息———————    \t\t|\n");
	printf("\t|\t                                        \t\t|\n");
	printf("\t|\t姓名      性别            ID         密码        密匙 \t|\n");
	printf("\t|\t                                        \t\t|\n");
	for (j = 0; j < i; j++)
	{
		printf("\t|\t%-5s     %-10s     %-6s      %-5s       %-5s \t|\n"
			, member[j].name, member[j].sex, member[j].ID, member[j].password
		     ,member[j].passwordkey);
	}
	printf("按回车键返回菜单\n");
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
		printf("书库中无借阅记录");
	else
	{
		printf("|\t\t ———————图书信息———————                 |\n");
		printf("|\t\t                                                      |\n");
		printf("|编号   书名 \t    作者\t出版社       类别    价格    借阅ID   |\n");
		for (j = 0; j < k; j++)
		{
			printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8s |\n", bookgrasp[j].number,
				bookgrasp[j].name, bookgrasp[j].author, bookgrasp[j].press,
				bookgrasp[j].category, bookgrasp[j].price,bookgrasp[j].account);
		}
	}
	printf("按回车键返回菜单\n");
	getchar();
}
void passwordcircle()
{
	system("cls");
	printf("\n\n\n\t\t\t***================================*** \n");
	printf("\t\t\t                                   \n");
	printf("\t\t\t   账户 (account):");
}
void find_account_circle()
{
	printf("\n\n");
	printf("\t\t=================H-E-L-P=================\n");
	printf("\t\t|                                       |\n");
	printf("\t\t*   是否通过密匙需要找回账户？Y/y N/n   *\n");
	printf("\t\t|                                       |\n");
	printf("\t\t|                                       |\n");
	printf("\t\t----------------------------------------|\n");
}
void about_me()
{
	printf("|-------------------About me-------------------|\n");
	printf("|       原创: Fenrari Yang                     |\n");
	printf("|       地址: GitHub图书管理系统最多星的c语言版|\n");
	printf("|                                              |\n");
	printf("|       校正: ulyssesorz(张昊)                 |\n");
	printf("^                                              ^\n");
	printf("|  ps: 经过修改，此版本可在vs2017上正常运行    |\n");
	printf("|----------------------------------------------|\n");
	system("pause");
}