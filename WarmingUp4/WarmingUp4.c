#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<Windows.h>

int BOARD[10][10] = { 0 };
int COUNT = 0;

void Init();
void Insert();
void Display();
void Order();

typedef struct OBJ
{
	int ID;
	int TYPE;
	int x;
	int y;
}OBJ;

OBJ obj[2] =
{
	{1,0,0,0}, // ��ü 1 
	{2,0,0,0} // ��ü 2 
};

int main()
{
	Init();
	Insert(); // Board�� ��ġ�Ѵ�.
	
	while (1)
	{
		system("cls");
		Display(); // ���忡 �ö�� ���� �����ش�.
		printf("[���� ��: %d]\n", COUNT);
		printf("[0:awsd / 1:jikl / r:���� / q:����]\n");
		if ((obj[0].x == obj[1].x) && (obj[0].y == obj[1].y))
			Beep(260, 300); // ȭ����� �� ����ϰ��� BEEP�� �鸮���ϱ�
		Order();
	}
}

void Init()
{
	int rx, ry, rt;
	srand(time(NULL));
	/*��ü 1 ���� �ʱ�ȭ*/
	rx = rand() % 10;
	ry = rand() % 10;
	rt = (rand() % 5) + 1;
	obj[0].x = rx;
	obj[0].y = ry;
	obj[0].TYPE = rt;

	/*��ü 2 ���� �ʱ�ȭ*/
	while (1)
	{
		rx = rand() % 10;
		ry = rand() % 10;

		/*��ü 1�� ��ġ�� �ʵ��� �����Ѵ�.*/
		if ((rx != obj[0].x) || (ry != obj[0].y))
		{
			obj[1].x = rx;
			obj[1].y = ry;
			break;
		}
	}

	while (1)
	{
		rt = (rand() % 5) + 1;
		obj[1].TYPE = rt;

		/*��ü 1�� ��ġ�� �ʵ��� �����Ѵ�.*/
		if ((obj[1].TYPE != obj[0].TYPE))
		{
			obj[1].TYPE = rt;
			break;
		}
	}

	return 0;
}

void Insert()
{
	int r1;
	srand(time(NULL)); 

	while (1) // �̸� ���ٲٱ�
	{
		r1 = (rand() % 5) + 1;
		if ((r1 != obj[0].TYPE) && (r1 != obj[1].TYPE))
			break;
	}
	//��ü 1, 2�� x��ǥ y��ǥ ID�� �����ٰ� BOARD�� �÷��ش�.
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			BOARD[i][j] = 0;
		}

	BOARD[obj[0].x][obj[0].y] = obj[0].ID;
	BOARD[obj[1].x][obj[1].y] = obj[1].ID;

	if ((obj[0].x == obj[1].x) && (obj[0].y == obj[1].y)) //�Դ����� ���ΰ����� �����.
	{

		if (COUNT == 0) // ��ü 2�� 1�� �Դ´�
		{
			BOARD[obj[0].x][obj[0].y] = obj[0].ID;
			BOARD[obj[1].x][obj[1].y] = obj[1].ID;		
			obj[0].TYPE = r1;
		}

		else if (COUNT == 1) // ��ü1�� 2�� �Դ´�
		{
			BOARD[obj[1].x][obj[1].y] = obj[1].ID;
			BOARD[obj[0].x][obj[0].y] = obj[0].ID;		
			obj[1].TYPE = r1;
		}
	}
}
void Display()
{
	int m_id, m_type;

	for (int i = 0; i < 10; i++)
	{
		printf("---------------------\n");

		for (int j = 0; j < 10; j++)
		{
			printf("l");
			if (BOARD[i][j] != 0) // 0�� �ƴ϶�� ���̵� �����ؼ� �ش� ID�� TYPE���� �����ٰ� �°� �� ���.
			{
				m_id = BOARD[i][j];
				for (int k = 0; k < 2; k++)
				{
					if (m_id == obj[k].ID)
					{
						m_type = obj[k].TYPE; // �ش� ���̵� �´� Ÿ�԰��� ����.

						if (m_type == 1)
							printf("o");
						if (m_type == 2)
							printf("x");
						if (m_type == 3)
							printf("#");
						if (m_type == 4)
							printf("@");
						if (m_type == 5)
							printf("*");
						break;
					}
				}
			}
			else
				printf(" ");
		}
		printf("l\n");
	}
	printf("---------------------\n");

	
}

void Order()
{
	/*Count���� ���� ���� �̵���ų����.
	���� 0�̸� ��ü1, ���� 1�̸� ��ü2�� ������ �� �ִ�.*/
	char ch;
	int r1;
	srand(time(NULL));
	ch = getch();
	if (ch == 'r')
	{
		/*�ʱ�ȭ*/
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
			{
				BOARD[i][j] = 0;
			}

		Init();
		Insert();

		return 0;
	}
	/*�̸� ����� �ٲ����*/
	while (1)
	{
		r1 = (rand() % 5) + 1;
		if ((r1 != obj[0].TYPE) && (r1 != obj[1].TYPE))
			break;
	}

	/*��ü 1*/
	if (COUNT == 0)
	{
		if (ch == 'a')
		{
			obj[0].y--;
			COUNT = 1;
			if (obj[0].y < 0)
			{
				obj[0].y = 9;
				//�����ϰ� ����� �ٲ�� ��.
				obj[0].TYPE = r1;
			}
			Insert();
		}
		else if (ch == 'd')
		{
			obj[0].y++;
			COUNT = 1; COUNT = 1;
			if (obj[0].y > 9)
			{
				obj[0].y = 0;
				obj[0].TYPE = r1;
			}
			Insert();
		}
		else if (ch == 'w')
		{
			obj[0].x--;
			COUNT = 1;
			if (obj[0].x < 0)
			{
				obj[0].x = 9;
				obj[0].TYPE = r1;
			}
			Insert();
		}
		else if (ch == 's')
		{
			obj[0].x++;
			COUNT = 1;
			if (obj[0].x > 9)
			{
				obj[0].x = 0;
				obj[0].TYPE = r1;
			}
			Insert();
		}

		else if (ch == 'q')
			exit(1);
	}

	/*��ü 2*/
	else if (COUNT == 1)
	{
		if (ch == 'j')
		{
			obj[1].y--;
			COUNT = 0;
			if (obj[1].y < 0)
			{
				obj[1].y = 9;
				obj[1].TYPE = r1;
			}
			Insert();
		}
		else if (ch == 'l')
		{
			obj[1].y++;
			COUNT = 0;
			if (obj[1].y > 9)
			{
				obj[1].y = 0;
				obj[1].TYPE = r1;
			}
			Insert();
		}
		else if (ch == 'i')
		{
			obj[1].x--;
			COUNT = 0;
			if (obj[1].x < 0)
			{
				obj[1].x = 9;
				obj[1].TYPE = r1;
			}
			Insert();
		}
		else if (ch == 'k')
		{
			obj[1].x++;
			COUNT = 0;
			if (obj[1].x > 9)
			{
				obj[1].x = 0;
				obj[1].TYPE = r1;
			}
			Insert();
		}
		else if (ch == 'q')
			exit(1);
	}

	return 0;
}
