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
	int arr[INTMAX] = { 0 }; // ���� 5���� ���� �迭
	char str[CALMAX] = { 0 }; // ��Ģ���� 4���� ���� �迭
	Insert(arr, str); // �� ����
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
	/*������ �迭 �ʱ�ȭ*/
	for (i = 0; i < INTMAX; i++)
	{
		system("cls");
		printf("1~99������ ���ڸ� �Է��Ͻÿ�: ");
		scanf_s("%d", &arr[i]);
		if ((arr[i] < 1) || (arr[i] > 99))
		{
			printf("%d�� ���� ������ ������ϴ�.", arr[i]); // ������ ������ �����
			i--; // �ٽ��Է�
			PressEnter();
		}
	}
	for (i = 0; i < INTMAX; i++)
	{
		printf("%d", arr[i]);
	}

	/*������ �迭 �ʱ�ȭ*/
	system("cls");
	for (i = 0; i < 4; i++)
	{
		printf("+ - * /��Ģ���� �� �ϳ��� �Է��Ͻÿ�.");
		scanf_s("%c", &str[i]);
		if ((str[i] == )
		{
			printf("%d�� ���� ������ ������ϴ�.", arr[i]); // ������ ������ �����
			i--; // �ٽ��Է�
			PressEnter();
		}
	}
}