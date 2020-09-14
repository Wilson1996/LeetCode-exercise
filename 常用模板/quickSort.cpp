/*
* @Author: Williss Taan
* @Date:   2019-08-28 15:07:16
* @Last Modified by:   Wilson.T
* @Last Modified time: 2019-10-05 11:35:56
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int RandomInRange(int start, int end)
{
	srand((unsigned)time(NULL));
	return rand() % (end - start + 1) + start;
}

void Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int Partition(int data[], int length, int start, int end)
{
	if(data == NULL || length <= 0 || start < 0 || end >= length)
	{
		// throw new std::exception("Invalid Parameters.");
		throw exception();
		abort();
	}
	int index = RandomInRange(start, end);
	cout << "index: " << index << endl;
	Swap(&data[index], &data[end]);

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if(data[index] < data[end])
		{
			++small;
			if(small != index)
				Swap(&data[index], &data[small]);
		}
	}
	++small;
	Swap(&data[small], &data[end]);
	return small;
}

void QuickSort(int data[], int length, int start, int end)
{
	if(start == end)
		return;
	int index = Partition(data, length, start, end);
	if(index > start)
		QuickSort(data, length, start, index - 1);
	if(index < end)
		QuickSort(data, length, index + 1, end);
}

int main(int argc, char const *argv[])
{
	int data[] = {5, 6, 7, 9, 1, 7, 3, 8, 8, 10};
	// cout << Partition(data, 10, 0, 9) << endl;
	QuickSort(data, 10, 0, 9);
	for (int i = 0; i < 10; ++i)
	{
		cout << data[i] << ",";
	}
	cout << endl;
	return 0;
}