#include <thread>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

auto f = [](long x) -> long { return x*x; };

int main() {
    map<long, long> results;
    vector<thread> threads;
    for(long x = 43; x < 47; ++x) {
      threads.emplace_back([&results, x] {
        auto result = f(x); // Time-consuming task
        results.emplace(x, result); // Here's the problem!
      });
    }
    for(auto &thread : threads)
      thread.join();
    for(auto &pair : results)
      cout << "f(" << pair.first << ") = " << pair.second << endl;
}
