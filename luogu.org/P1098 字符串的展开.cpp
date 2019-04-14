#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

int p1, p2, p3;
char str[105];

void putcharn(char ch) {
	for (int j = 1; j <= p2; ++j) {
		switch(p1) {
			case 1:
				putchar(tolower(ch));
				break;
			case 2:
				putchar(toupper(ch));
				break;
			case 3:
				putchar('*');
				break;
		}
	}
}

int main() {
	scanf("%d%d%d%s", &p1, &p2, &p3, str);
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
		if (str[i] == '-' && i != 0 && i != len - 1 && ((isalpha(str[i - 1]) && isalpha(str[i + 1])) || (isdigit(str[i - 1]) && isdigit(str[i + 1]))) && str[i - 1] < str[i + 1])
			if (p3 == 1) for (char ch = str[i - 1] + 1; ch < str[i + 1]; ++ch) putcharn(ch);
			else         for (char ch = str[i + 1] - 1; ch > str[i - 1]; --ch) putcharn(ch);
		else putchar(str[i]);
	return 0;
}
