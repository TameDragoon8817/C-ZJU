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
	printf("谢谢使用！");
	exit(0);
}

void logininterface() {
	int select;
	printf("请选择您的身份：\n1.用户 2.管理员\n 注：在本程序中输入其他将退出系统。");
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
/*管理员*/
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
		printf("现在没有学生信息，请先输入学生信息");
		return;
	}

	struct student* p = head;
	FILE* fp = NULL;
	fp = fopen("information.txt", "w+");
	if (!fp)
	{
		printf("文件不存在\n");
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
	printf("请输入学生的学号、学生姓名、班级、生日、高数、数字逻辑、离散成绩（每输入完一项请按一次回车，输入完成后输入0以结束）：\n");
	scanf("%s%s%s%s%f%f%f", temp.numbertemp, temp.nametemp, temp.classtemp, temp.birthtemp, &temp.marktemp1, &temp.marktemp2, &temp.marktemp3);
	while (1)
	{
		rewind(fp);
		printf("---\n");
		fprintf(fp, "\n%s %s %s %s %.2f %.2f %.2f", temp.numbertemp, temp.nametemp, temp.classtemp, temp.birthtemp, temp.marktemp1, temp.marktemp2, temp.marktemp3);
		printf("===\n");
		printf("\n 是否继续？（1继续/2退出）");
		int num = 1;
		scanf("%d", &num);
		system("cls");
		if (num == 2)
			break;
		printf("请输入学生的学号、学生姓名、班级、生日、高数、数字逻辑、离散成绩（每输入完一项请按一次回车，输入完成后输入0以结束）：\n");
		scanf("%s%s%s%s%f%f%f", temp.numbertemp, temp.nametemp, temp.classtemp, temp.birthtemp, &temp.marktemp1, &temp.marktemp2, &temp.marktemp3);
		printf(temp.numbertemp);
	}
	printf("操作已完成。");
	adminmain();
}
void delte()
{
	char compare[64] = { 0 };
	printf("请输入要删除的学生学号：");
	scanf("%s", compare);
	system("cls");
	struct student* head = readinfor();
	if (NULL == head)
	{
		printf("学生信息为空");
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
	printf("请输入你需要修改的学生信息的学号：");
	getchar();
	gets_s(studentnumber,20);

	while (NULL != p)
	{
		if (strcmp(p->studentnumber, studentnumber) == 0)
		{
			printf("提示：修改信息的时，修改则改，不改则原样输入\n");
			printf("将姓名修改成:");
			scanf("%s", p->studentname);
			printf("将班级修改成:");
			scanf("%s", p->classname);
			printf("将高数修改成:");
			scanf("%f", &p->mark1);
			printf("将离散修改成:");
			scanf("%f", &p->mark2);
			printf("将数字逻辑修改成:");
			scanf("%f", &p->mark3);
			flag = 1;
			savefile(head);
			printf("修改成功！");
			break;
		}
		p = p->next;
	}

	if (!flag)
	{
		if (p)
			printf("对不起，不存在姓名为 %s 的学生", p->studentname);
	}
}
void adminmain()
{
	int select;
	struct student* head = readinfor();
	printf("请选择您要选择的功能：\n1.增加学生自然信息\n2.删除学生自然信息\n3.修改学生自然信息\n");
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
	printf("请输入管理员密码：");
	scanf("%s", &str1);
	system("cls");
	if (strcmp(str0, str1) == 0)
		adminmain();
	else
	{
		frequency++;
		if (frequency < 5)
		{
			printf("密码错误，请重新输入（还有%d次机会）：", 5 - frequency);
			scanf("%s", &str1);
			system("cls");
		}
		else
		{
			printf("密码输入错误，即将返回主页面");
			logininterface();
		}
	}
}
/*用户*/
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
	printf("学号\t姓名  班级\t生日\t\t高数\t数字逻辑 离散\t总成绩\t平均成绩\n");
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
	printf("输入1以生成所有学生信息，输入2以查询特定学生信息：");
	scanf("%d", &select);
	system("cls");
	if (select == 1)
		printAll();
	else if (select == 2)
	{
		printf("请输入学号：");
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
	printf("请输入您的学号：");
	scanf("%s", studentnumber);
	system("cls");
	while (p)
	{
		if ((strcmp(p->studentnumber, studentnumber)) == 0)
		{
			SUM = (p->mark1 * 1.0 + p->mark2 * 1.0 + p->mark3 * 1.0);
			AVERAGE = SUM / 3.0;
			printf("你的总分是： %f  平均分是： %f\n", SUM, AVERAGE);
			break;
		}
		p = p->next;
	}
	printf("请确定是否输出所有单科成绩平均分:1.是    2.否  ");
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
		printf("高数科目平均成绩为%.2f \n数字逻辑科目平均成绩为%.2f\n离散数学科目平均成绩为%.2f\n", average1, average2, average3);
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
			printf("总分最高%.2f", HIGHESTSUM);
			counter++;
		}
		p = p->next;
	} while (p);
	printf("总分最高共有%d人", counter);
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
				printf("\n总分最高%.2f\n", HIGHESTSUM);
				item++;
			}
			counter++;
		}
		p = p->next;
	} while (p);
	printf("总分最高共有%d人\n", counter);
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
				printf("总分最高%.2f\n", HIGHESTSUM);
			}
			counter++;
		}
		p = p->next;
	} while (p);
	printf("总分最高共有%d人\n", counter);
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
				printf("\n总分最高%.2f\n", HIGHESTSUM);
				item++;
			}
			counter++;
		}
		p = p->next;
	} while (p);
	printf("总分最高共有%d人\n", counter);
}
void highestgrade()
{
	int choose;
	getchar();
	printf("*1.总分最高的学生的学号、姓名和成绩\n");
	printf("*2.高数最高的学生的学号、姓名和成绩\n");
	printf("*3.数字逻辑总分最高的学生的学号、姓名和成绩\n");
	printf("*4.离散数学总分最高的学生的学号、姓名和成绩\n");
	printf("请输入你的选择\n");
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
	printf("高数的平均成绩%.2f\n", aver1);
	aver2 = average2();
	printf("数字逻辑的平均成绩%.2f\n", aver2);
	aver3 = average3();
	printf("离散数学的平均成绩%.2f\n", aver3);
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
	printf("高数 A类学生%.0f个，占%.2f%%\n", a, a * 100 / counter);
	printf("高数 B类学生%.0f个，占%.2f%%\n", b, b * 100 / counter);
	printf("高数 C类学生%.0f个，占%.2f%%\n", c, c * 100 / counter);
	printf("高数 D类学生%.0f个，占%.2f%%\n", d, d * 100 / counter);
	printf("高数 E类学生%.0f个，占%.2f%%\n", e, e * 100 / counter);

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
	printf("数字逻辑 A类学生%.0f个，占%.2f%%\n", a, a * 100 / counter);
	printf("数字逻辑 B类学生%.0f个，占%.2f%%\n", b, b * 100 / counter);
	printf("数字逻辑 C类学生%.0f个，占%.2f%%\n", c, c * 100 / counter);
	printf("数字逻辑 D类学生%.0f个，占%.2f%%\n", d, d * 100 / counter);
	printf("数字逻辑 E类学生%.0f个，占%.2f%%\n", e, e * 100 / counter);


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
	printf("离散数学 A类学生%.0f个，占%.2f%%\n", a, a * 100 / counter);
	printf("离散数学 B类学生%.0f个，占%.2f%%\n", b, b * 100 / counter);
	printf("离散数学 C类学生%.0f个，占%.2f%%\n", c, c * 100 / counter);
	printf("离散数学 D类学生%.0f个，占%.2f%%\n", d, d * 100 / counter);
	printf("离散数学 E类学生%.0f个，占%.2f%%\n", e, e * 100 / counter);
}
void level()
{
	int select;
	printf("请选择您要查询的科目：1.高数\n2.数字逻辑\n3.离散数学\n4.以上三项\n");
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
	printf("高数平均成绩%f\n", aver);
	printf("高于平均成绩的有%.0f个人\n", counter1);
	printf("等于平均成绩的有%.0f个人\n", counter2);
	printf("低于平均成绩的有%.0f个人\n", counter3);
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
	printf("数字逻辑平均成绩%f\n", aver);
	printf("高于平均成绩的有%d个人\n", counter1);
	printf("等于平均成绩的有%d个人\n", counter2);
	printf("低于平均成绩的有%d个人\n", counter3);
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
	printf("离散数学平均成绩%f\n", aver);
	printf("高于平均成绩的有%.0f个人\n", counter1);
	printf("等于平均成绩的有%.0f个人\n", counter2);
	printf("低于平均成绩的有%.0f个人\n", counter3);
}
void counter()
{
	int select;
	printf("请选择您要查询的科目：\n");
	printf("1.高数科目偏离情况\n");
	printf("2.数字逻辑科目偏离情况\n");
	printf("3.离散数学科目偏离情况\n4.以上三项\n");
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
	printf("请选择您要进行的功能：\n");
	printf("1.依据学号查询学生的总分、平均分，查询每门课程的平均分.\n2.查询总分或单科最高的学生的学号、姓名和成绩\n3.查询所有同学每门课程的平均分\n4.查询成绩不同等级人数和所占百分比\n5.查询平均成绩以及高于、低于和等于平均成绩的人数\n");
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
	printf("请选择您要进行的功能：\n");
	printf("1.查询学生自然信息\n2.查询分数\n");
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
/*主函数*/
int main(void)
{
	headest = readinfor();
	logininterface();

	printf("谢谢使用！");
	return 0;
}