#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROW 4
#define COLUMN 5

void Insert(int arr[ROW][COLUMN]);
int Checkdup(int arr[ROW][COLUMN], int num);
void Output(int arr[ROW][COLUMN]);
void Asc(int arr[ROW][COLUMN], int checkarr[]);
void Desc(int arr[ROW][COLUMN], int checkarr[]);
void Even(int arr[ROW][COLUMN]);
void Odd(int arr[ROW][COLUMN]);
void Max(int arr[ROW][COLUMN]);
void Min(int arr[ROW][COLUMN]);
void Rowadd(int arr[ROW][COLUMN], int checkarr[]);
void Shuffle(int arr[ROW][COLUMN], int checkarr[]);
void ReInsert(int arr[ROW][COLUMN], int checkarr[]);

int original[20] = { 0 }; // 이 배열은 Insert함수 호출 시 초기 값이 저장되는 부분으로, 원래되로 되돌릴 때 사용한다.
/* 0은 정렬을 할 수 있는 준비가 되어있는 상태. 1은 되어있는 상태.
0에서 1이 될 때 다른 녀석들을 준비상태로 바꿔주어야 한다. 똑같은 정렬을 실행하면 1에서 0이되어 그 녀석도 준비상태가 된다. */

int main()
{
	char ch;
	int arr[ROW][COLUMN] = { 0 };
	int checkarr[4] = { 0 };

	Insert(arr); // 중복 없이 랜덤한 값 1~50 저장

	while (1)
	{
		system("cls");
		Output(arr); // 출력
		printf("[명령어: a, d, e, o, m, n, p, r, s, q]\n");

		scanf(" %c", &ch);
		if ((ch == 'a') || (ch == 'd') || (ch == 'e') || (ch == 'o') || (ch == 'm') || (ch == 'n') || (ch == 'p') || (ch == 'r') || (ch == 's') || (ch == 'q'))
			switch (ch)
			{
			case 'a':
				Asc(arr, checkarr);
				break;
			case 'd':
				Desc(arr, checkarr);
				break;
			case 'e':
				Even(arr);
				break;
			case 'o':
				Odd(arr);
				break;
			case 'm':
				Max(arr);
				break;
			case 'n':
				Min(arr);
				break;
			case 'p':
				Rowadd(arr, checkarr);
				break;
			case 'r':
				Shuffle(arr, checkarr);
				break;
			case 's':
				ReInsert(arr, checkarr);
				break;
			case 'q':
				return 0;
				
			}

		else
		{
			printf("올바른 명령어를 입력하기 바랍니다.");
			Sleep(1000);
		}
	} // while문의 끝
}

void Insert(int arr[ROW][COLUMN])
{
	int num;
	int loop = 1;
	srand(time(NULL));

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			while (loop) // 
			{
				num = (rand() % 50) + 1;

				/*num에 저장된 랜덤 값이 중복인지 먼저 체크를 한 뒤 배열에 저장을 할 것이다.
				만약 loop가 0이되었다면 올바른 값이 들어왔다는 의미이고, 반복문을 빠져나가게 된다. 그 때 arr배열에 저장한다.*/
				loop = Checkdup(arr, num);
			}
			arr[i][j] = num; // 올바르게 빠져나왔다면 저장함.
			loop = 1; // 다시 잠궈줘야함
		}
	}// for문의 끝

}
int Checkdup(int arr[ROW][COLUMN], int num)
{
	//가져온 num값이 check배열에 존재하지 않는다면 값을 0을 반환하고, 존재한다면 1을 반환한다.
	// 랜덤값은 1~50까지니까 일단 0으로 초기화를 해놓으면 처음값은 무조건 들어가게 된다.

	int loop;
	/*방법 1: 배열을 0번째 인덱스부터 검사를 한다. 만약 중복이 없다면 계속해서 0을 저장하고 중복이 있다면 1을 저장한다.
	AND 현재 값이 0이 저장되어있다면 빈공간이므로, check함수에 저장하고 loop를 0으로 바꾼 후 함수를 빠져나온다.
	방법 2: 첫번째 for문은 검사하는 함수로, 두번째 for문은 값을 넣는 함수로 지정한다.
	첫번째 for문에서 중복된 값이 있다면 loop = 1을하고, 함수를 빠져나온다. 없다면 두번째 for문에서 값이 0이 저장된
	인덱스를 만나면 그 곳에 집어넣고 loop = 0을 저장하고 빠져나온다.*/

	for (int i = 0; i < 20; i++)
	{
		if (num == original[i])
		{
			loop = 1;
			return loop; //중복된 값이 있다면 빠져나간다.
		}
	}

	for (int i = 0; i < 20; i++) // 중복된 값이 없을 때 돌리는 for문
	{
		if (original[i] == 0)
		{
			original[i] = num;
			loop = 0;
			return loop;
		}
	}
}

void Output(int arr[ROW][COLUMN])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			printf("%02d ", arr[i][j]);
		}
		printf("\n");
	}
}

void Asc(int arr[ROW][COLUMN], int checkarr[])
{
	int temp;
	int num = 0;
	if (checkarr[0] == 0)
	{
		//단순 오름차순 정렬이니까, 2차원배열도 결국 1차원배열으로 주소값이 저장되어있다는 원리를 이용한다.
		for (int i = 1; i < 20; i++) // n - 1 번이면 정렬 완료 됨. 
		{
			for (int j = 0; j < 20 - i; j++)
			{
				if (*(*arr + j) > *(*arr + j + 1))
				{
					temp = *(*arr + j); // arr = arr[0] = *(arr + 0)
					*(arr[0] + j) = *(arr[0] + j + 1);
					*(*arr + j + 1) = temp;
				}
			}
		}

		checkarr[0] = 1;
		checkarr[1] = 0;
		checkarr[2] = 0;
		checkarr[3] = 0;
	}
	else if (checkarr[0] == 1)
	{
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COLUMN; j++)
			{
				arr[i][j] = original[num];
				num++;
			}
		checkarr[0] = 0;

	}
}

void Desc(int arr[ROW][COLUMN], int checkarr[])
{
	//하.. 이거 그냥 1차원배열에 있는거 정렬시킨다음에 2차원배열에 그냥 저장해주면 되는데...
	//그런 방식을 원할거같진 않다.
	//대체 어떻게해야 2차원배열을 정렬가능하나
	//규칙: arr[3][0] [2][0] [1][0] [0][0] / [3][1] [2][1] [1][1] [0][1] ...
	int i, j, k, w;
	int val1 = ROW - 1, val2 = COLUMN;
	int temp;
	int temp2;
	int min, index1, index2;
	int num = 0;

	//선택정렬로 차례대로 넣어보자. 가장 작은거 처음에 넣고 그다음 작은거 다음 인덱스 넣고..
	//이게 2차원 배열에서는 버블정렬보다 오류없이 돌아갈 것 같다. 버블정렬은 예를들어 arr[0][4] arr[1][0]을 
	//비교하는게 까다로워보임. 행이 넘어갈 때 이전행 마지막열이랑 비교하는거 말하는거임.
	//선택정렬은 그냥 메모리 1차원으로 펼쳐가지고 가장 작은 것 찾으면 됨.
	//처음에는 min에 arr[j][i]값 넣어놓고, 그것보다 제일 작은 것 찾아다가 arr[j][i]에 넣는다.
	//작은 녀석의 인덱스도 알아야 스왑을 할텐데.. 해보자.

	if (checkarr[1] == 0)
	{

		for (w = 0; w < val2; w++) // 밑에꺼 싹 돌리고 나면 값 올라감.
		{
			for (k = 0; k < 4; k++)//밑에꺼 싹 돌리고나면 값 올라감
			{
				temp = k;
				min = 9999;
				for (i = w; i < val2; i++)
				{
					for (j = val1 - k; j >= 0; j--)
					{
						if (min > arr[j][i])
						{
							min = arr[j][i];
							index1 = j;
							index2 = i;
						}
					}
					k = 0; //처음 한바퀴 돌릴 때 빼고는 val - k는 의미 없음.
				}
				k = temp;
				temp2 = arr[index1][index2];
				arr[index1][index2] = arr[ROW - 1 - k][w];
				arr[ROW - 1 - k][w] = temp2;
			}
		}


		checkarr[1] = 1;
		checkarr[0] = 0;
		checkarr[2] = 0;
		checkarr[3] = 0;
	}

	else if (checkarr[1] == 1)
	{
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COLUMN; j++)
			{
				arr[i][j] = original[num];
				num++;
			}
		checkarr[1] = 0;
	}
}

void Even(int arr[ROW][COLUMN])
{
	char ch;
	system("cls");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if (((arr[i][j] % 2) == 0))
				printf("%02d ", arr[i][j]);
			else
				printf("00 ");
		}
		printf("\n");
	}

	while (1)
	{
		printf("Press Enter...\n");
		if ((ch = getch()) == 13)
			return 0;
	}
}

void Odd(int arr[ROW][COLUMN])
{
	char ch;

	system("cls");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if (((arr[i][j] % 2) == 1))
				printf("%02d ", arr[i][j]);
			else
				printf("00 ");
		}
		printf("\n");
	}

	while (1)
	{
		printf("Press Enter...\n");
		if ((ch = getch()) == 13)
			return 0;
	}
}

void Max(int arr[ROW][COLUMN])
{
	char ch;
	int max;
	int index1, index2;

	printf("\n");
	max = arr[0][0];
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
				index1 = i;
				index2 = j;
			}
		}
	}

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if ((i == index1) && (j == index2))
			{
				printf("%02d ", arr[index1][index2]);
			}
			else
				printf("00 ");
		}
		printf("\n");
	}

	while (1)
	{
		printf("Press Enter...\n");
		if ((ch = getch()) == 13)
			return 0;
	}

}

void Min(int arr[ROW][COLUMN])
{
	char ch;
	int min;
	int index1 = 0, index2 = 0;
	printf("\n");
	min = arr[0][0];
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if (min > arr[i][j])
			{
				min = arr[i][j];
				index1 = i;
				index2 = j;
			}
		}
	}

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if ((i == index1) && (j == index2))
			{
				printf("%02d ", arr[index1][index2]);
			}
			else
				printf("00 ");
		}
		printf("\n");
	}

	while (1)
	{
		printf("Press Enter...\n");
		if ((ch = getch()) == 13)
			return 0;
	}

}


void Rowadd(int arr[ROW][COLUMN], int checkarr[])
{
	// 각 행의 값을 더해 1열에 저장하는데, 먼저 안쪽의 for문이 다 돌아갈동안 sum에다가 값을 저장해두고, for문이 다 완료되면
	// 다음 for문값이 하나 올라가기 전에 sum값을 arr[i][0]에 저장한다.
	int sum = 0;
	int Rock = 1;
	int num = 0;
	if (checkarr[2] == 0)
	{
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COLUMN; j++)
			{
				sum += arr[i][j];
			}
			arr[i][0] = sum;
			sum = 0;
		}
		checkarr[2] = 1;
		checkarr[0] = 0;
		checkarr[1] = 0;
		checkarr[3] = 0;
	}

	else if (checkarr[2] == 1)
	{
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COLUMN; j++)
			{
				arr[i][j] = original[num];
				num++;
			}
		checkarr[2] = 0;
	}

}

void Shuffle(int arr[ROW][COLUMN], int checkarr[])
{
	//기존의 숫자를 재정렬 해야함.
	int num = 0;
	int r1, r2;
	int temp;
	srand(time(NULL));

	if (checkarr[3] == 0)
	{

		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COLUMN; j++)
			{
				arr[i][j] = original[num];
				num++;
			}

		for (int i = 0; i < ROW; i++)
		{

			for (int j = 0; j < COLUMN; j++)
			{
				r1 = (rand() % ROW);
				r2 = (rand() % COLUMN);
				temp = arr[i][j];
				arr[i][j] = arr[r1][r2];
				arr[r1][r2] = temp;
			}
		}

		checkarr[3] = 1;
		checkarr[0] = 0;
		checkarr[1] = 0;
		checkarr[2] = 0;
	}

	else if (checkarr[3] == 1)
	{
		for (int i = 0; i < ROW; i++)
			for (int j = 0; j < COLUMN; j++)
			{
				arr[i][j] = original[num];
				num++;
			}
		checkarr[3] = 0;
	}
}

void ReInsert(int arr[ROW][COLUMN], int checkarr[])
{
	for (int i = 0; i < ROW; i++) // 값 0으로 초기화
		for (int j = 0; j < COLUMN; j++)
			arr[i][j] = 0;

	for (int i = 0; i < 20; i++) // 값 0으로 초기화
			original[i] = 0;

	for (int i = 0; i < 4; i++) // 값 0으로 초기화
		checkarr[i] = 0;

	Insert(arr);
	
}