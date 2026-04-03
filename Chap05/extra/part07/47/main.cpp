#include <iostream>
#include <memory>
#include <thread>

void worker(std::weak_ptr<int> p) {
  if (auto sp = p.lock()) {
    std::cout << "lock acquired: " << *sp << '\n';
  } else {
    std::cout << "pointer expired\n"; 
  }
}

int main() {
  std::thread t1;
  std::thread t2;
  {
    auto sp = std::make_shared<int>(42);
    std::weak_ptr<int> wp = sp;
    t1 = std::thread(worker, wp);

    // t_innerの寿命 > spの寿命が保証される
    t1.join();

    sp.reset();
    t2 = std::thread(worker, wp);
  }

  t2.join();
}