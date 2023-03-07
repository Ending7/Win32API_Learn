#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>

#define LEN 61 // 마지막 공간에는 null 삽입

int check(char str[]); // 예외처리
void order(char str[]); // 명령어 입력
void upper(char str[]); // 대문자 변경
int wordcount(char str[]); // 단어 개수 출력
void change(char str[]); // 대소문자 변환
void shift(char str[], char ch); //좌 우 시프트

int main()
{
	char str[LEN];
	int loop = 1;

	while (loop)
	{
		printf("[최대 60문자, 영문자, 마지막 글자는 .입력]\n");

		gets_s(str, LEN); // 최대 61문자까지 가능. 엔터는 null문자로 변경 됨.
		loop = check(str); // 조건을 만족하지 못하면 무한 입력 반복.
	}

	/*검사를 올바르게 마치면 while문을 빠져나온다.*/
	order(str);
}

int check(char str[])
{
	int i;
	int loop = 1;
	int len = strlen(str);

	printf("%d개의 영문자를 검사합니다...\n", len);

	/*문자의 길이는 최소 2개여야 한다.Enter만 눌렀을 때는 문자 0개, 첫문장에 마침표만 찍고 끝냈을 시 문자 1개
	마침표를 찍지 않고 문자만 입력할 시에도 문자 1개인데, 이 모든것을 다 예외처리 하다보니 코드가 엄청나게 길어지게 됨.
	처음부터 문자 길이를 2 이상으로 설정한다.*/
	if (len >= 2)
	{
		/*그 외에 필요한 열외처리는 첫번째 문자가 무조건 영문자로 시작이 되어야 한다.
		그리고 마지막 문자는 마침표로 끝나야 한다.
		또한 마침표 바로 앞에는 영문자가 있어야한다.
		예를들어 purple   . 이렇게 되면 안된다. purple. 확은 purple  color. 이런식으로 되어야 한다.
		마지막으로 마지막에 .가 쓰이는 것 빼고는 모든 문자는 영문자와 공백문자로만 이루어져야한다.
		예외처리는 완료한 것 같다.*/
		if (isalpha(str[0]) && isalpha(str[len - 2]) && str[len - 1] == '.')
		{
			for (i = 0; str[i] != '.'; i++) // 마침표가 나오기 전까지 검사한다.
			{
				if (!(isalpha(str[i]) || isblank(str[i])))
				{
					printf("올바른 문장을 입력하여 주십시오\n");
					return loop;
				}
			}
			loop = 0;
			return loop;
		}
		else
		{
			printf("올바른 문장을 입력하여 주십시오\n");
			return loop;
		}
	}

	else
	{
		printf("올바른 문장을 입력하여 주십시오\n");
		return loop;
	}
}

void order(char str[])
{
	
	char ch;
	char str2[61];
	int count =0; 

	while (1)
	{
		system("cls");
		printf("[입력하신 문장]\n");
		puts(str);
		printf("[문자 개수: %d개]\n", count);
		printf("[명령어 목록]\n");
		printf("e/E: 단어에 e 또는 E자가 있는 경우에는 그 단어를 모두 대문자로 바꾸고 출력\n");
		printf("l/L: 단어의 개수를 출력 (공백을 기준으로 단어 분리한다)	\n");
		printf("c/C: 대문자는 소문자로, 소문자는 대문자로 바꾸기\n");
		printf("a/A: 문장의 문자를 좌측/우측으로 한 문자씩 이동한다.\n");
		printf("q/Q: 프로그램을 종료\n");
		printf("명령어 입력: ");
		scanf_s(" %c",&ch);

		switch (ch)
		{
		case 'e':
		case 'E':
			upper(str);
			break;

		case 'l':
		case 'L':
			count = wordcount(str);
			break;

		case 'c':
		case 'C':
			change(str);
			break;

		case 'a':
		case 'A':
			shift(str,ch);
			break;

		case 'q':
		case 'Q':
			printf("프로그램을 종료합니다.");
			return 0;
		}
	}
}

void upper(char str[])
{	
	int i = 0;
	int len = strlen(str);

	for (i = 0; i < len; i++)
	{
		if ((str[i] == 'e') || (str[i] == 'E'))
			str[i] = toupper(str[i]);
	}
	
}

int wordcount(char str[])
{
	int waiting = 1;
	int i;
	int wc = 0;
	int len = strlen(str);

	for (i = 0; str[i] != '.'; i++)
	{
		if (isalpha(str[i]))
		{
			if (waiting)
			{
				wc++;
				waiting = 0;
			}
		}
		else
			waiting = 1;
	}
	
	return wc;
}

void change(char str[])
{
	int i;
	int len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (islower(str[i]))
			str[i] = toupper(str[i]);
		
		else if(isupper(str[i]))
			str[i] = tolower(str[i]);
	}
}

void shift(char str[], char ch)
{
	/*맨 앞에 문자를 temp변수에 저장해놓은 뒤 그 뒤에 있는 모든 문자를 . 제외하고 앞으로 당긴다.
	그 후 . 바로앞에 temp변수에 저장해 둔 문자를 저장한다.
	뒤로 당기는 것은 이에 반대로 수행하면 된다.*/
	int i;
	int temp;
	int len = strlen(str);


		temp = str[len - 1];

	if (len > 2) // ab. 마침표 포함 최소 문자가 3개 이상이어야 시프트 가능.
	{
		if (ch == 'a')
		{
			temp = str[0];
			for (i = 0; i < len - 2; i++) // ab. 3개, abc. 4개
				str[i] = str[i + 1];
			str[len - 2] = temp;
		}

		else if (ch == 'A')
		{
			temp = str[len-2];
			for (i = len-1; i > 1; i--) // ab. 3개, abc. 4개
				str[i-1] = str[i-2];
			str[0] = temp;
		}
	}
	return 0;
}