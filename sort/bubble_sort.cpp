#include <iostream>
#include <string.h>


using namespace std;

/*bubbleSort*/
int bubbleSort(int *arr, int arr_size)
{
	if (arr == NULL && arr_size < 1){
		return 0;
	}
	
	int temp = 0;
	for(int i = 0; i < arr_size; i++){
		for (int j = arr_size-1; j > i; j--){
			if(arr[j] < arr[j-1]){
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return 1;
}

int main (){
	int arr[5] = {9,2,3,4};
	int ret = bubbleSort(arr, 4);

	cout << "return " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << endl;
}