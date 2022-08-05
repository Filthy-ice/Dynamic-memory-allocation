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