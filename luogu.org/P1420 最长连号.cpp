#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a, b = 0;
    int ans = 1;
    int len = 0;
    while (n--) {
        scanf("%d", &a);
        if (a - b == 1) {
            if (++len > ans)
                ans = len;
        } else
            len = 1;
        b = a;
    }
    printf("%d", ans);
    return 0;
}