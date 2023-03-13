#include <stdio.h>
#include <conio.h>
#include <windows.h>

void Calander(int year, int month, int day); // 달력출력
int Error(int year, int month, int day); // 예외처리
void PressEnter(); // 엔터눌러야 다음 작업으로 넘어감
int SumDay(int year, int month, int day); // 총 일수 구하기
int LeepYear(int year); // 윤년이면 1 아니면 0반환
int Dayofweek(int sumday); // 요일구하기
void Output(char** str, int dayofweek, int year, int month); // 화면에 요일 출력
void Sequence(int year);
void YearMonthDay(int year, char** str);

int main()
{
	int year = 2023;
	int month = 3;
	int day = 1;
	char ch;

	Calander(year, month, day); // 처음엔 2023/3/1 기본값
	while (1)
	{
		system("cls");
		printf("[c: 달력 / f/F: 마지막날짜, 요일]\n");
		ch = _getch();

		if (ch == 'c') // 달력을 출력할 때
		{
			printf("년 월 일: ");
			scanf_s("%d %d %d", &year, &month, &day);

			Calander(year, month, day);
		}

		else if ((ch == 'f') || (ch == 'F')) //해를 입력하면 모든 달의 마지막날의 날짜와 요일을 출력한다.
		{
			printf("년도: ");
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

	/*예외처리 년도는 2000 ~ 2023, 월은 1 ~ 1, 일은 월과 윤년에 맞춰서*/
	while (1)
	{
		check = Error(year, month, day);
		if (check == 0)
		{
			PressEnter();
			return 0;
		}
		else // 제대로 입력이 됬다면 반복문을 빠져나가고 달력 출력을 시작한다.
		{
			break;
		}
	}

	system("cls");//여태까지 출력한거 초기화해주고 달력만 출력한다.
	sumday = SumDay(year, month, day); // 1년 1월 1일부터 총 일수를 구해줘야한다.
	dayofweek = Dayofweek(sumday); // 계산한 일수로 요일구하기
	printf("%d/%02d/%02d: %s\n", year, month, day, str[dayofweek]);
	Output(str, dayofweek, year, month);
	PressEnter();
}

int Error(int year, int month, int day)
{
	int num = 0;
	int eday; //Error함수의 day
	if (year >= 0 && year <= 2030) // 년 확인
	{
		if (month >= 0 && month <= 12) //월 확인
		{
			switch (month) //일 확인
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
					eday = 29; // 윤년은 하루가 더 많다.
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
			/*일 비교*/
			if ((day >= 1) && (day <= eday)) //일 까지 제대로 입력이 되었다면
			{
				num = 1;
				return num;
			}
			else
			{
				printf("%d월의 일의 범위: 1 ~ %d", month, eday);
				return num;
			}
		}

		else
		{
			printf("월의 범위: 1 ~ 12");
			return num;
		}
	}

	else
	{
		printf("년의 범위: 2000 ~ 2030");
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

int SumDay(int year, int month, int day) // 총 일수 구하기
{
	int i, j;
	int sday; // SumDay의 day
	int sumday = 0;
	int count = 0; //1년 이후로, 평년이면 날짜가 1칸, 윤년이면 날짜가 2칸 밀림
	for (i = 1; i < year; i++) // 년을 일수로 바꾼다.
	{
		if (LeepYear(i) == 0)
			sumday += 365;
		else if (LeepYear(i) == 1)
			sumday += 366;
	}

	for (j = 1; j < month; j++) // 월을 일수로 바꾼다(윤년 계산)
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
				sumday += 29; // 윤년은 하루가 더 많다.
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

	sumday += day; //마지막으로 일수를 구한다.
	return sumday; //다 더한 값 반환
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

	for (j = 0; j < dayofweek; j++) // 공백
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
			dnum = 29; // 윤년은 하루가 더 많다.
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

	while (num <= dnum) // 해당 '월'의 일을 전부 출력한다.
	{
		printf("%02d   ", num);
		num++;
		dayofweek++;
		if ((dayofweek % 7) == 0) // 월 ~ 일까지 출력하고 나면 한칸 아래로 이동한다.
			printf("\n");
	}
}

void Sequence(int year)
{
	char* str[] =
	{ "Sun", "Mon", "Tue", "Wed", "Tur", "Fri", "Sat" };

	if ((year < 2000) || (year > 2030))
	{
		printf("년도: 2000 ~ 2030");
		PressEnter();
		return 0;
	}
	system("cls");
	/*년도를 가지고 그 해의 1~12월까지, 마지막 일수와 요일까지 ex)2020-1-31 금요일*/
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

	/*윤년체크*/
	leepyear = LeepYear(year); // 맞으면 1 아니면 0

	/*년을 일수로 바꾸기*/
	for (i = 1; i < year; i++)
	{
		if (LeepYear(i) == 0)
			ysumday += 365;
		else if (LeepYear(i) == 1)
			ysumday += 366;
	}

	/*달을 일수로 바꾸기*/
	for (i = 1; i < month; i++) // 월을 일수로 바꾼다(윤년 계산)
	{
		sumday = ysumday;
		for (j = 1; j < i + 1; j++) // i가 1일 때 j는 1, i가 2일 때 j는 1,2
		{
			/*1월일땐 31, 2월일땐 1월 + 2월, 3월일땐 1월 + 2월 + 3월...*/		
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
					sumday += 29; // 윤년은 하루가 더 많다.
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
		/*스위치문을 빠져 나오게되면 */
		printf("%d-%d-%d: %s\n", year, i, m_day, str[week]); //년-월-일: 요일
	}
}