#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define MAX 30

void print(int arr[]);
void insert(int arr[]);
void random(int arr[], int num); // ���� �� ����
void order(int arr[]); // ��ɾ�
void asc(int arr[]);
void desc(int arr[]);
void shuffle(int arr[]);
void three(int arr[]);
void seven(int arr[]);
void tos(int arr[]);
void tns(int arr[]);
void ma(int arr[]);
void mi(int arr[]);

int main()
{
	int arr[MAX];

	insert(arr);
	order(arr);
}

void insert(int arr[])
{
	int num;
	system("cls");

	while (1)
	{
		printf("������ �ִ�: ");
		scanf_s("%d", &num);
		if (num < 30)
			printf("30 �̻��� ���� �Է��Ͻÿ�\n");
		else
			break;
	}

	random(arr, num);

	return 0;
}

void random(int arr[], int num)
{
	int i, j;
	srand(time(NULL));

	for (i = 0; i < 30; ) // �迭 0���� 30���� ���� �������̴�.
	{
		arr[i] = (rand() % num) + 1; // 1���� 30���� ���� ����

		if (i > 0) // arr[i]�� �� ���� 
		{

			for (j = 0; j < i; j++)
			{
				if (arr[i] == arr[j]) // ���ٸ� i���� ������Ű�� �ʰ� �������ͼ� �ٽ� ���� �ִ´�.
				{
					i--;
					break;
				}
			}
			i++;
		}
		else
			i++; // ó���� i �ϳ� ����
	}
	return 0;
}

void order(int arr[])
{
	while (1)
	{
		system("cls");
		char ch;
		printf("a: ������������ ����\n");
		printf("d: ������������ ����\n");
		printf("r: �����ϰ� ������\n");
		printf("q: ���α׷� ����\n");
		printf("t: 3�� ��� ����ϱ�\n");
		printf("s: 7�� ��� ����ϱ�\n");
		printf("+: 3�� ����̰ų� 7�� ��� ����ϱ� (�����Ͽ� ���)\n");
		printf("-: 3�� ����̰� 7�� ����� ���� ����ϱ� (�����Ͽ� ���)\n");
		printf("m: �ִ밪 ���\n");
		printf("n: �ּҰ� ���\n");
		printf("p: �ٽ� ������ ���� ����� ����ϱ�\n");
		print(arr);
		printf("��ɾ� �Է�: ");
		scanf_s(" %c", &ch);

		switch (ch)
		{
		case 'a':
			asc(arr);
			break;

		case 'd':
			desc(arr);
			break;

		case 'r':
			shuffle(arr);
			break;

		case 'q':

			return 0;

		case 't':
			three(arr);
			break;

		case 's':
			seven(arr);
			break;

		case '+':
			tos(arr);
			break;

		case '-':
			tns(arr);
			break;

		case 'm':
			ma(arr);
			break;

		case 'n':
			mi(arr);
			break;

		case 'p':
			insert(arr);
			break;
		}
	}
}

void asc(int arr[])
{
	int i, j;
	int min;
	int temp;

	for (i = 0; i < 29; i++)
	{	
		min = i;
		for (j = i+1; j < 30; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}

		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

void print(int arr[])
{
	int i;
	for (i = 0; i < 30; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}

void desc(int arr[])
{
	int i, j;
	int max;
	int temp;

	for (i = 0; i < 29; i++)
	{
		max = i;
		for (j = i + 1; j < 30; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}

		temp = arr[max];
		arr[max] = arr[i];
		arr[i] = temp;
	}
}

void shuffle(int arr[])
{
	int num;
	int temp;
	srand(time(NULL));

	for (int i = 0; i < 30; i++)
	{
		num = rand()%30;

		temp = arr[i];
		arr[i] = arr[num];
		arr[num] = temp;
	}
}

void three(int arr[])
{
	int i;
	char ch;
	for (i = 0; i < 30; i++)
	{
		if (arr[i] % 3 == 0)
			printf("%d ", arr[i]);
		
		
	}

	while (1)
	{
		printf("\nEnter...");
		if ((ch = getch()) == 13)
			break;
	}

}

void seven(int arr[])
{
	int i;
	char ch;
	for (i = 0; i < 30; i++)
	{
		if (arr[i] % 7 == 0)
			printf("%d ", arr[i]);
	}

	while (1)
	{
		printf("\nEnter...");
		if ((ch = getch()) == 13)
			break;
	}
}

void tos(int arr[])
{
	int i;
	char ch;

	asc(arr);

	for (i = 0; i < 30; i++)
	{
		if ((arr[i] %3==0) || (arr[i] % 7 == 0))
			printf("%d ", arr[i]);
	}

	while (1)
	{
		printf("\nEnter...");
		if ((ch = getch()) == 13)
			break;
	}
}

void tns(int arr[])
{
	int i;
	char ch;

	asc(arr);

	for (i = 0; i < 30; i++)
	{
		if ((arr[i] % 3 == 0) && (arr[i] % 7 == 0))
			printf("%d ", arr[i]);
	}

	while (1)
	{
		printf("\nEnter...");
		if ((ch = getch()) == 13)
			break;
	}
}

void ma(int arr[])
{
	int i = 0, max = arr[i];
	char ch;
	for (i =0; i < 30; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}

	while (1)
	{
		printf("\nmax: %d",max);
		printf("\nEnter...");
		if ((ch = getch()) == 13)
			break;
	}
}

void mi(int arr[])
{
	int i = 0, min = arr[i];
	char ch;
	for (i =0; i < 30; i++)
	{
		if (min > arr[i])
			min = arr[i];
	}

	while (1)
	{
		printf("\min: %d", min);
		printf("\nEnter...");
		if ((ch = getch()) == 13)
			break;
	}
}