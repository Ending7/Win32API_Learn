#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define INTMAX 5
#define CALMAX 4 

void PressEnter();
void Insert(int arr[], int str[]);

int main()
{
	int i;
	int arr[INTMAX] = { 0 }; // 정수 5개를 받을 배열
	char str[CALMAX] = { 0 }; // 사칙연산 4개를 받을 배열
	Insert(arr, str); // 값 삽입
}

void PressEnter()
{
	char ch;
	printf("\nPRESS ENTER...");
	if ((ch = _getch()) == 13)
		return 0;
}

void Insert(int arr[], int str[])
{
	int i;
	/*정수형 배열 초기화*/
	for (i = 0; i < INTMAX; i++)
	{
		system("cls");
		printf("1~99까지의 숫자를 입력하시오: ");
		scanf_s("%d", &arr[i]);
		if ((arr[i] < 1) || (arr[i] > 99))
		{
			printf("%d의 값은 범위를 벗어났습니다.", arr[i]); // 정수의 범위를 벗어나면
			i--; // 다시입력
			PressEnter();
		}
	}
	for (i = 0; i < INTMAX; i++)
	{
		printf("%d", arr[i]);
	}

	/*문자형 배열 초기화*/
	system("cls");
	for (i = 0; i < 4; i++)
	{
		printf("+ - * /사칙연산 중 하나를 입력하시오.");
		scanf_s("%c", &str[i]);
		if ((str[i] == )
		{
			printf("%d의 값은 범위를 벗어났습니다.", arr[i]); // 정수의 범위를 벗어나면
			i--; // 다시입력
			PressEnter();
		}
	}
}