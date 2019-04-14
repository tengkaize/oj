#include <cstdio>
#ifndef TKZ_COLLECTION_TREAP
#define TKZ_COLLECTION_TREAP

#include <random>
#ifndef TKZ_BASE
#define TKZ_BASE

#include <cstddef>
#include <cstdint>

namespace tkz {

using int8_t = ::std::int8_t;
using int16_t = ::std::int16_t;
using int32_t = ::std::int32_t;
using int64_t = ::std::int64_t;

using uint8_t = ::std::uint8_t;
using uint16_t = ::std::uint16_t;
using uint32_t = ::std::uint32_t;
using uint64_t = ::std::uint64_t;

using size_t = ::std::size_t;

using float32_t = float;
using float64_t = double;

}  // namespace tkz

#endif

namespace tkz {
namespace collection {

template <typename T>
class Treap {
   protected:
    struct Node {
        Node* left;
        Node* right;
        T key;
        std::mt19937::result_type priority;
        size_t times;
        size_t size;
    };

    static Node* nil;

    Node* root;
    std::mt19937 randgen;

    inline void updateSize(Node* n) { n->size = n->left->size + n->right->size + n->times; }

    // 右旋
    inline void zig(Node*& n) {
        Node* l = n->left;
        n->left = l->right;
        l->right = n;
        l->size = n->size;
        updateSize(n);
        n = l;
    }

    // 左旋
    inline void zag(Node*& n) {
        Node* r = n->right;
        n->right = r->left;
        r->left = n;
        r->size = n->size;
        updateSize(n);
        n = r;
    }

    void insert(const T& key, Node*& n) {
        if (n == nil)
            n = new Node{nil, nil, key, randgen(), 1, 1};
        else {
            ++n->size;
            if (key < n->key) {
                insert(key, n->left);
                if (n->left->priority < n->priority)
                    zig(n);
            } else if (key > n->key) {
                insert(key, n->right);
                if (n->right->priority < n->priority)
                    zag(n);
            } else {
                ++n->times;
            }
        }
    }

    void erase(const T& key, Node*& n) {
        if (n->key == key) {
            if (n->times > 1)
                --n->times, --n->size;
            else if (n->left == nil || n->right == nil)
                n = (n->left != nil ? n->left : n->right);
            else if (n->left->priority < n->right->priority)
                zig(n), erase(key, n);
            else /*if (n->left->priority >= n->right->priority)*/
                zag(n), erase(key, n);
        } else {
            --n->size;
            if (key < n->key)
                erase(key, n->left);
            else /*if (key > n->key)*/
                erase(key, n->right);
        }
    }

   public:
    const T& prev(const T& key) {
        Node* n = root;
        const T* res = nullptr;
        while (n != nil) {
            if (n->key < key)
                res = &n->key, n = n->right;
            else
                n = n->left;
        }
        return *res;
    }

    const T& next(const T& key) {
        Node* n = root;
        const T* res = nullptr;
        while (n != nil) {
            if (n->key > key)
                res = &n->key, n = n->left;
            else
                n = n->right;
        }
        return *res;
    }

    inline size_t count() const { return root->size; }

    // note: rank must in range[1, count()]
    const T& operator[](size_t rank) const {
        Node* n = root;
        while (n != nil) {
            if (n->left->size < rank && rank <= n->left->size + n->times)
                return n->key;
            if (rank <= n->left->size)
                n = n->left;
            else
                rank -= n->left->size + n->times, n = n->right;
        }
        // note: n is nullptr now!
        return n->key;
    }

    // note: return 0 if not found key
    size_t rankOf(const T& key) const {
        Node* n = root;
        size_t r = 0;
        while (n) {
            if (n->key == key)
                return r + n->left->size + 1;
            else if (n->key > key)
                n = n->left;
            else /*if (n->key < key)*/
                r += n->left->size + n->times, n = n->right;
        }
        return r;
    }

    inline void insert(const T& key) { insert(key, root); }

    inline void erase(const T& key) { erase(key, root); }

    Treap() : root(nil), randgen() {}
};

template <typename T>
typename Treap<T>::Node* Treap<T>::nil = new Node{nullptr, nullptr, {}, 0, 0, 0};

}  // namespace collection
}  // namespace tkz

#endif

template <typename Integral>
Integral readInt() {
    Integral n = 0;
    int c = std::getchar();
    bool neg = false;
    while (!std::isdigit(c) && c != '-')
        c = std::getchar();
    if (c == '-')
        neg = true, c = std::getchar();
    while (std::isdigit(c))
        n = n * 10 + c - '0', c = std::getchar();
    return neg ? -n : n;
}

template <typename Integral>
void writeUInt(Integral n) {
    if (n < 10) {
        std::putchar(n + '0');
        return;
    }
    writeUInt(n / 10);
    std::putchar(n % 10 + '0');
}

template <typename Integral>
void writeIntLn(Integral n) {
    if (n < 0) {
        std::putchar('-');
        n = -n;
    }
    writeUInt(n);
    std::putchar('\n');
}

int main() {
    int n = readInt<int>();
    tkz::collection::Treap<int> treap;
    while (n--) {
        int opt = readInt<int>(), x = readInt<int>();
        switch (opt) {
            case 1: treap.insert(x);                break;
            case 2: treap.erase(x);                 break;
            case 3: writeIntLn(treap.rankOf(x));    break;
            case 4: writeIntLn(treap[x]);           break;
            case 5: writeIntLn(treap.prev(x));      break;
            case 6: writeIntLn(treap.next(x));      break;
            default: break;
        }
    }
    return 0;
}