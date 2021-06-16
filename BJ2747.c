#include<stdio.h>

int main(void) {
	int array[50] = { 0, };
	array[1] = 1;
	for (int i = 2; i < 50; i++) {
		array[i] = array[i - 1] + array[i - 2];
	}
	int n;
	scanf("%d", &n);
	printf("%d", array[n]);
	return 0;
}
