#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void bubble_sort(int list[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (list[j] > list[j + 1]) {
				swap(&list[j], &list[j + 1]);
			}
		}
	}
}
int main() {
	int y[9];
	int i,j,k,sum=0;
	for (i = 0; i < 9; i++) {
		scanf("%d", y+i);
	}
	bubble_sort(y, 9);
	i = 0;
	while (i < 9) {
		sum += y[i];
		i++;
	}
	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++) {
			if (sum - y[i] - y[j] == 100) {
				for (k = 0; k < 9; k++) {
					if (k != i && k != j) {
						printf("%d \n", y[k]);
					}
				}
				return 0;
			}
		}
	}
	return 0;
}