#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_LENGTH = 1000000;
char s[MAX_LENGTH + 1];
int p[MAX_LENGTH + 1];

void getFail(const char* str, int* fail, int& slen) {
    slen = strlen(str);
    fail[0] = -1;
    int j = -1;
    for (int i = 0; i < slen - 1; ++i) {
        while (j > -1 && str[j + 1] != str[i + 1])
            j = fail[j];
        if (str[j + 1] == str[i + 1])
            ++j;
        fail[i + 1] = j;
    }
}

int main() {
    int n;
    while (scanf("%s", s) != EOF && s[0] != '.') {
        getFail(s, p, n);
        printf("%d\n", n % (n - p[n - 1] - 1) == 0 ? n / (n - p[n - 1] - 1) : 1);
    }
    return 0;
}
