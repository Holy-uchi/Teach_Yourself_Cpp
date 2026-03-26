#include <algorithm>
#include <iostream>
#include <vector>

struct Person {
  std::string name;
  int age;
};

int main() {

  std::vector<Person> people = {
      {"bob", 20}, {"alice", 18}, {"carol", 20}, {"dave", 18}, {"eve", 20}};

  std::sort(people.begin(), people.end(), [](auto a, auto b) {
    if (a.age != b.age) {
      return a.age < b.age;
    } else {
      return a.name < b.name;
    }
  });

  for (auto person : people) {
    std::cout << person.name << " : " << person.age << "\n";
  }
}
