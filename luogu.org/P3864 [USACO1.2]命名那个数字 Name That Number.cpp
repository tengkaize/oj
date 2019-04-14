#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

map<long long, set<string> > namemap;

long long nameToNum(const string& s) {
	static int ctoi['Z' - 'A' + 1] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};
	long long res = 0;
	for (string::const_iterator it = s.begin(); it != s.end(); ++it) {
		res *= 10;
		res += ctoi[*it - 'A'];
	}
	return res;
}

int main() {
	long long n;
	cin >> n;
	string s;
	for (int i = 0; i < 4617; ++i) {
		cin >> s;
		namemap[nameToNum(s)].insert(s);
	}
	const set<string>& resset = namemap[n];
	if (resset.empty()) {
		cout << "NONE" << '\n';
	}
	else {
		for (set<string>::const_iterator it = resset.begin(); it != resset.end(); ++it) {
			cout << *it << '\n';
		}
	}
	return 0;
}
