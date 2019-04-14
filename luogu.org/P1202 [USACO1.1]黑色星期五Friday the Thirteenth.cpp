#include <cstdio>

using namespace std;

int ans[7], n;

int days[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

inline bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
	scanf("%d", &n);
	int year = 1900, month = 1, day = 1;
	int wday = 0;
	while (!(year == 1900 + n && month == 1 && day == 1)) {
		++day;
		++wday;
		wday %= 7;
		if (day > days[isLeapYear(year)][month]) {
			day = 1;
			++month;
		}
		if (month > 12) {
			month = 1;
			++year;
		}
		if (day == 13) {
			++ans[wday];
		}
	}
	printf("%d %d %d %d %d %d %d\n", ans[5], ans[6], ans[0], ans[1], ans[2], ans[3], ans[4]);
	return 0;
}
