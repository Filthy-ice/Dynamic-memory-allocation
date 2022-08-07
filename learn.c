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
//下面这个程序有什么问题？
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