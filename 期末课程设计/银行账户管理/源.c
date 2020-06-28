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
	printf("�����Ѹ���!\n");
}
void Display(int p)
{
	printf("�ʺ�:%s ���֤:%s ����:%s ��ַ:%s ���:%f\n", acc[p].accountid,acc[p].customerid, acc[p].name, acc[p].address, acc[p].balance);
}
void increase()
{
	int i;
	printf("�������ʺ�:");
	scanf("%s", temp.accountid);
		for (i = 0; i <= index - 1; i++)
		{
			if (strcmp(acc[i].accountid, temp.accountid) == 0)
			{
				flag++;
				system("cls");
				printf("�˺��Ѵ��ڣ������������˺�...\n");
				increase();
			}
		}
	if (flag == 0)
	{
		strcpy(acc[index].accountid, temp.accountid);
		printf("���������֤����:");
		scanf("%s", acc[index].customerid);
		printf("����������:");
		scanf("%s", acc[index].name);
		printf("�������ַ:");
		scanf("%s", acc[index].address);
		printf("��������:");
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
	printf("������Ҫɾ�����ʺ�:");
	scanf("%s", id);
	system("cls");
	for (i = 0; i < index; i++)
		if (!del[i])
			if (strcmp(id, acc[i].accountid) == 0)
			{
				del[i] = 1;
				SaveFile();
				printf("ɾ���ɹ�!\n");
				return;
			}
	printf("ɾ��ʧ��,���ʺŲ�����!\n");
}
void admine()
{
	int i,choice;
	char id[10] = {0};
	printf("������Ҫ�޸ĵ��ʺ�:");
	scanf("%s", id);
	system("cls");
	for (i = 0; i < index; i++)
		if (!del[i])
			if (strcmp(id, acc[i].accountid) == 0)
			{
				printf("��������Ҫ�޸ĵ���Ŀ\n1.���֤����\n2.����\n3.��ַ\n4.���\n");
				scanf("%d", &choice);
				switch (choice)
				{
				case 1:printf("���������֤����:"); scanf("%s", acc[i].customerid); break;
				case 2:printf("����������:"); scanf("%s", acc[i].name); break;
				case 3:printf("�������ַ:"); scanf("%s", acc[i].address); break;
				case 4:printf("��������:"); scanf("%f", &acc[i].balance); break;
				}
				printf("�޸ĳɹ�!\n");
				SaveFile();
				return;
			}
	printf("�޸�ʧ��,���ʺŲ�����!\n");
}
void search()
{
	int i;
	char id[10] = {0};
	printf("������Ҫ��ѯ���ʺ�:");
	scanf("%s", id);
	system("cls");
	for (i = 0; i < index; i++)
		if (!del[i])
			if (strcmp(id, acc[i].accountid) == 0)
			{
				printf("��ѯ�ɹ�!\n");
				Display(i);
				return;
			}
	printf("��ѯʧ��,���ʺŲ�����!\n");
}
void Menu()
{
	printf("��ӭʹ�����й���ϵͳ\n");
	printf("1.¼�����˻�\n");
	printf("2.��ѯ�˻���Ϣ\n");
	printf("3.�޸��˻���Ϣ\n");
	printf("4.ɾ���˻���Ϣ\n");
	printf("0.�˳�\n");
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
		printf("��ѡ���ܣ�");
		scanf("%d", &flag);
		system("cls");
		while (flag < 0 || flag>4)
		{
			printf("������ѡ��:");
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
			printf("ллʹ��!\n");
			return 0;
		}
	}
	return 0;
}