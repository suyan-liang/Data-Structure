#include<iostream>
#include<algorithm>
using namespace std;
//冒泡排序，本质上就是冒泡啊，对未排序的序列进行操作，每次冒一个最大（最小）的元素上去
void BubbleSort(int data[],int len)//len是数组中元素的个数，没办法，只能这样
{
	for (int i = 0; i < len - 1; i++)//只需要冒len-1次就行了，最后一个直接就是有序的了，无需再排
	{
		for (int j = 0; j < len - 1 - i; j++)//len - 1 - i就是剩余的未排序的序列 
		{
			if (data[j] > data[j + 1])
			{
				swap(data[j], data[j + 1]);
			}
		}
	}
}
//选择排序，一个形象的比喻就是，对n-1个元素,进行将军里面拔矮子（矮子里面拔将军），放到前面有序区的末尾
void SelectSort(int data[], int n)
{
	int i;//代表着无序区的第一个元素
	for (i = 0; i < n - 1; i++)//n-1的原因和冒泡排序一样
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (data[min] > data[j])
			{
				min = j;
			}
		}//将军里面拔矮子
		swap(data[i], data[min]);//放到前面最后一个
	}
}
void PrintSort(int data[], int n)
{
	cout << "排好的序列如下" << endl;
	for (int i = 0; i < n; i++)
	{
		cout <<data[i] << "   ";
	}
}

//------------------------------下面是没用的函数-----------------------------------
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int C(int n, int k)
{
	if (k == 0 || k == n)
	{
		return 1;
	
	}
	else if(n > k && k > 0)
	{
		return C(n - 1, k) + C(n - 1, k - 1);
	}
}
int fib(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int main()
{
#if 0
	int data[100];
	cout << "请输入想排序数字的个数" << endl;
	int n;
	cin >> n;
	cout << "请输入数字" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
	}

	SelectSort(data, n);
	PrintSort(data, n);
#endif

	cout << fib(2) << endl;
	cout << fib(3) << endl;
	cout << fib(4) << endl;
	cout << fib(5) << endl;
	return 0;
}



