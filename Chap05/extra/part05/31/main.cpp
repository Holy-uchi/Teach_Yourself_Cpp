#include "widget.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Widget::Impl {
  std::string name;
  std::vector<int> data;
  
  Impl(std::string n, std::vector<int> d)
  : name(std::move(n)), data(std::move(d)) {}
};

Widget::Widget() : impl(std::make_unique<Widget::Impl>(Widget::Impl{"name", std::vector<int>(3,1)})) {
  std::cout << "Widget::Widget()\n";
};
Widget::~Widget() = default;

int main() {
  Widget wg;
}