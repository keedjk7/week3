#include<stdio.h>

int main() {
	char Keep[50][50];
	int input;
	scanf_s("%d", &input);
	for (int i = 0; i < input; i++) {
		scanf_s("%s", Keep[i], 50);
	}

}