#include <cstdio>

using namespace std;

typedef long long ll;

inline ll powermod(ll b, ll p) {
    ll r = 1;
    while (p) {
        if (p & 1) {
            r *= b;
        }
        b *= b;
        p >>= 1;
    }
    return r;
}

int main() {
    ll x, n;
    scanf("%lld%lld", &x, &n);
    printf("%lld", powermod(x + 1, n));
    return 0;
}