#include <thread>
#include <iostream>

int main() {
    std::unique_ptr<std::thread> a_thread;
    {
      int a = 2;
      std::unique_ptr<int> b;
      b = std::make_unique<int>(2);
      // this was wrong...
      a_thread = std::make_unique<std::thread>([&a, b = std::move(b)] {
        std::cout << (a + *b) << std::endl;
      });
    }
    // if this was a normal reference, it'd have been destroyed when going out of scope
    a_thread->join();
}
