#include <cstdio>

using namespace std;

typedef long long ll;

constexpr ll MOD = 100003;

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
    ll m, n;
    scanf("%lld%lld", &m, &n);
    printf("%lld", (powermod(m, n, MOD) - m * powermod(m - 1, n - 1, MOD) % MOD + MOD) % MOD);
    return 0;
}