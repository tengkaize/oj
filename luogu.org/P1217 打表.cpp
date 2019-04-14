#include <cstdio>

using namespace std;

bool isPrime(int x) {
//	if (x == 0 || x == 1) return false;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) return false;
	}
	return true;
}

bool isPalindromes(int x) {
	int y = x, num = 0;
    while (y != 0) {
        num = num * 10 + y % 10;
        y /= 10;
    } 
    if (num == x) return true;
    else return false;
}

int main() {
	FILE* fout = fopen("P1217.txt", "w");
	printf("START\n");
	for (int i = 5; i <= 100000000; ++i)
		if (isPalindromes(i) && isPrime(i))
			fprintf(fout, "%d,\n", i);
	printf("END.\n");
	return 0;
}
