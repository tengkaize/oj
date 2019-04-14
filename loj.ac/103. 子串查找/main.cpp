#include <cstdio>
#include <cstring>

using namespace std;

const size_t po = 257, maxlen = 1e6;

char A[maxlen + 1], B[maxlen + 1];
size_t hashA[maxlen + 1];

int main() {
    scanf("%s%s", A, B);
    size_t lenA = strlen(A), lenB = strlen(B);
    
    hashA[0] = 0;
    for (size_t i = 0; i < lenA; ++i) {
        hashA[i + 1] = hashA[i] * po + A[i];
    }
    
    size_t hashB = 0, power = 1;
    for (size_t i = 0; i < lenB; ++i) {
        hashB = (hashB * po + B[i]);
        power *= po;
    }
    
    size_t ans = 0;
    for (size_t i = 0; i <= lenA - lenB; ++i) {
        if (hashB == hashA[i + lenB] - hashA[i] * power) {
            ++ans;
        }
    }
    printf("%d\n", int(ans));
    
    return 0;
}
