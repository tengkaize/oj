#include <cstdio>

using namespace std;

int main() {
    int T, N, L, R, X, K;
    scanf("%d%d%d%d%d%d", &T, &N, &L, &R, &X, &K);
    int x, y;
    long long dist = 0;
    int gear = 1;
    int speed = L;
    int hCnt = 0;
    while (T-- && hCnt != K) {
        scanf("%d%d", &x, &y);
        if (x == 0) {
            if (gear++ == N) {
                printf("-1");
                return 0;
            }
            speed = L;
        } else if (x == 1) {
            if (gear-- == 1) {
                printf("-1");
                return 0;
            }
            speed = R;
        }
        if (y == 1) {
            speed += X;
            if (speed > R)
                speed = R;
        }
        if (speed == R)
            ++hCnt;
        else
            hCnt = 0;
        dist += gear * static_cast<long long>(speed);
    }
    printf("%lld\n", dist);
    return 0;
}