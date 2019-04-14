#include <iostream>
#include <map>
#include <string>

using namespace std;

const int NP = 10;

int np;
map<string, int> pm;
string pn[NP];

int main() {
	cin >> np;
	for (int i = 0; i < np; ++i) {
		cin >> pn[i];
	}
	for (int i = 0; i < np; ++i) {
		string nown;
		int money, fnum;
		cin >> nown >> money >> fnum;
		if (fnum == 0) continue;
		int spendm = money / fnum;
		pm[nown] -= spendm * fnum;
		string fname;
		for (int i = 0; i < fnum; ++i) {
			cin >> fname;
			pm[fname] += spendm;
		}
	}
	for (int i = 0; i < np; ++i) {
		cout << pn[i] << ' ' << pm[pn[i]] << '\n';
	}
	return 0;
}
