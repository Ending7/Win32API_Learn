#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

int arr[5];
char str[4];
int Count1 = 5;
int Count2 = 4;

void PressEnter();
void Insert(int arr2[], char str2[]);
void OutPrint();
void Show();
void Cal1(int arr2[], char str2[]);
void Cal2(int arr2[], char str2[]);
void Cal3(int arr2[], char str2[]);
void CalMD(int arr2[], char str2[], int i);

int main()
{
	int num;
	int arr2[5];
	char str2[4];

	Insert(arr2, str2); // �� ����
	while (1)
	{
		OutPrint(arr, str); // ����ȭ��

		scanf_s("%d", &num); // ��ɾ� �Է�
		switch (num)
		{
		case 1: //������ �켱������ ���
			Cal1(arr2, str2);
			break;
		case 2: // ������� ���
			Cal2(arr2, str2);
			break;
		case 3: // �� ������� ���
			Cal3(arr2, str2);
			break;
		case 4: // ���ο� ����, ������
			Insert(arr2,str2);
			break;
		case 5: // ����
			return 0;
		}

	}
}

void PressEnter()
{
	char ch;
	printf("\nPRESS ENTER...");
	if ((ch = _getch()) == 13)
		return 0;

}

void Insert(int arr2[], char str2[])
{
	int count = 0;
	char ch;
	while (1)
	{
		system("cls");
		printf("���� �Է� [ex:5 4 3 2 1]: ");
		scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]); //�ټ��� ���޾� �Է�;
		for (int i = 0; i < 5; i++)
		{
			if ((arr[i] > 0) && (arr[i] < 100)) //ù���� �������� �� ����������� ����϶�� �Ͻ�.
			{
				count++;
			}
			else
			{
				printf("�ٽ� �Է�");
				count = 0;
				PressEnter();
				break;
			}
		}
		if (count == 5)
			break;
	}

	count = 0;
	ch = getchar();
	while (1)
	{
		system("cls");

		printf("���� �Է�: [ex:-+*/]: ");
		gets_s(str, 5);
		for (int i = 0; i < 4; i++)
		{
			if ((str[i] == '-') || (str[i] == '+') || (str[i] == '*') || (str[i] == '/'))
			{
				count++;
			}
			else
			{
				printf("�ٽ��Է�");
				count = 0;
				PressEnter();
				break;
			}
		}

		if (count == 4)
			break;
	}

	for (int i = 0; i < 5; i++)
	{
		arr2[i] = arr[i];
	}

	for (int i = 0; i < 4; i++)
	{
		str2[i] = str[i];
	}

	return 0;
}

void OutPrint()
{
	system("cls");
	Show();
	printf("---------------------------------------\n");
	printf("��ɾ� 1: ������ �켱������\n");
	printf("��ɾ� 2: �������\n");
	printf("��ɾ� 3: �� �������\n");
	printf("��ɾ� 4: ���� ���ڿ� ������ ����\n");
	printf("��ɾ� 5: ���α׷� ����\n");
	printf("---------------------------------------\n");
	printf("��ɾ� �Է�: ");
}

void Show()
{
	printf("[�Է°�]\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%d", arr[i]);
		printf("%c", str[i]);
	}
	printf("%d\n", arr[4]);
}

void Cal1(int arr2[], char str2[])
{
	int calculate;
	int i;
}

void Cal2(int arr2[], char str2[])
{
	int calculate = arr2[0];
	for (int i = 0; i < 4; i++)
	{
		switch (str2[i])
		{
		case '-': 
			calculate -= arr2[i + 1];
			break;
		case '+':
			calculate += arr2[i + 1];
			break;
		case '*':
			calculate *= arr2[i + 1];
			break;
		case '/':
			calculate /= arr2[i + 1];
			break;
		}
	}
	printf("%d", calculate);
	PressEnter();
}

void Cal3(int arr2[], char str2[])
{
	int calculate = arr2[4];
	for (int i = 3; i >= 0; i--)
	{
		switch (str2[i])
		{
		case '-':
			calculate = (arr2[i] -calculate);
			break;
		case '+':
			calculate = (arr2[i] + calculate);
			break;
		case '*':
			calculate = (arr2[i] *calculate);
			break;
		case '/':
			calculate = (arr2[i] /calculate);
			break;
		}
	}
	printf("%d", calculate);
	PressEnter();

}