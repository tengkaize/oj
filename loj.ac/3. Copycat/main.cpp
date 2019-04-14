#include <cstdio>

namespace tkz {
    inline constexpr bool isdigit(char c) { return '0' <= c && c <= '9'; }
    inline constexpr bool isgraph(char c) { return '\41' <= c && c <= '\176'; }
}

namespace tkz {
    namespace io {    
        namespace quick {
            constexpr std::size_t BUF_SIZE = 10000000;

            struct InBuf { 
                char* buf;
                char* ptr;

                explicit InBuf(FILE*&& f):
                    buf(new char[BUF_SIZE]),
                    ptr(buf)
                {
                    std::fread(buf, sizeof(char), BUF_SIZE, f);
                    std::fclose(f);
                }
                
                ~InBuf() {
                    delete[] buf;
                }
                
                inline char getchar() { return *ptr++; }
            };

            struct OutBuf {
                char* buf;
                char* ptr;
                FILE* file;

                explicit OutBuf(FILE* f):
                    buf(new char[BUF_SIZE]),
                    ptr(buf),
                    file(f)
                {
                }
                
                ~OutBuf() {
                    flush();
                    std::fclose(file);
                    delete[] buf;
                }
                
                inline void flush() { std::fwrite(buf, sizeof(char), ptr - buf, file); ptr = buf; }
                inline void putchar(char ch) {
                    *ptr++ = ch;
                }
            };
            
            InBuf& operator>>(InBuf& in, unsigned int& v) {
                v = 0;
                while (!isdigit(*in.ptr)) ++in.ptr;
                while (isdigit(*in.ptr)) v = v * 10 + *in.ptr++ - '0';
                return in;
            }

            InBuf& operator>>(InBuf& in, char* s) {
                while (!isgraph(*in.ptr)) ++in.ptr;
                while (isgraph(*in.ptr)) *s++ = *in.ptr++;
                *s = '\0';
                return in;
            }

            InBuf& operator>>(InBuf& in, char& ch) {
                ch = *in.ptr++;
                return in;
            }
            
            OutBuf& operator<<(OutBuf& out, const char* s) {
                while (*s != '\0') out.putchar(*s++);
                return out;
            }
            
            OutBuf& operator<<(OutBuf& out, char ch) {
                out.putchar(ch);
                return out;
            }
        }
    }
}

int main() {
    using namespace tkz::io::quick;
    
    InBuf in(std::fopen("copycat.in", "r"));
    OutBuf out(std::fopen("copycat.out", "w"));
    
    unsigned int T;
    in >> T;
    char num[1002];
    while (T--) {
        in >> num;
        out << num << '\n';
    }
    
    return 0;
}
