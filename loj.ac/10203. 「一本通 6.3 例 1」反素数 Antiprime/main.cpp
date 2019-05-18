#include <cstdio>
#include <algorithm>

using namespace std;

int p[51] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229};

long long n;
int maxG = 0;
long long maxPri = 0;

void gPri(long long acc, int i, int amax, int g) {
	for (int ai = 1; ai <= amax; ++ai) {
		if (acc * p[i] > n) {
			if (g > maxG) { 
				maxG = g;
				maxPri = acc;
			} else if (g == maxG) maxPri = min(maxPri, acc);
			return;
		}
		gPri(acc *= p[i], i + 1, ai, g * (ai + 1));
	}
}

int main() {
#if !defined(ONLINE_JUDGE)
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	
	scanf("%lld", &n);
	gPri(1, 1, 31, 1);
	printf("%lld", maxPri);

#if !defined(ONLINE_JUDGE)
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}

