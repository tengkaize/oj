#include <cstdio>
#include <cstring>

using namespace std;

long long l, r;
int T;

int checkVaild(const char* num) {
    bool neg = *num == '-' ? (++num, true) : false;
    bool st0 = *num == '0' ? (++num, true) : false;
    if (neg && *num == '\0')
        return 1;
    if (neg && st0)
        return 1;
    if (st0 && *num == '0')
        return 1;
    long long v = 0;
    while (*num != '\0') {
        if (*num < '0' || '9' < *num)
            return 1;
        v = v * 10 + *num++ - '0';
    }
    if (neg)
        v = -v;
    if (strlen(num) > 18)
        return 2;
    return l <= v && v <= r ? 0 : 2;
}

char buf[131072];

int main() {
    scanf("%lld%lld%d", &l, &r, &T);
    while (T--) {
        scanf("%s", buf);
        printf("%d\n", checkVaild(buf));
    }
    return 0;
}