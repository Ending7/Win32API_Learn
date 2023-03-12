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

int original[20] = { 0 }; // �� �迭�� Insert�Լ� ȣ�� �� �ʱ� ���� ����Ǵ� �κ�����, �����Ƿ� �ǵ��� �� ����Ѵ�.
/* 0�� ������ �� �� �ִ� �غ� �Ǿ��ִ� ����. 1�� �Ǿ��ִ� ����.
0���� 1�� �� �� �ٸ� �༮���� �غ���·� �ٲ��־�� �Ѵ�. �Ȱ��� ������ �����ϸ� 1���� 0�̵Ǿ� �� �༮�� �غ���°� �ȴ�. */

int main()
{
	char ch;
	int arr[ROW][COLUMN] = { 0 };
	int checkarr[4] = { 0 };

	Insert(arr); // �ߺ� ���� ������ �� 1~50 ����

	while (1)
	{
		system("cls");
		Output(arr); // ���
		printf("[��ɾ�: a, d, e, o, m, n, p, r, s, q]\n");

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
			printf("�ùٸ� ��ɾ �Է��ϱ� �ٶ��ϴ�.");
			Sleep(1000);
		}
	} // while���� ��
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

				/*num�� ����� ���� ���� �ߺ����� ���� üũ�� �� �� �迭�� ������ �� ���̴�.
				���� loop�� 0�̵Ǿ��ٸ� �ùٸ� ���� ���Դٴ� �ǹ��̰�, �ݺ����� ���������� �ȴ�. �� �� arr�迭�� �����Ѵ�.*/
				loop = Checkdup(arr, num);
			}
			arr[i][j] = num; // �ùٸ��� �������Դٸ� ������.
			loop = 1; // �ٽ� ��������
		}
	}// for���� ��

}
int Checkdup(int arr[ROW][COLUMN], int num)
{
	//������ num���� check�迭�� �������� �ʴ´ٸ� ���� 0�� ��ȯ�ϰ�, �����Ѵٸ� 1�� ��ȯ�Ѵ�.
	// �������� 1~50�����ϱ� �ϴ� 0���� �ʱ�ȭ�� �س����� ó������ ������ ���� �ȴ�.

	int loop;
	/*��� 1: �迭�� 0��° �ε������� �˻縦 �Ѵ�. ���� �ߺ��� ���ٸ� ����ؼ� 0�� �����ϰ� �ߺ��� �ִٸ� 1�� �����Ѵ�.
	AND ���� ���� 0�� ����Ǿ��ִٸ� ������̹Ƿ�, check�Լ��� �����ϰ� loop�� 0���� �ٲ� �� �Լ��� �������´�.
	��� 2: ù��° for���� �˻��ϴ� �Լ���, �ι�° for���� ���� �ִ� �Լ��� �����Ѵ�.
	ù��° for������ �ߺ��� ���� �ִٸ� loop = 1���ϰ�, �Լ��� �������´�. ���ٸ� �ι�° for������ ���� 0�� �����
	�ε����� ������ �� ���� ����ְ� loop = 0�� �����ϰ� �������´�.*/

	for (int i = 0; i < 20; i++)
	{
		if (num == original[i])
		{
			loop = 1;
			return loop; //�ߺ��� ���� �ִٸ� ����������.
		}
	}

	for (int i = 0; i < 20; i++) // �ߺ��� ���� ���� �� ������ for��
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
		//�ܼ� �������� �����̴ϱ�, 2�����迭�� �ᱹ 1�����迭���� �ּҰ��� ����Ǿ��ִٴ� ������ �̿��Ѵ�.
		for (int i = 1; i < 20; i++) // n - 1 ���̸� ���� �Ϸ� ��. 
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
	//��.. �̰� �׳� 1�����迭�� �ִ°� ���Ľ�Ų������ 2�����迭�� �׳� �������ָ� �Ǵµ�...
	//�׷� ����� ���ҰŰ��� �ʴ�.
	//��ü ����ؾ� 2�����迭�� ���İ����ϳ�
	//��Ģ: arr[3][0] [2][0] [1][0] [0][0] / [3][1] [2][1] [1][1] [0][1] ...
	int i, j, k, w;
	int val1 = ROW - 1, val2 = COLUMN;
	int temp;
	int temp2;
	int min, index1, index2;
	int num = 0;

	//�������ķ� ���ʴ�� �־��. ���� ������ ó���� �ְ� �״��� ������ ���� �ε��� �ְ�..
	//�̰� 2���� �迭������ �������ĺ��� �������� ���ư� �� ����. ���������� ������� arr[0][4] arr[1][0]�� 
	//���ϴ°� ��ٷο�����. ���� �Ѿ �� ������ ���������̶� ���ϴ°� ���ϴ°���.
	//���������� �׳� �޸� 1�������� ���İ����� ���� ���� �� ã���� ��.
	//ó������ min�� arr[j][i]�� �־����, �װͺ��� ���� ���� �� ã�ƴٰ� arr[j][i]�� �ִ´�.
	//���� �༮�� �ε����� �˾ƾ� ������ ���ٵ�.. �غ���.

	if (checkarr[1] == 0)
	{

		for (w = 0; w < val2; w++) // �ؿ��� �� ������ ���� �� �ö�.
		{
			for (k = 0; k < 4; k++)//�ؿ��� �� �������� �� �ö�
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
					k = 0; //ó�� �ѹ��� ���� �� ����� val - k�� �ǹ� ����.
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
	// �� ���� ���� ���� 1���� �����ϴµ�, ���� ������ for���� �� ���ư����� sum���ٰ� ���� �����صΰ�, for���� �� �Ϸ�Ǹ�
	// ���� for������ �ϳ� �ö󰡱� ���� sum���� arr[i][0]�� �����Ѵ�.
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
	//������ ���ڸ� ������ �ؾ���.
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
	for (int i = 0; i < ROW; i++) // �� 0���� �ʱ�ȭ
		for (int j = 0; j < COLUMN; j++)
			arr[i][j] = 0;

	for (int i = 0; i < 20; i++) // �� 0���� �ʱ�ȭ
			original[i] = 0;

	for (int i = 0; i < 4; i++) // �� 0���� �ʱ�ȭ
		checkarr[i] = 0;

	Insert(arr);
	
}