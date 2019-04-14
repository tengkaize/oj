#include <cstdio>

namespace {

constexpr int prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

long long n, s = 0, pCmax = 0;

void findAntiprime(int pI = 1, long long anti = 1, int bI = 31, long long pC = 1) {
    if (pI == 11)
        return;
    long long k = 1;
    for (int i = 1; i <= bI; ++i) {
        k *= prime[pI];
        if (anti * k > n)
            return;
        if (pC * (i + 1) == pCmax && anti * k < s)
            s = anti * k;
        if (pC * (i + 1) > pCmax) {
            s = anti * k;
            pCmax = pC * (i + 1);
        }
        findAntiprime(pI + 1, anti * k, i, pC * (i + 1));
    }
}

}  // namespace

int main() {
    using namespace std;
    scanf("%lld", &n);
    findAntiprime();
    printf("%lld\n", s);
    return 0;
}
