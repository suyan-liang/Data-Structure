#include<iostream>
#include<algorithm>
using namespace std;
//堆用数组表示，从 1 开始计数
//******重要前提假设 data[s...m]中除了data[s]之外其他的数据都满足堆的性质,所以只需要下沉就行了，不需要考虑上浮的问题********
void HeapAdjust(int data[], int s, int m)
{
	int temp = data[s];
	int j;
	//堆调整中一个重要的原则：每次交换都要把改变了结点所在的那棵树判定一下，这也是这个for循环存在的意义
	for (j = s * 2; j <= m; j *= 2)
	{
		//让j指向左右孩子中大的那个孩子
		if (j < m && data[j] < data[j + 1])
		{
			++j;
		}
		else
		{

		}
		//如果他爹大于儿子中的最大的，就不用调整了，break就行
		if (temp >= data[j])
		{
			break;
		}
		//否则的话，就交换啊，这里可以直接赋值，也可以进行交换，和数据结构课本那个快排差不多
		else
		{
			data[s] = data[j];
			s = j;
		}
	}
	//最后把父结点插到合适的位置
	data[s] = temp;
}
//堆排序的思想，就是先把一个无序的数组构建成为一个二叉堆，然后每次把根节点和最后一个结点进行交换，然后对这时候除了最后一个结点的树进行调整成二叉堆，循环
//大根堆是升序，小根堆是降序。
void HeapSort(int data[],int len)
{
	//看HeapAdjust的代码可以知道，len/2是最后一个非叶子结点，它只有两个叶子结点的孩子，除根节点外满足堆的定义，调整后满足二叉堆，调整后，它爹也满足了，以此类推
	for (int i = len / 2; i > 0; i--)
	{
		HeapAdjust(data, i, len);
	}
	//堆排序
	for (int i = len; i > 1; i--)
	{
		swap(data[i], data[1]);
		HeapAdjust(data, 1, i - 1);
	}
}
void PrintHeapSort(int data[],int len)
{
	for (int i = 1; i <= len; i++)
		cout << data[i] << "    ";
}
int main()
{
	int data[100] = {0, 15,2,46,489,13 };
	int size = 5;
	HeapSort(data, size);
	PrintHeapSort(data, size);
	return 0;
}
