#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Milking {
	int start, end;
};

int main() {
	vector<Milking> ms;
	int n;
	scanf("%d", &n);
	int s, e;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &s, &e);
		ms.push_back(Milking{s, e});
	}
	sort(ms.begin(), ms.end(), [](const Milking& m1, const Milking& m2) {
		return m1.start < m2.start;
	});
	int mkt = ms[0].end - ms[0].start, maxmkt = mkt, maxnmkt = 0;
	for (int i = 1; i < n; ++i) {
		if (ms[i].start < ms[i - 1].end) {
			mkt += ms[i].end - ms[i - 1].end;
		}
		else {
			maxmkt = max(maxmkt, mkt);
			maxnmkt = max(maxnmkt, ms[i].start - ms[i - 1].end);
		}
	}
	printf("%d %d\n", maxmkt, maxnmkt);
	
	return 0;
}
