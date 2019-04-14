#include <cstdio>
#include <queue>

int main() {
	using namespace std;
	int n, b, h;
	priority_queue<int> que;
	scanf("%d%d", &n, &b);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &h);
		que.push(h);
	}
	while (b > 0) {
        if ((b -= que.top()) <= 0) {
            printf("%d\n", n - que.size() + 1);
            break;
        }
        que.pop();
    }
    return 0;
}
