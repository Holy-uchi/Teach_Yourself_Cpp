#include <future>
#include <iostream>
#include <memory>
#include <thread>
#include <utility>

void increment(std::unique_ptr<int> p, std::promise<std::unique_ptr<int>> result) {
  *p += 1;
  result.set_value(std::move(p));
}

int main() {
  auto p = std::make_unique<int>(0);

  {
    std::promise<std::unique_ptr<int>> promise;
    std::future<std::unique_ptr<int>> f = promise.get_future();
    std::thread t{increment, std::move(p), std::move(promise)};
    t.join();
    p = f.get();
  }

  {
    std::promise<std::unique_ptr<int>> promise;
    std::future<std::unique_ptr<int>> f = promise.get_future();
    std::thread t{increment, std::move(p), std::move(promise)};
    t.join();
    p = f.get();
  }


  std::cout << *p << std::endl;
}