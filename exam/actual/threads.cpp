#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

/// List containing elements that cannot be removed
class ThreadSafeGrowingList {
private:
  mutex vec_mutex; // protects volatile data
  vector<int> vec; // contains data
public:
  /// Thread-safe wrapper for emplace_back
  void add(int i) {
    lock_guard<mutex> lock(vec_mutex); // locks until end-of-scope
    vec.emplace_back(i);
  }

  // Thread-safe iteration
  void for_each(function<void(int)> action) {
    lock_guard<mutex> lock(vec_mutex); // locks until end-of-scope
    for (auto elem: vec)
      action(elem); // perform some action on each element
  }
};

int main() {
  ThreadSafeGrowingList list;
  vector<thread> threads;
  for (int i = 0; i < 10; ++i) {
    threads.emplace_back([&list, i] {
      list.add(i);
    });
  }

  // This thread may be executed at *any* time
  // since the other threads don't *have* to be executed before this point.
  // Therefore, this for_each will print a random number of elements in an arbitrary order.
  list.for_each([](int value) {
    cout << value << endl;
    this_thread::sleep_for(200ms);
  });

  for (auto &thread : threads)
    thread.join();
}

// vim:softtabstop=2:shiftwidth=2
