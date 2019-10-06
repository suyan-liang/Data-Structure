#include<iostream>
#include<algorithm>
using namespace std;
//ð�����򣬱����Ͼ���ð�ݰ�����δ��������н��в�����ÿ��ðһ�������С����Ԫ����ȥ
void BubbleSort(int data[],int len)//len��������Ԫ�صĸ�����û�취��ֻ������
{
	for (int i = 0; i < len - 1; i++)//ֻ��Ҫðlen-1�ξ����ˣ����һ��ֱ�Ӿ���������ˣ���������
	{
		for (int j = 0; j < len - 1 - i; j++)//len - 1 - i����ʣ���δ��������� 
		{
			if (data[j] > data[j + 1])
			{
				swap(data[j], data[j + 1]);
			}
		}
	}
}
//ѡ������һ������ı������ǣ���n-1��Ԫ��,���н�������ΰ��ӣ���������ν��������ŵ�ǰ����������ĩβ
void SelectSort(int data[], int n)
{
	int i;//�������������ĵ�һ��Ԫ��
	for (i = 0; i < n - 1; i++)//n-1��ԭ���ð������һ��
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (data[min] > data[j])
			{
				min = j;
			}
		}//��������ΰ���
		swap(data[i], data[min]);//�ŵ�ǰ�����һ��
	}
}
void PrintSort(int data[], int n)
{
	cout << "�źõ���������" << endl;
	for (int i = 0; i < n; i++)
	{
		cout <<data[i] << "   ";
	}
}

//------------------------------������û�õĺ���-----------------------------------
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
	cout << "���������������ֵĸ���" << endl;
	int n;
	cin >> n;
	cout << "����������" << endl;
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



