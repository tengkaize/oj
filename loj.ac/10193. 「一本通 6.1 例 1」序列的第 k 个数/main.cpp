#include <cstdio>

using namespace std;

typedef long long ll;

const ll MOD = 200907;

inline ll powermod(ll b, ll p) {
    ll r = 1;
    while (p) {
        if (p & 1) {
            r = r * b % MOD;
        }
        b = b * b % MOD;
        p >>= 1;
    }
    return r % MOD;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        ll a, b, c, k;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &k);
        if (b - a == c - b) {
            printf("%lld\n", (a + (b - a) * (k - 1) % MOD) % MOD);
        }
        else if (b / a == c / b) {
            printf("%lld\n", a * powermod(b / a, k - 1) % MOD);
        }
    }
    return 0;
}