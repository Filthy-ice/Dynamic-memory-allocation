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
//1.�������������ʲô���⣿
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
//char* Getmemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = Getmemory(str);
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


//2.�������test������������ʲô��
//char* Getmemory()
//{
//	char p[] = "hello bit";//������һ����ʱ����p������ַ�����
//	return p;//��p�ĵ�ַ���أ�����֮��p�������١�
//}
//void Test()
//{
//	char* str = NULL;
//	str = Getmemory();//�����������bug�Ϳ�Getmemory������Ĵ��롣//p�������٣������ֵ���٣�strֻ���յ���p����ʼ��ַ��
//	printf(str);//���������ӡ����str�ڴ洦�����ݣ���������������ֵ��//���ڷǷ����ʡ�
//}
//int main()
//{
//	Test();
//	return 0;
//}

//int* test()
//{
//	int a = 10;//ջ������������test���١����Ҫʹa�������٣���Ҫʹ��static��
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	printf(*p);//�Ƿ����ʡ�
//	return 0;
//}

//3.����������еĽ����ʲô��
//void Getmemory(char** p, int num)
//{
//	*p = (char*)malloc(num);//û���ж��Ƿ񿪱ٳɹ���
//}
//void Test()
//{
//	char* str = NULL;
//	Getmemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);//û���ͷŶ������ٵ��ڴ档û���ÿգ������ڴ�й©��Σ�ա�
//}
//int main()
//{
//	Test();
//	return 0;
//}

//4.����Test������ʲô���Ľ����
//void Test()
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);//��ʱ�Ѿ���str�ͷ���,���ǲ�û���ÿգ������Կ���ͨ��str�������ҵ�����ڴ�Σ��������ڷǷ����ʡ�
//	if (str != NULL)
//	{
//		strcpy(str, "world");//�������ᱻ���У��������ڷǷ������ڴ档str��������ڴ��Ѿ����ͷš�
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}

//��������ʹ��
//��һ��ʹ�÷���
//struct S
//{
//	int a;
//	int arr[];
//};
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	ps->a = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//	struct S* ptr = realloc(ps, 44);
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	free(ps);
//	ps = NULL;
//	return 0;
//}

//�ڶ���ʹ�÷���
struct S
{
	int a;
	int* arr;
};
int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S));//ֱ�ӴӶ������ٵ��ڴ档
	if (ps == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	ps->arr = (int*)malloc(20);//����Ҳ���õĶ��������ڴ档
	if (ps->arr == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	int* ptr = realloc(ps->arr, 40);
	if (ptr != NULL)
	{
		ps->arr = ptr;
	}
	for (i = 5; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}