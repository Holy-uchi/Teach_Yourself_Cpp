#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
class StrBuf {
  char* cstr;
  std::size_t len;
  std::size_t cap;

  void reserve(std::size_t min_size) {
    if (this->cap >= min_size) {
      return;
    }
    std::size_t ncap = this->cap;
    while (ncap < min_size) {
      ncap *= 2;
    }

    char* ncstr = new char[ncap];
    std::copy(this->cstr, this->cstr + this->len + 1, ncstr);

    delete[] this->cstr;
    this->cstr = ncstr;
    this->cap = ncap;
  }

public:
  StrBuf() : cstr(new char[8]), len(0), cap(8) {
    std::cout << "デフォルトコンストラクタ" << std::endl;
    cstr[0] = '\0';
  }
  explicit StrBuf(std::size_t cap) : cstr(new char[cap]), len(0), cap(cap) {
    std::cout << "cap指定コンストラクタ" << std::endl;
    cstr[0] = '\0';
  }

  StrBuf(const StrBuf& other)
      : cstr(new char[other.cap]), len(other.len), cap(other.cap) {
    std::cout << "コピーコンストラクタ" << std::endl;
    std::strcpy(this->cstr, other.cstr);
  }

  StrBuf(StrBuf&& other)
      : cstr(new char[other.cap]), len(other.len), cap(other.cap) {
    std::cout << "ムーブコンストラクタ" << std::endl;
    this->cstr = other.cstr;
    other.cstr = nullptr;
    other.len = 0;
    other.cap = 0;
  }

  ~StrBuf() {
    std::cout << "デストラクタ" << std::endl;
    cap = 0;
    len = 0;
    delete[] cstr;
  }

  void append(const char* cstr) {
    std::size_t add_len = std::strlen(cstr);
    this->reserve(this->len + add_len + 1);
    std::strcpy(&this->cstr[this->len], cstr);
    this->len += add_len;
  }

  const char* get_string() const { return cstr; }
  const std::size_t& get_len() const { return len; }
  const std::size_t& get_cap() const { return cap; }
  void dump() const {
    if (this->cstr != nullptr) {
      std::cout << "文字列: " << this->get_string() << std::endl;
    } else {
      std::cout << "文字列は破棄されています。" << std::endl;
    }
    std::cout << "長さ: " << this->get_len() << std::endl;
    std::cout << "容量: " << this->get_cap() << std::endl;
  }
};

int main() {
  StrBuf str{};
  str.dump();
  str.append("hogehogehogehogehoge");
  str.dump();

  {

    StrBuf str2 = str;
    std::cout << "str2" << std::endl;
    str2.dump();
  }
  std::cout << "str" << std::endl;
  str.dump();

  {
    StrBuf str3 = std::move(str);
    str3.dump();
  }

  std::cout << "str" << std::endl;
  str.dump();
};
