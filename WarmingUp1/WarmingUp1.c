#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define LEN 61 // ������ �������� null ����

int check(char str[]); // ����ó��
void order(char str[]); // ��ɾ� �Է�
void upper(char str[]); // e�� �빮�ڷ� ����
void rdword(char str[]); // blank�� ���� ���� ���
int wordcount(char str[]); // �ܾ� ���� ���
void change(char str[]); // ��ҹ��� ��ȯ
void shift(char str[], char ch); //�� �� ����Ʈ

int main()
{
	char str[LEN];
	int loop = 1;

	while (loop)
	{
		printf("[�ִ� 60����, ������, ������ ���ڴ� .�Է�]\n");

		gets_s(str, LEN); // �ִ� 61���ڱ��� ����. ���ʹ� null���ڷ� ���� ��.
		loop = check(str); // ������ �������� ���ϸ� ���� �Է� �ݺ�.
	}

	/*�˻縦 �ùٸ��� ��ġ�� while���� �������´�.*/
	order(str);
}

int check(char str[])
{
	int i;
	int loop = 1;
	int len = strlen(str);

	printf("%d���� �����ڸ� �˻��մϴ�...\n", len);

	/*������ ���̴� �ּ� 2������ �Ѵ�.Enter�� ������ ���� ���� 0��, ù���忡 ��ħǥ�� ��� ������ �� ���� 1��
	��ħǥ�� ���� �ʰ� ���ڸ� �Է��� �ÿ��� ���� 1���ε�, �� ������ �� ����ó�� �ϴٺ��� �ڵ尡 ��û���� ������� ��.
	ó������ ���� ���̸� 2 �̻����� �����Ѵ�.*/
	if (len >= 2)
	{
		/*�� �ܿ� �ʿ��� ����ó���� ù��° ���ڰ� ������ �����ڷ� ������ �Ǿ�� �Ѵ�.
		�׸��� ������ ���ڴ� ��ħǥ�� ������ �Ѵ�.
		���� ��ħǥ �ٷ� �տ��� �����ڰ� �־���Ѵ�.
		������� purple   . �̷��� �Ǹ� �ȵȴ�. purple. Ȯ�� purple  color. �̷������� �Ǿ�� �Ѵ�.
		���������� �������� .�� ���̴� �� ����� ��� ���ڴ� �����ڿ� ���鹮�ڷθ� �̷�������Ѵ�.
		����ó���� �Ϸ��� �� ����.*/
		if (isalpha(str[0]) && isalpha(str[len - 2]) && str[len - 1] == '.')
		{
			for (i = 0; str[i] != '.'; i++) // ��ħǥ�� ������ ������ �˻��Ѵ�.
			{
				if (!(isalpha(str[i]) || isblank(str[i])))
				{
					printf("�ùٸ� ������ �Է��Ͽ� �ֽʽÿ�\n");
					return loop;
				}
			}
			loop = 0;
			return loop;
		}
		else
		{
			printf("�ùٸ� ������ �Է��Ͽ� �ֽʽÿ�\n");
			return loop;
		}
	}

	else
	{
		printf("�ùٸ� ������ �Է��Ͽ� �ֽʽÿ�\n");
		return loop;
	}
}

void order(char str[])
{

	char ch;
	int count = 0;

	while (1)
	{
		system("cls");
		printf("[�Է��Ͻ� ����]\n");
		puts(str);
		printf("[���� ����: %d��]\n", count);
		printf("[��ɾ� ���]\n");
		printf("e/E: �ܾ e �Ǵ� E�ڰ� �ִ� ��쿡�� �� �ܾ ��� �빮�ڷ� �ٲٰ� ���\n");
		printf("f/F: ��� ���鿡 ������ ����(@, %%, # �Ǵ� .)�� �ְ� ���\n");
		printf("l/L: �ܾ��� ������ ��� (������ �������� �ܾ� �и��Ѵ�)	\n");
		printf("c/C: �빮�ڴ� �ҹ��ڷ�, �ҹ��ڴ� �빮�ڷ� �ٲٱ�\n");
		printf("a/A: ������ ���ڸ� ����/�������� �� ���ھ� �̵��Ѵ�.\n");
		printf("q/Q: ���α׷��� ����\n");
		printf("��ɾ� �Է�: ");
		scanf_s(" %c", &ch);

		switch (ch)
		{
		case 'e':
		case 'E':
			upper(str);
			break;

		case 'f':
		case 'F':
			rdword(str);
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
			shift(str, ch);
			break;

		case 'q':
		case 'Q':
			printf("���α׷��� �����մϴ�.");
			return 0;
		}
	}
}

void upper(char str[])
{
	int i = 0;
	int num;
	int len = strlen(str);

	for (int i = 0; i < len - 1; i++)
	{
		if (str[i] == 'e')
		{
			num = i;
			while (isalpha(str[i]))
			{
				str[i] = toupper(str[i]);
				i++;
			}
			i = num;
			while (isalpha(str[i]) && i!=0)
			{	
		
				str[i] = toupper(str[i]);
				i--;
				if(i == 0)
					str[i] = toupper(str[i]);

			}
			i = num;
		}
	}
}

int wordcount(char str[])
{
	int waiting = 1;
	int i;
	int wc = 0;
	int len = strlen(str);

	for (i = 0; i < len - 1; i++)
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

		else if (isupper(str[i]))
			str[i] = tolower(str[i]);
	}
}

void shift(char str[], char ch)
{
	/*�� �տ� ���ڸ� temp������ �����س��� �� �� �ڿ� �ִ� ��� ���ڸ� . �����ϰ� ������ ����.
	�� �� . �ٷξտ� temp������ ������ �� ���ڸ� �����Ѵ�.
	�ڷ� ���� ���� �̿� �ݴ�� �����ϸ� �ȴ�.*/
	int i;
	int temp;
	int len = strlen(str);


	temp = str[len - 1];

	if (len > 2) // ab. ��ħǥ ���� �ּ� ���ڰ� 3�� �̻��̾�� ����Ʈ ����.		
	{
		if (ch == 'a')
		{
			temp = str[0];
			for (i = 0; i < len - 2; i++) // ab. 3��, abc. 4��
				str[i] = str[i + 1];
			str[len - 2] = temp;
		}

		else if (ch == 'A')
		{
			temp = str[len - 2];
			for (i = len - 1; i > 1; i--) // ab. 3��, abc. 4��
				str[i - 1] = str[i - 2];
			str[0] = temp;
		}
	}
	return 0;
}

void rdword(char str[])
{
	int i;
	int random;
	int len = strlen(str);
	srand(time(NULL));

	for (i = 0; i < len - 1; i++)
	{
		random = rand() % 4;
		if (isblank(str[i]))
		{
			if (random == 0)
				str[i] = '%';
			else if (random == 1)
				str[i] = '@';
			else if (random == 2)
				str[i] = '#';
			else if (random == 3)
				str[i] = '.';
		}
		else if ((str[i] == '%') || (str[i] == '#') || (str[i] == '@') || (str[i] == '.'))
		{
			str[i] = ' ';
		}
	}
	return 0;
}