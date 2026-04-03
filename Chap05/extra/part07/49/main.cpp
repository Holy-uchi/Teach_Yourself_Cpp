#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

struct Data {
    mutable std::mutex m;
    int value = 0;

    int get() const {
        std::lock_guard<std::mutex> lock(m);
        return value;
    }

    void add(int x) {
        std::lock_guard<std::mutex> lock(m);
        value += x;
    }
};

void reader(std::weak_ptr<Data> wp) {
    if (auto sp = wp.lock()) {
        std::cout << "read: " << sp->get() << '\n';
    } else {
        std::cout << "expired\n";
    }
}

void writer(std::weak_ptr<Data> wp) {
    if (auto sp = wp.lock()) {
        sp->add(1);
    } else {
        std::cout << "expired\n";
    }
}

int main() {
    auto owner = std::make_shared<Data>();

    std::thread t1(reader, std::weak_ptr<Data>(owner));
    std::thread t2(writer, std::weak_ptr<Data>(owner));
    std::thread t3(reader, std::weak_ptr<Data>(owner));

    t1.join();
    t2.join();
    t3.join();

    owner.reset();  // ここで最後の所有者が消えれば破棄される
}


//設計方針

// オブジェクト本体は shared_ptr で所有する
// 各スレッドには基本 weak_ptr を渡し、使う直前に lock() する
// lock() に成功した間だけ一時的に shared_ptr を持ち、安全にアクセスする
// オブジェクト内部の共有状態は mutex で保護する
// 更新処理だけでなく、更新と競合しうる読み取り処理も同じ mutex で保護する
// mutex はグローバルより、可能ならオブジェクト内部に持たせる

// 理由

// shared_ptr は所有権と寿命管理を担当する
// weak_ptr は寿命が不確実な相手への一時アクセスを安全にする
// mutex はデータレースを防ぐ
// これにより、所有権が明確で、ダングリングもなく、競合も防げる
