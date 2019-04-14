#include <cstdint>
#include <cstdio>

inline std::int64_t readInt() {
    std::int64_t n = 0;
    bool neg = false;
    char ch = std::getchar();
    while ((ch < '0' || ch > '9') && ch != '-')
        ch = std::getchar();
    if (ch == '-')
        neg = true, ch = std::getchar();
    while ('0' <= ch && ch <= '9')
        n = n * 10 + ch - '0', ch = std::getchar();
    return neg ? -n : n;
}

void writeUInt(std::int64_t n) {
    if (n < 10) {
        std::putchar(n + '0');
        return;
    }
    writeUInt(n / 10);
    std::putchar(n % 10 + '0');
}

inline void writeIntLn(std::int64_t n) {
    if (n < 0)
        n = -n;
    writeUInt(n);
    std::putchar('\n');
}

constexpr std::size_t N = 100000 + 5;
std::int64_t n, m;

using nodeIndex_t = std::size_t;

std::int64_t sum[N * 4];
std::int64_t add[N * 4];

inline void update(nodeIndex_t k) {
    sum[k] = sum[k << 1] + sum[k << 1 | 1];
}

void build(nodeIndex_t k = 1, std::size_t l = 1, std::size_t r = n) {
    if (l == r) {
        sum[k] = readInt();
        return;
    }
    std::size_t m = (l + r) >> 1;
    build(k << 1, l, m);
    build(k << 1 | 1, m + 1, r);
    update(k);
}

void tagAdd(nodeIndex_t k, std::size_t l, std::size_t r, const std::int64_t& v) {
    add[k] += v;
    sum[k] += v * (r - l + 1);
}

void pushDown(nodeIndex_t k, std::size_t l, std::size_t r, std::size_t m) {
    if (add[k] == 0)
        return;
    tagAdd(k << 1, l, m, add[k]);
    tagAdd(k << 1 | 1, m + 1, r, add[k]);
    add[k] = 0;
}

const std::int64_t query(std::size_t x, std::size_t y, nodeIndex_t k = 1, std::size_t l = 1, std::size_t r = n) {
    if (l >= x && r <= y)
        return sum[k];
    std::size_t m = (l + r) >> 1;
    pushDown(k, l, r, m);
    std::int64_t res = 0LL + (x <= m ? query(x, y, k << 1, l, m) : 0) + (m < y ? query(x, y, k << 1 | 1, m + 1, r) : 0);
    return res;
}

void rangeAdd(std::size_t x,
              std::size_t y,
              const std::int64_t& v,
              nodeIndex_t k = 1,
              std::size_t l = 1,
              std::size_t r = n) {
    if (l >= x && r <= y)
        return tagAdd(k, l, r, v);
    std::size_t m = (l + r) >> 1;
    pushDown(k, l, r, m);
    if (x <= m)
        rangeAdd(x, y, v, k << 1, l, m);
    if (m < y)
        rangeAdd(x, y, v, k << 1 | 1, m + 1, r);
    update(k);
}

int main() {
    n = readInt();
    m = readInt();
    build();
    std::int64_t op, x, y, k;
    while (m--) {
        op = readInt();
        x = readInt();
        y = readInt();
        if (op == 1) {
            k = readInt();
            rangeAdd(x, y, k);
        } else {
            writeIntLn(query(x, y));
        }
    }
    return 0;
}
