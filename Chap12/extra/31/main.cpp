#include <algorithm>
#include <iostream>
#include <vector>

struct Student {
  std::string name;
  int score;
};

int main() {
  std::vector<Student> students = {
      {"alice", 82}, {"bob", 95}, {"carol", 78}, {"dave", 90}};

  std::sort(students.begin(), students.end(),
            [](auto a, auto b) { return a.score < b.score; });

  for (auto st : students) {
    std::cout << st.name << " : " << st.score << "\n";
  }
}
