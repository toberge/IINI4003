#include <thread>
#include <iostream>

int main() {
    std::unique_ptr<std::thread> a_thread;
    {
      int a = 2;
      std::unique_ptr<int> b;
      *b = 2;
      // this is wrong...
      a_thread.reset(new std::thread([&a, &b] {
        std::cout << (a + *b) << std::endl;
      }));
    }
    // if this was a normal reference, it'd have been destroyed when going out of scope
    a_thread->join();
}
