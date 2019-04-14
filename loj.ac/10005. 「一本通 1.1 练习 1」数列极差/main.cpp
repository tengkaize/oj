#include <queue>
#include <cstdio>

using namespace std;

priority_queue<size_t, vector<size_t>, less<size_t>> mini;
priority_queue<size_t, vector<size_t>, greater<size_t>> maxi;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int z;
        scanf("%d", &z);
        maxi.push(z); mini.push(z);
    }
    while (maxi.size() != 1) {
        int maxa = maxi.top(); maxi.pop();
        int maxb = maxi.top(); maxi.pop();
        int mina = mini.top(); mini.pop();
        int minb = mini.top(); mini.pop();
        maxi.push(maxa * maxb + 1);
        mini.push(mina * minb + 1);
    }
    printf("%llu\n", maxi.top() - mini.top());
    return 0;
}
