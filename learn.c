#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

//struct Stu
//{
//	char name;
//	int age;
//};
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	struct Stu arr[n];//���ִ����䳤������﷨��C99���ӵģ�����VS������δʵʩ��
//	return 0;
//}

int main()
{
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));//��Ҫ�ļ��p�Ƿ��ǿյ�ַ��Ҳ���Ǽ��malloc�Ƿ񿪱ٳɹ���
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i;
			printf("%d ", *(p + i));
		}
	}
	free(p);//�ͷſռ䣬�������ܶ���룬Ӧ�ý�ʡ���ÿռ䡣
	p = NULL;//����p�ĺۼ�����ֹ�����ҵ�֮ǰ��ʹ�õĶ����ڴ棬���Ӱ�ȫ��
	return 0;
}