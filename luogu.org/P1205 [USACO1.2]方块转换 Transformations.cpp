#include <cstdio>
#include <functional>

using namespace std;

struct Mat {
	static int n;
	char data[11][11];
};
int Mat::n;

function<bool(const Mat&, const Mat&)> transEq[] = {
	// 0
	nullptr,
	// 1
	[](const Mat& from, const Mat& to) -> bool {
		for (int i = 1; i <= Mat::n; ++i) {
			for (int j = 1; j <= Mat::n; ++j) {
				if (from.data[i][j] != to.data[j][Mat::n - i + 1]) return false;
			}
		}
		return true;
	},
	// 2
	[](const Mat& from, const Mat& to) -> bool {
		for (int i = 1; i <= Mat::n; ++i) {
			for (int j = 1; j <= Mat::n; ++j) {
				if (from.data[i][j] != to.data[Mat::n - i + 1][Mat::n - j + 1]) return false;
			}
		}
		return true;
	},
	// 3
	[](const Mat& from, const Mat& to) -> bool {
		for (int i = 1; i <= Mat::n; ++i) {
			for (int j = 1; j <= Mat::n; ++j) {
				if (from.data[i][j] != to.data[Mat::n - j + 1][i]) return false;
			}
		}
		return true;
	},
	// 4
	[](const Mat& from, const Mat& to) -> bool {
		for (int i = 1; i <= Mat::n; ++i) {
			for (int j = 1; j <= Mat::n; ++j) {
				if (from.data[i][j] != to.data[i][Mat::n - j + 1]) return false;
			}
		}
		return true;
	},
	// 5
	[](const Mat& from, const Mat& to) -> bool {
		Mat temp;
		for (int i = 1; i <= Mat::n; ++i) {
			for (int j = 1; j <= Mat::n; ++j) {
				temp.data[i][j] = from.data[i][Mat::n - j + 1];
			}
		}
		return transEq[1](temp, to) || transEq[2](temp, to) || transEq[3](temp, to);
	},
	// 6
	[](const Mat& from, const Mat& to) -> bool {
		for (int i = 1; i <= Mat::n; ++i) {
			for (int j = 1; j <= Mat::n; ++j) {
				if (from.data[i][j] != to.data[i][j]) return false;
			}
		}
		return true;
	},
	// 7
	[](const Mat& from, const Mat& to) -> bool {
		return true;
	}
};

void getMat(Mat& in) {
	char ch[2];
	for (int i = 1; i <= Mat::n; ++i) {
		for (int j = 1; j <= Mat::n; ++j) {
			scanf("%1s", ch);
			in.data[i][j] = ch[0];
		}
	}
}

int main() {
	scanf("%d", &Mat::n);
	Mat from, to;
	getMat(from);
	getMat(to);
	for (int i = 1; i <= 7; ++i) {
		if (transEq[i](from, to)) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
