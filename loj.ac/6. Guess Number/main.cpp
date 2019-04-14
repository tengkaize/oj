#include "interaction.h"

int main() {
    int n = get_num();
    std::vector<int> num;
    for (int i = 0; i < num.size(); ++i) {
        num.push_back([i] {
            int l = 0, r = 1000000, m;
            while (l <= r) {
                m = (l + r) >> 1;
                switch (guess(i, m)) {
                    case -1:
                        l = m + 1;
                    case 1:
                        r = m - 1;
                    case 0:
                        return m;
                }
            }
        }());
    }
    submit(num);
    return 0;
}
