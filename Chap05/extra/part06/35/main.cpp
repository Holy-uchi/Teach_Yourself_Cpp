#include <thread>

void work() {}

int main() {
    std::thread t(work);
    t.join();
    return 0;
}

