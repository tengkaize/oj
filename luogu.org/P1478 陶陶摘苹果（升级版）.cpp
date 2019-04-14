#include <iostream>
// istream_iterator �� back_inserter Ҫ�õ�ͷ�ļ�
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

// ����һ��ƻ���ṹ��
struct Apple {
	// ƻ���ĸ߶�
	int h;
    // ��Ҫ������
	int y;
};

// Ϊ��ʹ�� istream_iterator ������������
istream& operator>>(istream& in, Apple& a) {
	in >> a.h >> a.y;
	return in;
}

// �溯��
int main() {
	// ���岢���� n s a b, h Ϊ�ܸ߶�
	// ��Ȼ n ֮���û���� 
	int n, s, a, b, h;
	cin >> n >> s >> a >> b;
	h = a + b;
	// ƻ������ 
	vector<Apple> apples;
	// �� 
	copy_if(
		istream_iterator<Apple>(cin),
		istream_iterator<Apple>(),
		back_inserter(apples),
		[h](const Apple& a) { return a.h <= h; }
	);
	sort(
		apples.begin(),
		apples.end(),
		[](const Apple& a1, const Apple& a2) { return a1.y < a2.y; }
	);
	cout << count_if(
		apples.begin(),
		apples.end(),
		[&s](const Apple& a) { return (s -= a.y) >= 0; }
	);
	return 0;
}
