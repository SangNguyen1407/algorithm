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

int partition(int *arr, int low, int high)
{
	int pivot = arr[high];//先頭要素をpivotとする
	int i = low - 1; 
	
	for (int j = low; j < high; j++)
	{
		//pivotより小さいものを左へ、大きいものを右へ
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	
	return (i+1);
}

int quickSort(int *arr, int low, int high)
{
	int pivot = 0;
	int left_pos = 0, high_pos = 0;
	
	if (arr == NULL)
	{
		return RST_ERROR;
	}
	
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi-1);
		/*piは*/
		quickSort(arr, pi+1, high);
	}
	return RST_SUCCESS;
}

int main (){
    int arr[] = {1, 100, 67, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
	int ret = quickSort(arr, 0, size-1);

    cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << endl;
}