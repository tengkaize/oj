#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Student {
	int id;
	int c, m, e;
	inline int all() const { return c + m + e; }
};

vector<Student> stu;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		Student t;
		t.id = i;
		scanf("%d%d%d", &t.c, &t.m, &t.e);
		stu.push_back(t);
	}
	sort(stu.begin(), stu.end(), [](const Student& s1, const Student& s2) {
		return s1.all() == s2.all() ? s1.c == s2.c ? s1.id < s2.id : s1.c > s2.c : s1.all() > s2.all();
	});
	for_each(stu.begin(), stu.begin() + 5, [](const Student& s) {
		printf("%d %d\n", s.id, s.all());
	});
	return 0;
}
