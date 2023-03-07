#include <stdio.h>
#include <ctype.h>

#define LEN 61
int check();

int main()
{
	char str[LEN];
	int loop = 1;
	while (loop)
	{
		printf("[최대 60문자, 영문자, 마지막 글자는 .입력]\n");

		gets_s(str, LEN); // 최대 61문자까지 가능. 엔터는 null문자로 변경 됨.
		loop = check(str); // 조건을 만족하지 못하면 무한 입력 반복.
		puts(str);
	}
	printf("완료");
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
		예외처리는 완료한 것 같다.*/
		if (isalpha(str[0]) && isalpha(str[len-2]) && str[len - 1] == '.')
		{
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
