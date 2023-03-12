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
	{1,0,0,0}, // 객체 1 
	{2,0,0,0} // 객체 2 
};

int main()
{
	Init();
	Insert(); // Board에 배치한다.
	
	while (1)
	{
		system("cls");
		Display(); // 보드에 올라온 돌을 보여준다.
		printf("[현재 턴: %d]\n", COUNT);
		printf("[0:awsd / 1:jikl / r:리셋 / q:종료]\n");
		if ((obj[0].x == obj[1].x) && (obj[0].y == obj[1].y))
			Beep(260, 300); // 화면까지 다 출력하고나서 BEEP음 들리게하기
		Order();
	}
}

void Init()
{
	int rx, ry, rt;
	srand(time(NULL));
	/*객체 1 랜덤 초기화*/
	rx = rand() % 10;
	ry = rand() % 10;
	rt = (rand() % 5) + 1;
	obj[0].x = rx;
	obj[0].y = ry;
	obj[0].TYPE = rt;

	/*객체 2 랜덤 초기화*/
	while (1)
	{
		rx = rand() % 10;
		ry = rand() % 10;

		/*객체 1과 겹치지 않도록 설정한다.*/
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

		/*객체 1과 겹치지 않도록 설정한다.*/
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

	while (1) // 미리 돌바꾸기
	{
		r1 = (rand() % 5) + 1;
		if ((r1 != obj[0].TYPE) && (r1 != obj[1].TYPE))
			break;
	}
	//객체 1, 2의 x좌표 y좌표 ID를 가져다가 BOARD에 올려준다.
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			BOARD[i][j] = 0;
		}

	BOARD[obj[0].x][obj[0].y] = obj[0].ID;
	BOARD[obj[1].x][obj[1].y] = obj[1].ID;

	if ((obj[0].x == obj[1].x) && (obj[0].y == obj[1].y)) //먹는쪽이 위로가도록 만든다.
	{

		if (COUNT == 0) // 객체 2가 1을 먹는다
		{
			BOARD[obj[0].x][obj[0].y] = obj[0].ID;
			BOARD[obj[1].x][obj[1].y] = obj[1].ID;		
			obj[0].TYPE = r1;
		}

		else if (COUNT == 1) // 객체1가 2을 먹는다
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
			if (BOARD[i][j] != 0) // 0이 아니라면 아이디 추출해서 해당 ID에 TYPE값을 가져다가 맞게 돌 띄움.
			{
				m_id = BOARD[i][j];
				for (int k = 0; k < 2; k++)
				{
					if (m_id == obj[k].ID)
					{
						m_type = obj[k].TYPE; // 해당 아이디에 맞는 타입값을 추출.

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
	/*Count값을 보고 돌을 이동시킬것임.
	값이 0이면 객체1, 값이 1이면 객체2를 움직을 수 있다.*/
	char ch;
	int r1;
	srand(time(NULL));
	ch = getch();
	if (ch == 'r')
	{
		/*초기화*/
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
			{
				BOARD[i][j] = 0;
			}

		Init();
		Insert();

		return 0;
	}
	/*미리 돌모양 바꿔놓기*/
	while (1)
	{
		r1 = (rand() % 5) + 1;
		if ((r1 != obj[0].TYPE) && (r1 != obj[1].TYPE))
			break;
	}

	/*객체 1*/
	if (COUNT == 0)
	{
		if (ch == 'a')
		{
			obj[0].y--;
			COUNT = 1;
			if (obj[0].y < 0)
			{
				obj[0].y = 9;
				//랜덤하게 돌모양 바꿔야 함.
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

	/*객체 2*/
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
