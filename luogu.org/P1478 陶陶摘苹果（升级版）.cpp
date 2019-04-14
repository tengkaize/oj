#include <iostream>
// istream_iterator 与 back_inserter 要用的头文件
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

// 定义一个苹果结构体
struct Apple {
	// 苹果的高度
	int h;
    // 需要的体力
	int y;
};

// 为了使用 istream_iterator 定义读入运算符
istream& operator>>(istream& in, Apple& a) {
	in >> a.h >> a.y;
	return in;
}

// 面函数
int main() {
	// 定义并输入 n s a b, h 为总高度
	// 虽然 n 之后就没用了 
	int n, s, a, b, h;
	cin >> n >> s >> a >> b;
	h = a + b;
	// 苹果数组 
	vector<Apple> apples;
	// 将 
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
