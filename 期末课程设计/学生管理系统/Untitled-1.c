#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	char studentnumber[20];
	char studentname[20];
	char classname[20];
	char birthday[20];
	float mark1;
	float mark2;
	float mark3;
	struct student* next;
};
char selectchar[10];
void adminmain();
void usermain();
extern void login();
extern void exitsystem()
{
	printf("ллʹ�ã�");
	exit(0);
}

void logininterface() {
	int select;
	printf("��ѡ��������ݣ�\n1.�û� 2.����Ա\n ע���ڱ������������������˳�ϵͳ��");
	scanf("%d", &select);
	switch (select)
	{
	case 1:usermain(); break;
	case 2:login(); break;
	default:break;
	}
};

struct student* readinfor()
{
	struct student* pointer = NULL, * head = NULL, * temp = NULL;
	FILE* fp = NULL;

	if ((fp = fopen("information.txt", "r+")) == NULL)
	{
		printf("can not open this file...");
		exit(1);
	}

	pointer = (struct student*)malloc(sizeof(struct student));
	if (NULL == pointer) {
		printf("malloc failed\n");
		return NULL;
	}

	fscanf(fp, "%s %s %s %s %f %f %f", pointer->studentnumber, pointer->studentname, pointer->classname, pointer->birthday, &(pointer->mark1), &(pointer->mark2), &(pointer->mark3));

	head = temp = pointer;

	while (!feof(fp))
	{
		pointer = (struct student*)malloc(sizeof(struct student));
		if (NULL == pointer) {
			printf("malloc failed\n");
			return NULL;
		}

		fscanf(fp, "%s %s %s %s %f %f %f", pointer->studentnumber, pointer->studentname, pointer->classname, pointer->birthday, &(pointer->mark1), &(pointer->mark2), &(pointer->mark3));

		temp->next = pointer;
		temp = pointer;
	}

	temp->next = NULL;

	return head;
}

struct student* headest;
/*����Ա*/
struct stutemp
{
	char numbertemp[20];
	char nametemp[20];
	char classtemp[20];
	char birthtemp[20];
	float marktemp1;
	float marktemp2;
	float marktemp3;
};
void savefile(struct student* head)
{
	if (head == NULL)
	{
		printf("����û��ѧ����Ϣ����������ѧ����Ϣ");
		return;
	}

	struct student* p = head;
	FILE* fp = NULL;
	fp = fopen("information.txt", "w+");
	if (!fp)
	{
		printf("�ļ�������\n");
	}
	if (fp == NULL) {
		exit(8);
	}
	while (p != NULL)
	{
		fprintf(fp, "%s %s %s %s %.2f %.2f %.2f", p->studentnumber, p->studentname, p->classname, p->birthday, p->mark1, p->mark2, p->mark3);
		if (p->next)
		{
			fprintf(fp, "\n");
		}
		p = p->next;
	}
	fclose(fp);
}
void edit()
{
	struct stutemp temp;
	FILE* fp;
	if ((fp = fopen("information.txt", "a")) == NULL)
	{
		printf("can not open this file...");
		exit(1);
	}
	int size = sizeof(struct stutemp);
	printf("������ѧ����ѧ�š�ѧ���������༶�����ա������������߼�����ɢ�ɼ���ÿ������һ���밴һ�λس���������ɺ�����0�Խ�������\n");
	scanf("%s%s%s%s%f%f%f", temp.numbertemp, temp.nametemp, temp.classtemp, temp.birthtemp, &temp.marktemp1, &temp.marktemp2, &temp.marktemp3);
	while (1)
	{
		rewind(fp);
		printf("---\n");
		fprintf(fp, "\n%s %s %s %s %.2f %.2f %.2f", temp.numbertemp, temp.nametemp, temp.classtemp, temp.birthtemp, temp.marktemp1, temp.marktemp2, temp.marktemp3);
		printf("===\n");
		printf("\n �Ƿ��������1����/2�˳���");
		int num = 1;
		scanf("%d", &num);
		system("cls");
		if (num == 2)
			break;
		printf("������ѧ����ѧ�š�ѧ���������༶�����ա������������߼�����ɢ�ɼ���ÿ������һ���밴һ�λس���������ɺ�����0�Խ�������\n");
		scanf("%s%s%s%s%f%f%f", temp.numbertemp, temp.nametemp, temp.classtemp, temp.birthtemp, &temp.marktemp1, &temp.marktemp2, &temp.marktemp3);
		printf(temp.numbertemp);
	}
	printf("��������ɡ�");
	adminmain();
}
void delte()
{
	char compare[64] = { 0 };
	printf("������Ҫɾ����ѧ��ѧ�ţ�");
	scanf("%s", compare);
	system("cls");
	struct student* head = readinfor();
	if (NULL == head)
	{
		printf("ѧ����ϢΪ��");
		return;
	}

	struct student* p = head;
	struct student* pre = NULL;

	while (NULL != p)
	{
		if (0 == strncmp(p->studentnumber, compare, strlen(compare)))
		{
			if (p == head)
			{
				head = head->next;
			}
			else
			{
				pre->next = p->next;
			}

			break;
		}

		pre = p;
		p = p->next;
	}

	free(p);
	savefile(head);
}

void repair()
{
	struct student* head = readinfor();
	struct student* p = head;
	int flag = 0;
	char studentnumber[20];
	printf("����������Ҫ�޸ĵ�ѧ����Ϣ��ѧ�ţ�");
	getchar();
	gets_s(studentnumber,20);

	while (NULL != p)
	{
		if (strcmp(p->studentnumber, studentnumber) == 0)
		{
			printf("��ʾ���޸���Ϣ��ʱ���޸���ģ�������ԭ������\n");
			printf("�������޸ĳ�:");
			scanf("%s", p->studentname);
			printf("���༶�޸ĳ�:");
			scanf("%s", p->classname);
			printf("�������޸ĳ�:");
			scanf("%f", &p->mark1);
			printf("����ɢ�޸ĳ�:");
			scanf("%f", &p->mark2);
			printf("�������߼��޸ĳ�:");
			scanf("%f", &p->mark3);
			flag = 1;
			savefile(head);
			printf("�޸ĳɹ���");
			break;
		}
		p = p->next;
	}

	if (!flag)
	{
		if (p)
			printf("�Բ��𣬲���������Ϊ %s ��ѧ��", p->studentname);
	}
}
void adminmain()
{
	int select;
	struct student* head = readinfor();
	printf("��ѡ����Ҫѡ��Ĺ��ܣ�\n1.����ѧ����Ȼ��Ϣ\n2.ɾ��ѧ����Ȼ��Ϣ\n3.�޸�ѧ����Ȼ��Ϣ\n");
	scanf("%d", &select);
	system("cls");
	if (select == 1)
		edit();
	else if (select == 2)
		delte();
	else if (select == 3)
		repair();
	else
		exitsystem();
}
void login()
{
	int frequency = 0;
	char str0[7] = { "123456" }, str1[7] = { 0 };
	printf("���������Ա���룺");
	scanf("%s", &str1);
	system("cls");
	if (strcmp(str0, str1) == 0)
		adminmain();
	else
	{
		frequency++;
		if (frequency < 5)
		{
			printf("����������������루����%d�λ��ᣩ��", 5 - frequency);
			scanf("%s", &str1);
			system("cls");
		}
		else
		{
			printf("����������󣬼���������ҳ��");
			logininterface();
		}
	}
}
/*�û�*/
void output(struct student* p)
{
	printf("%s\t", p->studentnumber);
	printf("%s\t", p->studentname);
	printf("%s\t", p->classname);
	printf("%s\t", p->birthday);
	printf("%.2f\t", p->mark1);
	printf("%.2f\t", p->mark2);
	printf("%.2f\t", p->mark3);
	printf("%.2f\t", p->mark1 * 1.0 + p->mark2 * 1.0 + p->mark3 * 1.0);
	printf("%.2f\t\n", (p->mark1 + p->mark2 + p->mark3) / 3);
}

void printAll()
{
	struct student* p = readinfor();
	printf("---------------------\n");
	printf("ѧ��\t����  �༶\t����\t\t����\t�����߼� ��ɢ\t�ܳɼ�\tƽ���ɼ�\n");
	while (p != NULL)
	{
		output(p);
		p = p->next;
	}
}

void findinfor()
{
	int select;
	struct student* p = readinfor();
	printf("����1����������ѧ����Ϣ������2�Բ�ѯ�ض�ѧ����Ϣ��");
	scanf("%d", &select);
	system("cls");
	if (select == 1)
		printAll();
	else if (select == 2)
	{
		printf("������ѧ�ţ�");
		scanf("%s", selectchar);
		system("cls");
		do
		{
			if (strcmp(p->studentnumber, selectchar) == 0)
			{
				output(p);
				exit(0);
			}
			p = p->next;
		} while (p);
	}
	else exit(0);
}
void printgrade()
{
	struct student* p = readinfor();
	double SUM = 0, AVERAGE = 0, average1 = 0, average2 = 0, average3 = 0, sum1 = 0, sum2 = 0, sum3 = 0;
	int choose;
	char studentnumber[20] = { 0 };
	printf("����������ѧ�ţ�");
	scanf("%s", studentnumber);
	system("cls");
	while (p)
	{
		if ((strcmp(p->studentnumber, studentnumber)) == 0)
		{
			SUM = (p->mark1 * 1.0 + p->mark2 * 1.0 + p->mark3 * 1.0);
			AVERAGE = SUM / 3.0;
			printf("����ܷ��ǣ� %f  ƽ�����ǣ� %f\n", SUM, AVERAGE);
			break;
		}
		p = p->next;
	}
	printf("��ȷ���Ƿ�������е��Ƴɼ�ƽ����:1.��    2.��  ");
	scanf("%d", &choose);
	system("cls");
	if (choose == 1)
	{
		while (p)
		{
			sum1 += p->mark1;
			sum2 += p->mark2;
			sum3 += p->mark3;
			p = p->next;
		}
		average1 = sum1 / 3.0;
		average2 = sum2 / 3.0;
		average3 = sum3 / 3.0;
		printf("������Ŀƽ���ɼ�Ϊ%.2f \n�����߼���Ŀƽ���ɼ�Ϊ%.2f\n��ɢ��ѧ��Ŀƽ���ɼ�Ϊ%.2f\n", average1, average2, average3);
	}
	else
		printf("please press any key to continue.\n");
}
void SUMhighest()
{
	struct student* p = readinfor();
	struct student* head = readinfor();
	float HIGHESTSUM = 0, temp = 0, temp1 = 0;
	int counter = 0;
	do
	{
		temp = (p->mark1 + p->mark2 + p->mark3);
		if (HIGHESTSUM > temp)
			HIGHESTSUM = HIGHESTSUM;
		else
			HIGHESTSUM = temp;
		p = p->next;
	} while (p);
	p = head;
	do
	{
		temp1 = (p->mark1 + p->mark2 + p->mark3);
		if (temp1 == HIGHESTSUM)
		{
			printf("�ܷ����%.2f", HIGHESTSUM);
			counter++;
		}
		p = p->next;
	} while (p);
	printf("�ܷ���߹���%d��", counter);
}
void mark1highest()
{
	int item = 0;
	struct student* p = readinfor();
	float HIGHESTSUM = 0, temp = 0, temp1 = 0;
	int counter = 0;
	do
	{
		temp = p->mark1;
		if (HIGHESTSUM > temp)
			HIGHESTSUM = HIGHESTSUM;
		else
			HIGHESTSUM = temp;
		p = p->next;
	} while (p);
	p = headest;
	do
	{
		temp1 = p->mark1;
		if (temp1 == HIGHESTSUM)
		{
			if (item == 0) {
				printf("\n�ܷ����%.2f\n", HIGHESTSUM);
				item++;
			}
			counter++;
		}
		p = p->next;
	} while (p);
	printf("�ܷ���߹���%d��\n", counter);
	return;
}
void mark2highest()
{
	int item = 0;
	struct student* p = readinfor();
	float HIGHESTSUM = 0, temp = 0, temp1 = 0;
	int counter = 0;
	do
	{
		temp = p->mark2;
		if (HIGHESTSUM > temp)
			HIGHESTSUM = HIGHESTSUM;
		else
			HIGHESTSUM = temp;
		p = p->next;
	} while (p);
	p = headest;
	do
	{
		temp1 = p->mark2;
		if (temp1 == HIGHESTSUM)
		{
			if (item == 0) {
				item++;
				printf("�ܷ����%.2f\n", HIGHESTSUM);
			}
			counter++;
		}
		p = p->next;
	} while (p);
	printf("�ܷ���߹���%d��\n", counter);
}
void mark3highest()
{
	struct student* p = readinfor();
	int item = 0;
	float HIGHESTSUM = 0, temp = 0, temp1 = 0;
	int counter = 0;
	do
	{
		temp = p->mark3;
		if (HIGHESTSUM > temp)
			HIGHESTSUM = HIGHESTSUM;
		else
			HIGHESTSUM = temp;
		p = p->next;
	} while (p);
	p = headest;
	do
	{
		temp1 = p->mark3;
		if (temp1 == HIGHESTSUM)
		{
			if (item == 0)
			{
				printf("\n�ܷ����%.2f\n", HIGHESTSUM);
				item++;
			}
			counter++;
		}
		p = p->next;
	} while (p);
	printf("�ܷ���߹���%d��\n", counter);
}
void highestgrade()
{
	int choose;
	getchar();
	printf("*1.�ܷ���ߵ�ѧ����ѧ�š������ͳɼ�\n");
	printf("*2.������ߵ�ѧ����ѧ�š������ͳɼ�\n");
	printf("*3.�����߼��ܷ���ߵ�ѧ����ѧ�š������ͳɼ�\n");
	printf("*4.��ɢ��ѧ�ܷ���ߵ�ѧ����ѧ�š������ͳɼ�\n");
	printf("���������ѡ��\n");
	scanf("%d", &choose);
	system("cls");
	switch (choose)
	{
	case 1:SUMhighest(); break;
	case 2:mark1highest(); break;
	case 3:mark2highest(); break;
	case 4:mark3highest(); break;
	default:printf("entr date error\n"); exit(0);
	}
}
float average1()
{
	float aver;
	struct student* p = readinfor();
	float sum = 0; int counter = 0;
	while (p)
	{
		sum += p->mark1;
		counter++;
		p = p->next;
	}
	aver = sum / counter;
	return aver;
}

float average2()
{
	struct student* p = readinfor();
	float aver;
	float sum = 0; int counter = 0;
	while (p)
	{
		sum += p->mark2;
		counter++;
		p = p->next;
	}
	aver = sum / counter;
	return aver;

}
float average3()
{
	struct student* p = readinfor();
	float aver;
	float sum = 0; int counter = 0;
	while (p)
	{
		sum += p->mark3;
		counter++;
		p = p->next;
	}
	aver = sum / counter;
	return aver;

}
void average()
{
	float aver1, aver2, aver3;
	aver1 = average1();
	printf("������ƽ���ɼ�%.2f\n", aver1);
	aver2 = average2();
	printf("�����߼���ƽ���ɼ�%.2f\n", aver2);
	aver3 = average3();
	printf("��ɢ��ѧ��ƽ���ɼ�%.2f\n", aver3);
}
void level1()
{
	struct student* p = readinfor();
	float a = 0, b = 0, c = 0, d = 0, e = 0, counter = 0;
	while (p)
	{
		if (p->mark1 >= 90 && p->mark1 <= 100)
			a++;
		if (p->mark1 >= 80 && p->mark1 <= 89)
			b++;
		if (p->mark1 >= 70 && p->mark1 <= 79)
			c++;
		if (p->mark1 >= 60 && p->mark1 <= 69)
			d++;
		if (p->mark1 >= 0 && p->mark1 < 60)
			e++;
		counter++;
		p = p->next;
	}
	printf("���� A��ѧ��%.0f����ռ%.2f%%\n", a, a * 100 / counter);
	printf("���� B��ѧ��%.0f����ռ%.2f%%\n", b, b * 100 / counter);
	printf("���� C��ѧ��%.0f����ռ%.2f%%\n", c, c * 100 / counter);
	printf("���� D��ѧ��%.0f����ռ%.2f%%\n", d, d * 100 / counter);
	printf("���� E��ѧ��%.0f����ռ%.2f%%\n", e, e * 100 / counter);

}
void level2()
{
	struct student* p = readinfor();
	float a = 0, b = 0, c = 0, d = 0, e = 0, counter = 0;
	while (p)
	{
		if (p->mark2 >= 90 && p->mark2 <= 100)
			a++;
		if (p->mark2 >= 80 && p->mark2 <= 89)
			b++;
		if (p->mark2 >= 70 && p->mark2 <= 79)
			c++;
		if (p->mark2 >= 60 && p->mark2 <= 69)
			d++;
		if (p->mark2 >= 0 && p->mark2 < 60)
			e++;
		counter++;
		p = p->next;
	}
	printf("�����߼� A��ѧ��%.0f����ռ%.2f%%\n", a, a * 100 / counter);
	printf("�����߼� B��ѧ��%.0f����ռ%.2f%%\n", b, b * 100 / counter);
	printf("�����߼� C��ѧ��%.0f����ռ%.2f%%\n", c, c * 100 / counter);
	printf("�����߼� D��ѧ��%.0f����ռ%.2f%%\n", d, d * 100 / counter);
	printf("�����߼� E��ѧ��%.0f����ռ%.2f%%\n", e, e * 100 / counter);


}
void level3()
{
	struct student* p = readinfor();
	float a = 0, b = 0, c = 0, d = 0, e = 0, counter = 0;
	while (p)
	{
		if (p->mark3 >= 90 && p->mark3 <= 100)
			a++;
		if (p->mark3 >= 80 && p->mark3 <= 89)
			b++;
		if (p->mark3 >= 70 && p->mark3 <= 79)
			c++;
		if (p->mark3 >= 60 && p->mark3 <= 69)
			d++;
		if (p->mark3 >= 0 && p->mark3 < 60)
			e++;
		counter++;
		p = p->next;
	}
	printf("��ɢ��ѧ A��ѧ��%.0f����ռ%.2f%%\n", a, a * 100 / counter);
	printf("��ɢ��ѧ B��ѧ��%.0f����ռ%.2f%%\n", b, b * 100 / counter);
	printf("��ɢ��ѧ C��ѧ��%.0f����ռ%.2f%%\n", c, c * 100 / counter);
	printf("��ɢ��ѧ D��ѧ��%.0f����ռ%.2f%%\n", d, d * 100 / counter);
	printf("��ɢ��ѧ E��ѧ��%.0f����ռ%.2f%%\n", e, e * 100 / counter);
}
void level()
{
	int select;
	printf("��ѡ����Ҫ��ѯ�Ŀ�Ŀ��1.����\n2.�����߼�\n3.��ɢ��ѧ\n4.��������\n");
	scanf("%d", &select);
	system("cls");
	switch (select)
	{
	case 1:level1(); break;
	case 2:level2(); break;
	case 3:level3(); break;
	case 4:level1(); level2(); level3(); break;
	default:exitsystem();
	}
}
void counter1()
{
	float aver, counter1 = 0, counter2 = 0, counter3 = 0;
	aver = average1();
	struct student* p = readinfor();
	while (p)
	{
		if (p->mark1 > aver)
		{
			counter1++;
		}
		if (p->mark1 < aver)
		{
			counter3++;
		}
		if (p->mark1 == aver)
		{
			counter2++;
		}
		p = p->next;
	}
	printf("����ƽ���ɼ�%f\n", aver);
	printf("����ƽ���ɼ�����%.0f����\n", counter1);
	printf("����ƽ���ɼ�����%.0f����\n", counter2);
	printf("����ƽ���ɼ�����%.0f����\n", counter3);
}
void counter2()
{
	float aver;
	int counter1 = 0, counter2 = 0, counter3 = 0;
	aver = average2();
	struct student* p = readinfor();
	while (p)
	{
		if (p->mark2 > aver)
		{
			counter1++;
		}
		if (p->mark2 < aver)
		{
			counter3++;
		}
		if (p->mark2 == aver)
		{
			counter2++;
		}
		p = p->next;
	}
	printf("�����߼�ƽ���ɼ�%f\n", aver);
	printf("����ƽ���ɼ�����%d����\n", counter1);
	printf("����ƽ���ɼ�����%d����\n", counter2);
	printf("����ƽ���ɼ�����%d����\n", counter3);
}
void counter3()
{
	float aver, counter1 = 0, counter2 = 0, counter3 = 0;
	aver = average3();
	struct student* p = readinfor();
	while (p)
	{
		if (p->mark3 > aver)
		{
			counter1++;
		}
		if (p->mark3 < aver)
		{
			counter3++;
		}
		if (p->mark3 == aver)
		{
			counter2++;
		}
		p = p->next;
	}
	printf("��ɢ��ѧƽ���ɼ�%f\n", aver);
	printf("����ƽ���ɼ�����%.0f����\n", counter1);
	printf("����ƽ���ɼ�����%.0f����\n", counter2);
	printf("����ƽ���ɼ�����%.0f����\n", counter3);
}
void counter()
{
	int select;
	printf("��ѡ����Ҫ��ѯ�Ŀ�Ŀ��\n");
	printf("1.������Ŀƫ�����\n");
	printf("2.�����߼���Ŀƫ�����\n");
	printf("3.��ɢ��ѧ��Ŀƫ�����\n4.��������\n");
	scanf("%d", &select);
	system("cls");
	switch (select)
	{
	case 1:counter1(); break;
	case 2:counter2(); break;
	case 3:counter3(); break;
	case 4:counter1(); counter2(); counter3(); break;
	default:exitsystem();
	}
}
void findscore()
{
	int select;
	printf("��ѡ����Ҫ���еĹ��ܣ�\n");
	printf("1.����ѧ�Ų�ѯѧ�����ܷ֡�ƽ���֣���ѯÿ�ſγ̵�ƽ����.\n2.��ѯ�ֻܷ򵥿���ߵ�ѧ����ѧ�š������ͳɼ�\n3.��ѯ����ͬѧÿ�ſγ̵�ƽ����\n4.��ѯ�ɼ���ͬ�ȼ���������ռ�ٷֱ�\n5.��ѯƽ���ɼ��Լ����ڡ����ں͵���ƽ���ɼ�������\n");
	scanf("%d", &select);
	system("cls");
	switch (select)
	{
	case 1:printgrade(); break;
	case 2:highestgrade(); break;
	case 3:average(); break;
	case 4:level(); break;
	case 5:counter(); break;
	default:exit(0); break;
	}
}
void usermain()
{
	int select;
	printf("��ѡ����Ҫ���еĹ��ܣ�\n");
	printf("1.��ѯѧ����Ȼ��Ϣ\n2.��ѯ����\n");
	scanf("%d", &select);
	system("cls");
	if (select == 1)
	{
		findinfor();
	}
	else if (select == 2)
	{
		findscore();
	}
	else
	{
		exitsystem();
	}
}
/*������*/
int main(void)
{
	headest = readinfor();
	logininterface();

	printf("ллʹ�ã�");
	return 0;
}