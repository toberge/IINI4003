#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// Running `watch -n.1 ./threads` gives various different orders of {0,1,2,3}^16
// due to threads being executed in semi-random order.
// The orders _do_ have the same length, though!

using namespace std;

template <typename T>
class ThreadSafeVector {
private:
  vector<T> vec;
  mutex vec_mutex;
public:
  void emplace_back(const T value) {
    lock_guard<mutex> lock(vec_mutex);
    vec.emplace_back(value);
  }

  void for_each(function<void(T)> operation) {
    lock_guard<mutex> lock(vec_mutex);
    for (auto &elem : vec)
      operation(elem);
  }
};

int main() {
  ThreadSafeVector<int> safe_vec;
  vector<thread> threads;
  for (int thread_id = 0; thread_id < 4; ++thread_id) {
    threads.emplace_back([thread_id, &safe_vec] {
      safe_vec.emplace_back(thread_id);
    });
  }
  for (auto &thread : threads)
    thread.join();
  // this result string was not protected!
  string result;
  mutex result_mutex;
  threads.clear();
  for (int thread_id = 0; thread_id < 4; ++thread_id) {
    threads.emplace_back([&result, &result_mutex, &safe_vec] {
      safe_vec.for_each([&result, &result_mutex](int e) {
        lock_guard<mutex> lock(result_mutex);
        result += to_string(e);
      });
    });
  }
  for (auto &thread : threads)
    thread.join();
  cout << result << endl;
}

// vim:softtabstop=2:shiftwidth=2
