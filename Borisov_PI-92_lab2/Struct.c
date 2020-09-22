//lab � 2 

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <malloc.h>
#pragma warning (disable:4996)
#define SIZE 25

typedef struct auto_show {

	char autoBrend[SIZE];
	char autoName[SIZE];
	int autoCost;
	int autoMax_speed;
	int autoYear;

} auto_show_t;


void init(auto_show_t* auto_show, char* brend, char* name, int cost, int max_speed, int year)
{
	strcpy(auto_show->autoBrend, brend);
	strcpy(auto_show->autoName, name);
	auto_show->autoCost = cost;
	auto_show->autoMax_speed = max_speed;
	auto_show->autoYear = year;

}

void Display(auto_show_t* auto_show)
{

	printf("\n�����: %s\n", auto_show->autoBrend);
	printf("��������: %s\n", auto_show->autoName);
	printf("���������: %d\n", auto_show->autoCost);
	printf("������������ ��������: %d\n", auto_show->autoMax_speed);
	printf("��� �������: %d\n", auto_show->autoYear);
	printf("\n");

}

void deleteSpace(char* text) {
	//���� ����� ������ ������, �� ������� ���, ����������� ���� ��������� ����� �������
	while (text[0] == ' ') {
		if (text + 1)
			strcpy(text, text + 1);
		else
			*text = '\0';
	}
}

Read(auto_show_t* auto_show)
{

	puts("������� ����� ����������:");
	scanf("%s", auto_show->autoBrend);
	fflush(stdin);
	deleteSpace(auto_show->autoBrend);

	puts("������� �������� ����������:");
	scanf("%s", auto_show->autoName);
	fflush(stdin);
	deleteSpace(auto_show->autoName);


	do {
		puts("������� ��������� ����������:");
		while (!scanf("%d", &auto_show->autoCost)) {
			puts("������! ������� ��� ���");
			fflush(stdin);
		}
	} while (auto_show->autoCost < 0);

	do {
		puts("������� ������������ �������� ����������:");
		while (!scanf("%d", &auto_show->autoMax_speed)) {
			puts("������! ������� ��� ���");
			fflush(stdin);
		}
	} while (auto_show->autoMax_speed < 0);

	do {
		puts("������� ��� ������� ����������:");
		while (!scanf("%d", &auto_show->autoYear)) {
			puts("������! ������� ��� ���");
			fflush(stdin);
		}
	} while (auto_show->autoYear < 0 || auto_show->autoYear > 2020);

}

int Add(auto_show_t first_auto, auto_show_t second_auto)

{

	return first_auto.autoCost + second_auto.autoCost;

}



int main()
{
	setlocale(LC_ALL, "");

	puts("������ ����������");

	auto_show_t first_auto;
	init(&first_auto, "lada", "granta", 300, 150, 2017);
	Display(&first_auto);

	puts("������ ����������");
	auto_show_t second_auto;
	Read(&second_auto);
	Display(&second_auto);

	printf("��������� ���� �����������: %d\n", Add(first_auto, second_auto));

	auto_show_t* auto_show;
	auto_show = malloc(sizeof (auto_show_t));
	free(auto_show);



	return 0;
}