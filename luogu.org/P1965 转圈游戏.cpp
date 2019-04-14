#include <cstdio>

using namespace std;

typedef long long ll;

inline ll powermod(ll b, ll p, ll m) {
    ll r = 1;
    while (p) {
        if (p & 1) {
            r = r * b % m;
        }
        b = b * b % m;
        p >>= 1;
    }
    return r % m;
}

int main() {
    ll n, m, k, x;
    scanf("%lld%lld%lld%lld", &n, &m, &k, &x);
    printf("%lld", (x + m * powermod(10, k, n) % n) % n);
    return 0;
}