#include <stdio.h>
#include <conio.h>
#include <windows.h>

void Calander(int year, int month, int day); // �޷����
int Error(int year, int month, int day); // ����ó��
void PressEnter(); // ���ʹ����� ���� �۾����� �Ѿ
int SumDay(int year, int month, int day); // �� �ϼ� ���ϱ�
int LeepYear(int year); // �����̸� 1 �ƴϸ� 0��ȯ
int Dayofweek(int sumday); // ���ϱ��ϱ�
void Output(char** str, int dayofweek, int year, int month); // ȭ�鿡 ���� ���
void Sequence(int year);
void YearMonthDay(int year, char** str);

int main()
{
	int year = 2023;
	int month = 3;
	int day = 1;
	char ch;

	Calander(year, month, day); // ó���� 2023/3/1 �⺻��
	while (1)
	{
		system("cls");
		printf("[c: �޷� / f/F: ��������¥, ����]\n");
		ch = _getch();

		if (ch == 'c') // �޷��� ����� ��
		{
			printf("�� �� ��: ");
			scanf_s("%d %d %d", &year, &month, &day);

			Calander(year, month, day);
		}

		else if ((ch == 'f') || (ch == 'F')) //�ظ� �Է��ϸ� ��� ���� ���������� ��¥�� ������ ����Ѵ�.
		{
			printf("�⵵: ");
			scanf_s("%d", &year);
			Sequence(year);
		}

	}
}

void Calander(int year, int month, int day)
{
	int check = 0;
	int sumday = 0;
	int leepyear = 0;
	int dayofweek = 0;
	int week;

	char* str[] =
	{ "Sun", "Mon", "Tue", "Wed", "Tur", "Fri", "Sat" };

	/*����ó�� �⵵�� 2000 ~ 2023, ���� 1 ~ 1, ���� ���� ���⿡ ���缭*/
	while (1)
	{
		check = Error(year, month, day);
		if (check == 0)
		{
			PressEnter();
			return 0;
		}
		else // ����� �Է��� ��ٸ� �ݺ����� ���������� �޷� ����� �����Ѵ�.
		{
			break;
		}
	}

	system("cls");//���±��� ����Ѱ� �ʱ�ȭ���ְ� �޷¸� ����Ѵ�.
	sumday = SumDay(year, month, day); // 1�� 1�� 1�Ϻ��� �� �ϼ��� ��������Ѵ�.
	dayofweek = Dayofweek(sumday); // ����� �ϼ��� ���ϱ��ϱ�
	printf("%d/%02d/%02d: %s\n", year, month, day, str[dayofweek]);
	Output(str, dayofweek, year, month);
	PressEnter();
}

int Error(int year, int month, int day)
{
	int num = 0;
	int eday; //Error�Լ��� day
	if (year >= 0 && year <= 2030) // �� Ȯ��
	{
		if (month >= 0 && month <= 12) //�� Ȯ��
		{
			switch (month) //�� Ȯ��
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				eday = 31;
				break;
			case 2:
				if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
				{
					eday = 29; // ������ �Ϸ簡 �� ����.
				}
				else
				{
					eday = 28;
				}
				break;
			default:
				eday = 30;
				break;
			}
			/*�� ��*/
			if ((day >= 1) && (day <= eday)) //�� ���� ����� �Է��� �Ǿ��ٸ�
			{
				num = 1;
				return num;
			}
			else
			{
				printf("%d���� ���� ����: 1 ~ %d", month, eday);
				return num;
			}
		}

		else
		{
			printf("���� ����: 1 ~ 12");
			return num;
		}
	}

	else
	{
		printf("���� ����: 2000 ~ 2030");
		return num;
	}
}

void PressEnter()
{
	char ch;
	while (1)
	{
		printf("\nPress Enter...");
		if ((ch = _getch()) == 13)
			return 0;
	}
}

int SumDay(int year, int month, int day) // �� �ϼ� ���ϱ�
{
	int i, j;
	int sday; // SumDay�� day
	int sumday = 0;
	int count = 0; //1�� ���ķ�, ����̸� ��¥�� 1ĭ, �����̸� ��¥�� 2ĭ �и�
	for (i = 1; i < year; i++) // ���� �ϼ��� �ٲ۴�.
	{
		if (LeepYear(i) == 0)
			sumday += 365;
		else if (LeepYear(i) == 1)
			sumday += 366;
	}

	for (j = 1; j < month; j++) // ���� �ϼ��� �ٲ۴�(���� ���)
	{
		switch (j)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			sumday += 31;
			break;
		case 2:
			if (LeepYear(year) == 1)
			{
				sumday += 29; // ������ �Ϸ簡 �� ����.
			}
			else
			{
				sumday += 28;
			}
			break;
		default:
			sumday += 30;
			break;
		}
	}

	sumday += day; //���������� �ϼ��� ���Ѵ�.
	return sumday; //�� ���� �� ��ȯ
}

int LeepYear(int year)
{
	int num = 0;
	if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
	{
		num = 1;
		return num;
	}
	else
		return num;
}

int Dayofweek(int sumday)
{
	if (sumday % 7 == 0)
		return 0;
	else if (sumday % 7 == 1)
		return 1;
	else if (sumday % 7 == 2)
		return 2;
	else if (sumday % 7 == 3)
		return 3;
	else if (sumday % 7 == 4)
		return 4;
	else if (sumday % 7 == 5)
		return 5;
	else if (sumday % 7 == 6)
		return 6;
	else if (sumday % 7 == 7)
		return 7;
}

void Output(char** str, int dayofweek, int year, int month)
{
	int i, j, k;
	int num = 1;
	int dnum = 0;
	printf("----------------------------------\n");
	for (i = 0; i < 7; i++)
	{
		printf("%s  ", str[i]);
	}
	printf("\n----------------------------------\n");

	for (j = 0; j < dayofweek; j++) // ����
	{
		printf("     ");
	}


	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		dnum = 31;
		break;
	case 2:
		if (LeepYear(year) == 1)
		{
			dnum = 29; // ������ �Ϸ簡 �� ����.
		}
		else
		{
			dnum = 28;
		}
		break;
	default:
		dnum = 30;
		break;
	}

	while (num <= dnum) // �ش� '��'�� ���� ���� ����Ѵ�.
	{
		printf("%02d   ", num);
		num++;
		dayofweek++;
		if ((dayofweek % 7) == 0) // �� ~ �ϱ��� ����ϰ� ���� ��ĭ �Ʒ��� �̵��Ѵ�.
			printf("\n");
	}
}

void Sequence(int year)
{
	char* str[] =
	{ "Sun", "Mon", "Tue", "Wed", "Tur", "Fri", "Sat" };

	if ((year < 2000) || (year > 2030))
	{
		printf("�⵵: 2000 ~ 2030");
		PressEnter();
		return 0;
	}
	system("cls");
	/*�⵵�� ������ �� ���� 1~12������, ������ �ϼ��� ���ϱ��� ex)2020-1-31 �ݿ���*/
	YearMonthDay(year,str);
	PressEnter();
}

void YearMonthDay(int year, char** str)
{
	int leepyear;
	int i,j;
	int month = 13;
	int ysumday = 0;
	int sumday = 0;
	int m_day;
	int week;

	/*����üũ*/
	leepyear = LeepYear(year); // ������ 1 �ƴϸ� 0

	/*���� �ϼ��� �ٲٱ�*/
	for (i = 1; i < year; i++)
	{
		if (LeepYear(i) == 0)
			ysumday += 365;
		else if (LeepYear(i) == 1)
			ysumday += 366;
	}

	/*���� �ϼ��� �ٲٱ�*/
	for (i = 1; i < month; i++) // ���� �ϼ��� �ٲ۴�(���� ���)
	{
		sumday = ysumday;
		for (j = 1; j < i + 1; j++) // i�� 1�� �� j�� 1, i�� 2�� �� j�� 1,2
		{
			/*1���϶� 31, 2���϶� 1�� + 2��, 3���϶� 1�� + 2�� + 3��...*/		
			switch (j)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				sumday += 31;
				m_day = 31;
				break;
			case 2:
				if (LeepYear(year) == 1)
				{
					sumday += 29; // ������ �Ϸ簡 �� ����.
					m_day = 29;
				}
				else
				{
					sumday += 28;
					m_day = 28;
				}
				break;
			default:
				sumday += 30;
				m_day = 30;
				break;
			}
		}
		week = Dayofweek(sumday);
		/*����ġ���� ���� �����ԵǸ� */
		printf("%d-%d-%d: %s\n", year, i, m_day, str[week]); //��-��-��: ����
	}
}