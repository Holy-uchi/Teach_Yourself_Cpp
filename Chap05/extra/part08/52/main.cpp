#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> balance{100};

void withdraw(int amount) {

  bool ok = true;
  do {
    auto current_balance = balance.load();
    if (current_balance >= amount) {
      ok = balance.compare_exchange_strong(current_balance, current_balance - amount);
      if (ok) {
        std::cout << "subtracted: " << amount << '\n';
      }
    } else {
      std::cout << "not enough balance. current: " << current_balance << ", amount: " << amount << '\n';
    }
  } while(!ok);
}

int main() {
  std::thread t1(withdraw, 30);
  std::thread t2(withdraw, 50);
  std::thread t3(withdraw, 70);
  std::thread t4(withdraw, 70);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
}