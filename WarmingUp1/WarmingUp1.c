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
		printf("[�ִ� 60����, ������, ������ ���ڴ� .�Է�]\n");

		gets_s(str, LEN); // �ִ� 61���ڱ��� ����. ���ʹ� null���ڷ� ���� ��.
		loop = check(str); // ������ �������� ���ϸ� ���� �Է� �ݺ�.
		puts(str);
	}
	printf("�Ϸ�");
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
		����ó���� �Ϸ��� �� ����.*/
		if (isalpha(str[0]) && isalpha(str[len-2]) && str[len - 1] == '.')
		{
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
