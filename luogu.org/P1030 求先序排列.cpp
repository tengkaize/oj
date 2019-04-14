#include <string>
#include <iostream>

using namespace std;

string pre(const string& in, const string& post) {
	if (in.size() < 1) return "";
	char ch = post[post.length() - 1];
	string::size_type p = in.find(ch);
	return ch + pre(in.substr(0, p), post.substr(0, p)) + pre(in.substr(p + 1), post.substr(p, in.length() - p - 1));
}

int main() {
	string in, post;
	cin >> in >> post;
	cout << pre(in, post) << endl;
	return 0;
}

