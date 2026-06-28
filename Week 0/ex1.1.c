#include <stdio.h>

void sort(int array[10]);

int main(){
	int array[10] = {3, 1, 5, 2, 4, 8, 9, 6, 7, 10};
	sort(array);

	printf("%i\n", array[5]);
}

void sort(int array[10]){
	for (int i = 0; i < 10; i++){
		int swapped = 0;
		for (int j = 0; j < 10 - i - 1; j++){
			if (array[j] > array[j + 1]){
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
			}
		}

		if (swapped == 0){
		
		}
	}

	return;
}
