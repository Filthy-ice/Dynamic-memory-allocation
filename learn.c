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
//	struct Stu arr[n];//这种创建变长数组的语法，C99增加的，但是VS至今仍未实施。
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));//必要的检测p是否是空地址，也就是检测malloc是否开辟成功。
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
//	free(p);//释放空间，如果下面很多代码，应该节省可用空间。
//	p = NULL;//消除p的痕迹，防止别人找到之前所使用的堆区内存，更加安全。
//	return 0;
//}

//08.05讲述动态内存开辟函数的注意事项。


//这个代码属于最原始内存病毒，如果写上开机自启的代码，电脑分分钟宕机。
//int main()
//{//该代码属于内崔开辟忘记释放，且循环开辟。导致虚拟内存一直占用，直到计算机死机。（内存泄漏）
//	while (1)
//	{
//		malloc(1);
//	}
//	return 0;
//}


//笔试题
//1.下面这个程序有什么问题？
//原代码
//void Getmemory(char* p)
//{
//	p = (char*)malloc(100);//开辟的堆区空间赋给了p，但是p是str的传值，函数结束p开辟的空间被收回。str并没有改变。
//}//开辟的动态内存尚未释放,并且找不到，造成内存泄漏。
//
//void Test(void)
//{
//	char* str = NULL;
//	Getmemory(str);//这个函数传参，传过去的是str的值？
//	strcpy(str, "hello bit");//str是NULL，字符串穿不过去，所以程序崩溃。
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//修改第一种写法
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

//修改第二种写法
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


//2.下面代码test函数输出结果是什么？
//char* Getmemory()
//{
//	char p[] = "hello bit";//创建了一个临时变量p，存放字符串。
//	return p;//将p的地址返回，但是之后p变量销毁。
//}
//void Test()
//{
//	char* str = NULL;
//	str = Getmemory();//函数结果有无bug就看Getmemory函数里的代码。//p变量销毁，里面的值销毁，str只是收到了p的起始地址。
//	printf(str);//所以这里打印的是str内存处的内容，所以输出的是随机值。//属于非法访问。
//}
//int main()
//{
//	Test();
//	return 0;
//}

//int* test()
//{
//	int a = 10;//栈区创建，出了test销毁。如果要使a不被销毁，需要使用static。
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	printf(*p);//非法访问。
//	return 0;
//}

//3.下面程序运行的结果是什么？
//void Getmemory(char** p, int num)
//{
//	*p = (char*)malloc(num);//没有判定是否开辟成功。
//}
//void Test()
//{
//	char* str = NULL;
//	Getmemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);//没有释放堆区开辟的内存。没有置空，会有内存泄漏的危险。
//}
//int main()
//{
//	Test();
//	return 0;
//}

//4.运行Test函数有什么样的结果？
//void Test()
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);//此时已经将str释放了,但是并没有置空，所以仍可以通过str这个标记找到这块内存段，但是属于非法访问。
//	if (str != NULL)
//	{
//		strcpy(str, "world");//这个代码会被运行，但是属于非法访问内存。str所申请的内存已经被释放。
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}

//柔型数组使用
//第一种使用方法
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

//第二种使用方法
struct S
{
	int a;
	int* arr;
};
int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S));//直接从堆区开辟的内存。
	if (ps == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	ps->arr = (int*)malloc(20);//这里也是用的堆区开辟内存。
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