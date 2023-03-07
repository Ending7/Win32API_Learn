#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define MAX 30

void print(int arr[]);
void insert(int arr[]);
void random(int arr[], int num); // 랜덤 값 생성
void order(int arr[]); // 명령어
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
		printf("숫자의 최댓값: ");
		scanf_s("%d", &num);
		if (num < 30)
			printf("30 이상의 값을 입력하시오\n");
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

	for (i = 0; i < 30; ) // 배열 0부터 30까지 값을 넣을것이다.
	{
		arr[i] = (rand() % num) + 1; // 1부터 30까지 숫자 생성

		if (i > 0) // arr[i]일 때 부터 
		{

			for (j = 0; j < i; j++)
			{
				if (arr[i] == arr[j]) // 같다면 i값을 증가시키지 않고 빠져나와서 다시 값을 넣는다.
				{
					i--;
					break;
				}
			}
			i++;
		}
		else
			i++; // 처음에 i 하나 증가
	}
	return 0;
}

void order(int arr[])
{
	while (1)
	{
		system("cls");
		char ch;
		printf("a: 오름차순으로 정렬\n");
		printf("d: 내림차순으로 정렬\n");
		printf("r: 랜덤하게 재정렬\n");
		printf("q: 프로그램 종료\n");
		printf("t: 3의 배수 출력하기\n");
		printf("s: 7의 배수 출력하기\n");
		printf("+: 3의 배수이거나 7의 배수 출력하기 (정렬하여 출력)\n");
		printf("-: 3의 배수이고 7의 배수인 숫자 출력하기 (정렬하여 출력)\n");
		printf("m: 최대값 출력\n");
		printf("n: 최소값 출력\n");
		printf("p: 다시 임의의 숫자 만들고 출력하기\n");
		print(arr);
		printf("명령어 입력: ");
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