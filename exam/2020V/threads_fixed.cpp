#include <thread>
#include <vector>
#include <iostream>
#include <mutex>
#include <map>

using namespace std;

auto f = [](long x) -> long { return x*x; };

int main() {
    map<long, long> results;
    vector<thread> threads;
    mutex result_mutex;
    for(long x = 43; x < 47; ++x) {
        threads.emplace_back([&results, &result_mutex, x] {
            auto result = f(x); // Time-consuming task
            {
                // Lock the mutation with a mutex
                // (however: unique_lock or lock_guard?)
                lock_guard<mutex> lock(result_mutex);
                results.emplace(x, result);
                // Lock is released when going out of scope
            }
        });
    }
    for(auto &thread : threads)
        thread.join();
    for(auto &[x, y] : results)
        cout << "f(" << x << ") = " << y << endl;
}
