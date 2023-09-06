#include <iostream>
#include <string.h>

#define RST_SUCCESS 0
#define RST_ERROR  -1

using namespace std;

int swap(int *a, int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
	
	return RST_SUCCESS;
}

int adjust(int *arr, int arr_size, int rootNodePos)
{
	int key = arr[rootNodePos];
	int checkNodePos = 0;
	
	while (true)
	{
		checkNodePos = (rootNodePos * 2 ) + 1;
		if (checkNodePos > arr_size)
		{
			break;
		}
		
		if (checkNodePos != arr_size)
		{
			if (arr[checkNodePos + 1] > arr[checkNodePos])
			{
				checkNodePos = checkNodePos + 1;
			}
		}
		
		if (key >= arr[checkNodePos])
		{
			break;
		}
		
		arr[rootNodePos] = arr[checkNodePos];
		rootNodePos = checkNodePos;
	}
	arr[rootNodePos] = key;
	
	
	return RST_SUCCESS;
}

int heapSort(int *arr, int arr_size)
{
	int j, v;
	for (int i = (arr_size - 1)/2; i >= 0; i--)
	{
		adjust(arr, arr_size, i);
	}
	
	for (int i = arr_size - 1; i > 0;i--)
	{
		swap(&arr[0], &arr[i]);		
		adjust(arr, i-1, 0);
	}
	
	return RST_SUCCESS;
}

int main (){
    int arr[] = {1, 100, 67, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
	int ret = heapSort(arr, size);

    cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << endl;
}