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

//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));//��Ҫ�ļ��p�Ƿ��ǿյ�ַ��Ҳ���Ǽ��malloc�Ƿ񿪱ٳɹ���
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//			printf("%d ", *(p + i));
//		}
//	}
//	free(p);//�ͷſռ䣬�������ܶ���룬Ӧ�ý�ʡ���ÿռ䡣
//	p = NULL;//����p�ĺۼ�����ֹ�����ҵ�֮ǰ��ʹ�õĶ����ڴ棬���Ӱ�ȫ��
//	return 0;
//}

//08.05������̬�ڴ濪�ٺ�����ע�����


//�������������ԭʼ�ڴ没�������д�Ͽ��������Ĵ��룬���Էַ���崻���
//int main()
//{//�ô��������ڴ޿��������ͷţ���ѭ�����١����������ڴ�һֱռ�ã�ֱ����������������ڴ�й©��
//	while (1)
//	{
//		malloc(1);
//	}
//	return 0;
//}


//������
//�������������ʲô���⣿
//ԭ����
//void Getmemory(char* p)
//{
//	p = (char*)malloc(100);//���ٵĶ����ռ丳����p������p��str�Ĵ�ֵ����������p���ٵĿռ䱻�ջء�str��û�иı䡣
//}//���ٵĶ�̬�ڴ���δ�ͷ�,�����Ҳ���������ڴ�й©��
//
//void Test(void)
//{
//	char* str = NULL;
//	Getmemory(str);//����������Σ�����ȥ����str��ֵ��
//	strcpy(str, "hello bit");//str��NULL���ַ���������ȥ�����Գ��������
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//�޸ĵ�һ��д��
//void Getmemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	Getmemory(&str);
//	strcpy(str, "hello bit");
//	printf(str);
//
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//�޸ĵڶ���д��
char* Getmemory(char* p)
{
	p = (char*)malloc(100);
	return p;
}
void Test(void)
{
	char* str = NULL;
	str = Getmemory(str);
	strcpy(str, "hello bit");
	printf(str);
	
	free(str);
	str = NULL;
}
int main()
{
	Test();
	return 0;
}