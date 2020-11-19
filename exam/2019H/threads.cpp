#include <thread>
#include <iostream>

int main() {
    std::thread *a_thread;
    {
      int a = 2;
      // don't allocate an int with new
      // also, this is shared between all threads
      // - potentially undefined behaviour if modified
      int *b = new int(2);
      // here, we allocate a thread on the heap with new
      // - it is NOT freed when we exit the block.
      // solution? don't use new.
      a_thread = new std::thread([&a, b] {
        std::cout << (a + *b) << std::endl;
      });
    }
    // if this was a normal reference, it'd have been destroyed when going out of scope
    a_thread->join();
}
