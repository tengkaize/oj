#include <set>
#include <iostream>
#include <iterator>

int main() {
    int _;
    std::cin >> _;
    std::set<int> s{std::istream_iterator<int>(std::cin), std::istream_iterator<int>()};
    std::cout << s.size() << '\n';
    std::copy(s.begin(), s.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}