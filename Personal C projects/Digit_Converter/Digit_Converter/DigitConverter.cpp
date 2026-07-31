#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

int select_the_digits(int a, int b);
int Boolean(int a);
int Octal(int a);
int Hexadecimal(int a);

int main() {
	int num, digit;
	printf("Enter the number you want to express in another digit: ");
	scanf("%d", &num);
	printf("\n");
	printf("Enter digits you want to express as(Binary: 2, Octal: 8, Hexadecimal: 16): ");
	scanf("%d", &digit);
	int seltd = select_the_digits(num, digit);
	if (seltd == 0) return 0;
}

int select_the_digits(int a, int b) {
	if (b == 2) { Boolean(a); return 0; }
	else if (b == 8) { Octal(a); return 0; }
	else if (b == 16) { Hexadecimal(a); return 0; }
	else {
		printf("think it again!!"); return 0;
	}
}

int Boolean(int a) {
	int arr[100];
	int prime = 0;
	int b = a;
	while (b > 0) {
		b = b / 2;
		prime++;
	}

	for (int i = 0; i < prime; i++) {
		arr[i] = a % 2;
		a = a / 2;
	}
	printf("0b");
	for (int i = prime - 1; i >= 0; i--) {
		printf("%d", arr[i]);
	}
}

int Octal(int a) {
	int arr[100];
	int prime = 0;
	int b = a;
	while (b > 0) {
		b = b / 8;
		prime++;
	}

	for (int i = 0; i < prime; i++) {
		arr[i] = a % 8;
		a = a / 8;
	}
	printf("0o");
	for (int i = prime - 1; i >= 0; i--) {
		printf("%d", arr[i]);
	}
}

int Hexadecimal(int a) {
	char charray[100] = { 0 };
	int arr[100] = { 0 };
	int prime = 0;
	int b = a;
	while (b > 0) {
		b = b / 16;
		prime++;
	}

	for (int i = 0; i < prime; i++) {
		arr[i] = a % 16;
		a = a / 16;
	}
	printf("0x");

	for (int i = prime - 1; i >= 0; i--) {
		if (arr[i] == 10) charray[i] = 'A';
		else if (arr[i] == 11) charray[i] = 'B';
		else if (arr[i] == 12) charray[i] = 'C';
		else if (arr[i] == 13) charray[i] = 'D';
		else if (arr[i] == 14) charray[i] = 'E';
		else if (arr[i] == 15) charray[i] = 'F';
		else printf("%d", arr[i]);
		printf("%c", charray[i]);
	}
}