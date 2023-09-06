#include <iostream>
#include <string.h>

#define RST_SUCCESS 0
#define RST_ERROR  -1

using namespace std;

int merge(int *arr_left, int left_size, int *arr_right, int right_size, int *arr)
{
	int left_pos = 0, right_pos = 0, arr_pos = 0;
	while(left_pos < left_size || right_pos < right_size)
	{
		if (right_pos >= right_size || 
		    (left_pos< left_size && 
			 arr_left[left_pos] < arr_right[right_pos]
			)
		   )
		{
			arr[arr_pos++] = arr_left[left_pos];
			left_pos++;
		}
		else
		{
			arr[arr_pos++] = arr_right[right_pos];
			right_pos++;
		}
	}
	
	return RST_SUCCESS;
}

int mergeSort(int *arr, int arr_size)
{
	if (arr == NULL)
	{
		return RST_ERROR;
	}
	int left_size   = arr_size/2;
	int right_size  = arr_size - left_size;
	int *arr_left  = new int[left_size];
	int *arr_right = new int[right_size];

	if (arr_size > 1)
	{
		for (int i = 0; i< left_size; i++)
		{
			arr_left[i] = arr[i];
		}
		
		for (int i = 0; i< right_size; i++)
		{
			arr_right[i] = arr[left_size+i];
		}

		mergeSort(arr_left, left_size);
		mergeSort(arr_right, right_size);
		merge(arr_left, left_size, arr_right, right_size, arr);

	}
	
	return RST_SUCCESS;
}

int main (){
    int arr[4] = {9,2,3,4};
    int size = sizeof(arr) / sizeof(int);
	int ret = mergeSort(arr, size);

    cout << arr[0] << arr[1] << arr[2] << arr[3] << endl;
}