#ifndef TKZ_STR
#define TKZ_STR

#include <cstring>
#include <iostream>
#include <cstdlib>

namespace tkz {
    namespace str {
        class String {
        public:
            String():
                len(0),
                data(nullptr)
            { }
            String(const char* str):
                len(std::strlen(str)),
                data(new char[len + 1])
            {
                std::strcpy(data, str);
            }
            String(const String& other):
                String(other.data)
            { }
            String(String&& other):
                len(other.len),
                data(other.data)
            {
                other.len = 0;
                other.data = nullptr;
            }
            
            ~String() {
                delete[] data;
            }

            
            std::size_t length() const { return len; }
            
            char& operator[](std::size_t i) { return data[i]; }
            const char& operator[](std::size_t i) const { return data[i]; }
            
            char* begin() { return data; }
            const char* begin() const { return data; }
            const char* cbegin() const { return data; }
            char* end() { return data + len; }
            const char* end() const { return data + len; }
            const char* cend() const { return data + len; }
           
        private:
            std::size_t len;
            char* data;
        };
        
        String randomCapitalize(String&& s) {
            for (char& ch : s) {
                ch = std::rand() % 2 ? toupper(ch) : tolower(ch);
            }
            return s;
        }
        
        String randomCapitalize(const String& s) {
            return randomCapitalize(String(s));
        }
        
        std::ostream& operator<<(std::ostream& out, const String& s) {
            for (const char& ch : s) {
                out.put(ch);
            }
            return out;
        }
    }
}

#endif

#include <ctime>

int main() {
    std::srand(std::time(0));
    std::cout << tkz::str::randomCapitalize("Hello, World!") << std::endl;
    return 0;
}
