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
    ll a, b, m;
    scanf("%lld%lld%lld%lld", &a, &b, &m);
    printf("%lld", powermod(a, b, m));
    return 0;
}
