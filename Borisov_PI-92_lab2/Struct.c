//lab № 2 

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

	printf("Марка: %s\n", auto_show->autoBrend);
	printf("Название: %s\n", auto_show->autoName);
	printf("Стоимость: %d\n", auto_show->autoCost);
	printf("Максимальная скорость: %d\n", auto_show->autoMax_speed);
	printf("Год выпуска: %d\n", auto_show->autoYear);
	printf("\n");

}




int main()
{
	setlocale(LC_ALL, "");
	int string;

	puts("Первый автомобиль");

	auto_show_t first_auto;
	init(&first_auto, "lada", "granta", 300, 150, 2017);
	Display(&first_auto);

	return 0;
}