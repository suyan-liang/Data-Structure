//快排的基本思想是在先对数组操作，使数据区间[l,r]里面找到一点k使[l,k-1]的元素都小于k,[k+1,r]的元素都大于k，注意是k-1和k+1哦，k是已经排好的啦
//然后分别在[l,k-1]和[k+1,r]两个区间内分别快排，最终得到一个有序序列
#include<iostream>
#include<algorithm>
using namespace std;
//找到那个k的方法是Partition，有不同的方法，不同的Partition在跑完一遍之后得到的序列也不同，这个版本是课本上的	
int Partition(int data[], int l, int r)
{
	int temp = data[l];
	while (l < r)
	{
		while (l < r && data[r] >= temp)
			r--;
		data[l] = data[r];
		while (l < r && data[l] <= temp)
			l++;
		data[r] = data[l];
	}
	data[l] = temp;
	return l;
}
//交换版本的Partition
int Partition2(int data[], int l, int r)
{
	int i = l;
	int temp = data[l];
	while (l < r)
	{
		while (l < r && data[r] >= temp)
			r--;
		while (l < r && data[l] <= temp)
			l++;
		if (l < r)
			swap(data[l], data[r]);
	}
	swap(data[l],data[i]);
	return l;
}
void QuickSort(int data[], int l, int r)
{
	if (l < r)
	{
		int k = Partition2(data, l, r);
		QuickSort(data, l, k-1);
		QuickSort(data, k + 1, r);
	}
}
#if 1
void QuickSort2(int data[], int l, int r)
{
		if (l >= r) 
			return;
		int i = l , j = r , x = data[l];
		while (i < j)
		{
			while (data[i] < x)
			i++;
		    while (data[j] > x)
			j--;
			if (i < j) 
				swap(data[i], data[j]);
			else
				break;
		}
		QuickSort(data, l, j);
		QuickSort(data, j + 1, r);
	
}
#endif
void quick_sort(int q[], int l, int r)
{
	if (l >= r) return;

	int i = l - 1, j = r + 1, x = q[l];
	while (i < j)
	{
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		if (i < j) swap(q[i], q[j]);
		else break;
	}
	quick_sort(q, l, j), quick_sort(q, j + 1, r);
}
void PrintQuickSort(int data[], int len)
{
	for (int i = 0; i <= len; i++)
	{
		cout << data[i] << "   ";
	}
}
int main()
{
	cout << "QuickSort!" << endl;
	//cout << "woc???" << endl;
	int data[100] = { 156,12,56,1231,45,2,0,2,1 };
	int len = 9;
	cout << "QuickSort 1:" << endl;
	QuickSort(data, 0, len - 1);
	PrintQuickSort(data, len - 1);
	cout << endl;
	cout << "QuickSort 2:" << endl;
	QuickSort2(data, 0, len - 1);
	PrintQuickSort(data, len - 1);
	cout << endl;
	cout << "没有Partition的版本" << endl;
	quick_sort(data, 0, len - 1);
	PrintQuickSort(data, len - 1);
	return 0;
}
