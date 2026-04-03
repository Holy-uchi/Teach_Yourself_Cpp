#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

struct Data {
  // 各スレッドでmをlockすることでデータレースを防げる。
  std::mutex m;
  int value = 0;
};

void work(std::shared_ptr<Data> d) {
  int local_value = 0;
  for (int i = 0; i < 10000; i++) {
    local_value++;
  }
  std::lock_guard<std::mutex> lock(d->m);
  d->value += local_value;
}

int main() {
  auto sp = std::make_shared<Data>();

  std::thread t1(work, sp);
  std::thread t2(work, sp);
  std::thread t3(work, sp);

  t1.join();
  t2.join();
  t3.join();

  std::cout << sp->value << '\n';
}