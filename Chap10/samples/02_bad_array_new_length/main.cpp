#include <iostream>
#include <new>

int main() {
  try {
    int len = 5;
    int* array = new int[len]{0, 1, 2, 3, 4, 5};

    // 何らかの処理
    delete[] array;
  } catch (std::bad_array_new_length& e) {
    std::cout << "動的確保の長さが足りません" << std::endl;
  } catch (std::bad_alloc& e) {
    std::cout << "メモリ割り当てに失敗しました" << std::endl;
  }
}
