#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}
void bubble_sort(int list[], int n) {
	int i, j,k,sum=0;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (list[j] > list[j + 1]) {
				swap(&list[j], &list[j + 1]);
			}
		}
	}
	for (k = 0; k < n; k++) {
		sum += list[k];
	}
	printf("%d \n", sum);
}
int main_ATM() {
	int i,a, b;
	int p[1000];
	scanf_s("%d", &a);
	for (i = 0; i < a; i++) {
		scanf_s("%d",&b);
		p[i] = b;
	}
	bubble_sort(p, a);
	return 0;
}

