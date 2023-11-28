#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* 1166 : 윤년 판별 */
void is_leap_year(int year) {
	if (!(year % 400)) {
		printf("Leap");
		return;
	}
	else
		if (!(year % 4) && year % 100 != 0) {
			printf("Leap");
			return;
		}
	printf("Normal");
}

/* 1173 : 30분전 */
#define MAX_HOUR 24
#define MAX_MINUTE 60
void minutes_ago(int* hour, int* minute) {
	if ((*minute) < 30) (*hour) = ((*hour) - 1 + MAX_HOUR) % MAX_HOUR;
	(*minute) = ((*minute) - 30 + MAX_MINUTE) % MAX_MINUTE;
}

/* 1369 : 빗금 친 사각형 출력하기 */
void comb_square(int n, int k) {
	int position = k - 1;
	if (n == 1) printf("*");
	else {
		for (int i = 0; i < n; i++) {
			if (!position) position += k;
			for (int j = 0; j < n; j++) {
				if ((i % (n - 1) == 0) || (j % (n - 1) == 0)) printf("*");
				else if (position == j) {
					printf("*");
					position += k;
				}
				else printf(" ");
			}
			position = (position - 1 + k) % k;
			printf("\n");
		}
	}
}

int main() {
	/*
		int hour;
		int minute;
		scanf("%d %d", &hour, &minute);
		minutes_ago(&hour, &minute);
		printf("%d %d", hour, minute);
	*/

	int n, k;
	scanf("%d %d", &n, &k);
	comb_square(n, k);
	
	return 0;
}