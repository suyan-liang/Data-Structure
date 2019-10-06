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


int main()
{

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

	return 0;
}


