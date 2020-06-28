#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 200
typedef struct account
{
	char accountid[10];
	char customerid[30];
	char name[20];
	char address[30];
	float balance;

}Account;
struct temp
{
	char accountid[10];
	char customerid[30];
	char name[20];
	char address[30];
	float balance;
}temp;
Account acc[MAX];
int index = 0;
int del[MAX] = { 0 };
int flag=0;
void ReadFile()
{
	FILE* fp;
	fp = fopen("account.txt", "r");
	if (fp==NULL)
		printf("malloc error...");
	while (fscanf(fp, "%s %s %s %s %f", acc[index].accountid, acc[index].customerid, acc[index].name,acc[index].address, &acc[index].balance) != EOF)
	{
		index++;
	}
	fclose(fp);
}
void SaveFile()
{
	FILE* fp;
	int i;
	fp = fopen("account.txt", "w");
	if (fp == NULL)
	{
		printf("malloc error...\n");
		return;
	}
	for (i = 0; i < index; i++)
		if (!del[i])
			fprintf(fp, "%s %s %s %s %lf\n", acc[i].accountid, acc[i].customerid, acc[i].name,acc[i].address, acc[i].balance);
	fclose(fp);
	printf("数据已更新!\n");
}
void Display(int p)
{
	printf("帐号:%s 身份证:%s 姓名:%s 地址:%s 余额:%f\n", acc[p].accountid,acc[p].customerid, acc[p].name, acc[p].address, acc[p].balance);
}
void increase()
{
	int i;
	printf("请输入帐号:");
	scanf("%s", temp.accountid);
		for (i = 0; i <= index - 1; i++)
		{
			if (strcmp(acc[i].accountid, temp.accountid) == 0)
			{
				flag++;
				system("cls");
				printf("账号已存在，请输入其他账号...\n");
				increase();
			}
		}
	if (flag == 0)
	{
		strcpy(acc[index].accountid, temp.accountid);
		printf("请输入身份证号码:");
		scanf("%s", acc[index].customerid);
		printf("请输入姓名:");
		scanf("%s", acc[index].name);
		printf("请输入地址:");
		scanf("%s", acc[index].address);
		printf("请输入存款:");
		scanf("%f", &acc[index].balance);
		system("cls");
		del[index] = 0;
		index++;
		SaveFile();
	}
	else
		flag--;
}
void dele()
{
	int i;
	char id[10] = {0};
	printf("请输入要删除的帐号:");
	scanf("%s", id);
	system("cls");
	for (i = 0; i < index; i++)
		if (!del[i])
			if (strcmp(id, acc[i].accountid) == 0)
			{
				del[i] = 1;
				SaveFile();
				printf("删除成功!\n");
				return;
			}
	printf("删除失败,该帐号不存在!\n");
}
void admine()
{
	int i,choice;
	char id[10] = {0};
	printf("请输入要修改的帐号:");
	scanf("%s", id);
	system("cls");
	for (i = 0; i < index; i++)
		if (!del[i])
			if (strcmp(id, acc[i].accountid) == 0)
			{
				printf("请输入需要修改的项目\n1.身份证号码\n2.姓名\n3.地址\n4.存款\n");
				scanf("%d", &choice);
				switch (choice)
				{
				case 1:printf("请输入身份证号码:"); scanf("%s", acc[i].customerid); break;
				case 2:printf("请输入姓名:"); scanf("%s", acc[i].name); break;
				case 3:printf("请输入地址:"); scanf("%s", acc[i].address); break;
				case 4:printf("请输入存款:"); scanf("%f", &acc[i].balance); break;
				}
				printf("修改成功!\n");
				SaveFile();
				return;
			}
	printf("修改失败,该帐号不存在!\n");
}
void search()
{
	int i;
	char id[10] = {0};
	printf("请输入要查询的帐号:");
	scanf("%s", id);
	system("cls");
	for (i = 0; i < index; i++)
		if (!del[i])
			if (strcmp(id, acc[i].accountid) == 0)
			{
				printf("查询成功!\n");
				Display(i);
				return;
			}
	printf("查询失败,该帐号不存在!\n");
}
void Menu()
{
	printf("欢迎使用银行管理系统\n");
	printf("1.录入新账户\n");
	printf("2.查询账户信息\n");
	printf("3.修改账户信息\n");
	printf("4.删除账户信息\n");
	printf("0.退出\n");
	printf("Please select a function id(0-4) to execute\n");
	printf("  ---------------------------------------- \n");
}
int main(void)
{
	int flag;
	ReadFile();
	while (1)
	{
		Menu();
		printf("请选择功能：");
		scanf("%d", &flag);
		system("cls");
		while (flag < 0 || flag>4)
		{
			printf("请重新选择:");
			Menu();
			scanf("%d", &flag);
			system("cls");
		}
		switch (flag)
		{
		case 1:
			increase();
			break;
		case 2:
			search();
			break;
		case 3:
			admine();
			break;
		case 4:
			dele();
			break;
		case 0:
			printf("谢谢使用!\n");
			return 0;
		}
	}
	return 0;
}