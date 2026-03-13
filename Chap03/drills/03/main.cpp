#include <iostream>
#include <string>

class Book {
  std::string title;
  std::string writer;
  int price;

public:
  Book(std::string title, std::string writer, int price);
  Book(const Book& other);
  void describe() const;
};

Book::Book(std::string title, std::string writer, int price)
    : title(title), writer(writer), price(price) {
  std::cout << "コンストラクタ呼び出し" << std::endl;
}

Book::Book(const Book& other)
    : title(other.title), writer(other.writer), price(other.price) {
  std::cout << "コピーコンストラクタ呼び出し" << std::endl;
}

void Book::describe() const {
  std::cout << "タイトル: " << this->title << ", 著者: " << this->writer
            << ", 値段: " << this->price << std::endl;
}

int main() {
  Book bk{"独習C++", "高橋航平", 3000};
  bk.describe();
  Book bk2 = bk;
  bk2.describe();
}
