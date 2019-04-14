#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	
	int n;
	scanf("%d", &n);
	
	int minprice = 0x7FFFFFFF;
	int num, price;
	for (int i = 1; i <= 3; ++i) {
		scanf("%d%d", &num, &price);
		minprice = min(minprice, (n + num - 1) / num * price);
	}
	
	printf("%d\n", minprice);
	
	return 0;
}
