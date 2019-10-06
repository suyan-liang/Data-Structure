#include<iostream>
using namespace std;
//归并排序有两步，1.分割 2. 合并
int temp[100];
void MergeSort(int data[], int l, int r)
{
	//如果左边界大于等于右边界了，直接return ，因为分到头了
	if (l >= r)
		return;
	//以mid为中间值将区间分成两段 [l,mid]和[mid+1,r]，分别进行归并（分治）
	int mid = (l + r) / 2;
	MergeSort(data, l, mid);
	MergeSort(data, mid + 1, r);
	//如果走到这一步，说明已经分割完毕，而且此时的data数组中[l,mid]和[mid+1,r]分别有序，只需要进行合并操作
	//接下来，经典的合并操作
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (data[i] < data[j])
			temp[k++] = data[i++];
		else
			temp[k++] = data[j++];
	}
	while (i <= mid)
		temp[k++] = data[i++];
	while (j <= r)
		temp[k++] = data[j++];
	//把temp中的数据再放到data里面，毕竟是还要进行下面的排序呢
	for (int m = l, n = 0; m <= r; m++, n++)
	{
		data[m] = temp[n];
	}
}
void PrintMergeSort(int data[], int len)
{
	for (int i = 0; i <= len; i++)
	{
		cout << data[i] << "   ";

	}
}
int main()
{
	cout << "MergeSort!" << endl;
	int data[100] = { 156,12,56,1231,45,2,0,2,1 };
	int len = 9;
	MergeSort(data, 0, len-1);
	PrintMergeSort(data, len-1);
	return 0;
}
