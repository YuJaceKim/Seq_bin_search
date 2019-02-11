#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

#define MAX 100000

int arr[MAX];

int seq_search (int key, int low, int high) {
	int i;
	arr[high + 1] = key;
	for (i = low; arr[i] != key; i++) {
		;
	}
	if (i == (high + 1)) return -1;
	else return i;
}

int search_binary (int key, int low, int high) {
	int middle;
	if (low <= high) {
		middle = (low + high) / 2;
		if (key == arr[middle]) 
			return middle;
		else if (key < arr[middle])
			return search_binary(key, low, middle - 1);
		else
			return search_binary(key, middle + 1, high);
	}
	return -1;
}


int main(int argv, char *argc[]) {

	const int input;
	int i, j;
	int found = 1;
	int odd = 1;
	int ran_odd[MAX];
	int ran_even[MAX];
	
	clock_t start, end;
	float result = 0;

	printf("Input data size: ");
	scanf("%d", &input);

	

	printf("\n%d odd numbers are generated\n\n", input / 2);

	// ÀÔ·ÂÇÑ ¼ýÀÚÀÇ ¹Ý¸¸Å­ È¦¼ö »ý¼º
	for (i = 0; i < input / 2; i++) {
		arr[i] = odd;
		odd += 2;
		//printf("%d ", arr[i]);
	}
	printf("\n");

	srand(time(NULL));

	// Â¦¼ö ·£´ý »ý¼º
	for (i = 0; i < input / 2; i++) {

		again:;
			int r = rand() % input / 2 * 2 + 0;
			for (j = 0; j <= i - 1; j++)
				if (r == ran_even[j])
					goto again;
			ran_even[i] = r;
			//printf("%d ", ran_even[i]);
	}

	printf("\n");

	// È¦¼ö ·£´ý »ý¼º
	for (i = 0; i < input / 2; i++) {

		again2:;
			int r = rand() % input / 2 * 2 + 1;
			for (j = 0; j <= i - 1; j++)
				if (r == ran_odd[j])
					goto again2;
			ran_odd[i] = r;
			//printf("%d ", ran_odd[i]);
		}

	printf("\nEven numbers search time (fail)\n");

	// even seq
	for (i = 0; i < input / 2; i++) {
		start = clock();
		seq_search(ran_even[i], 0, input/2);
		end = clock();
		result += (float)(end - start) / CLOCKS_PER_SEC;
	}
	printf("Seq Search time: %f\n", result);
	float a = result;
	result = 0;

	// even bin
	for (i = 0; i < input / 2; i++) {
		start = clock();
		search_binary(ran_even[i], 0, input / 2);
		end = clock();
		result += (float)(end - start) / CLOCKS_PER_SEC;
	}
	printf("Bin Search time: %f\n", result);
	float b = result;
	result = 0;
	printf("Bin Search %f faster\n", b / a);

	printf("\nOdd numbers search time (success)\n");
	// odd seq
	for (i = 0; i < input / 2; i++) {
		start = clock();
		seq_search(ran_odd[i], 0, input / 2);
		end = clock();
		result += (float)(end - start) / CLOCKS_PER_SEC;
	}
	printf("Seq Search time: %f\n", result);
	a = result;
	result = 0;
	// odd bin
	for (i = 0; i < input / 2; i++) {
		start = clock();
		search_binary(ran_odd[i], 0, input / 2);
		end = clock();
		result += (float)(end - start) / CLOCKS_PER_SEC;
	}
	printf("Bin Search time: %f\n", result);
	b = result;
	result = 0;
	printf("Bin Search %f faster\n", b / a);

		/*printf("Even numbers search time (fail)\n");
		printf("Seq Search time: \n");
		printf("Bin Search time: \n");
		printf("Bin Search  faster\n");

		printf("Odd numbers search time (success)\n");
		printf("Seq Search time: \n");
		printf("Bin Search time: \n");
		printf("Bin Search  faster\n");*/
	
}