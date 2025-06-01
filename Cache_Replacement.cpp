#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>

enum Policy { LRU, FIFO, RANDOM };

class Cache {
    int capacity;
    Policy policy;
    std::list<int> lruList;
    std::queue<int> fifoQueue;
    std::unordered_map<int, int> data;
    std::vector<int> keys;
public:
    Cache(int cap, Policy p) : capacity(cap), policy(p) {
        std::srand(std::time(0));
    }

    void put(int key, int value) {
        if (data.find(key) != data.end()) {

            data[key] = value;
            if (policy == LRU) {
                lruList.remove(key);
                lruList.push_front(key);
            }
            return;
        }

        if (data.size() >= capacity) {
            int evictKey;
            if (policy == LRU) {
                evictKey = lruList.back();
                lruList.pop_back();
            } else if (policy == FIFO) {
                evictKey = fifoQueue.front();
                fifoQueue.pop();
            } else if (policy == RANDOM) {
                int idx = rand() % keys.size();
                evictKey = keys[idx];
                keys.erase(keys.begin() + idx);
            }
            data.erase(evictKey);
        }


        data[key] = value;
        if (policy == LRU) lruList.push_front(key);
        if (policy == FIFO) fifoQueue.push(key);
        if (policy == RANDOM) keys.push_back(key);
    }

    int get(int key) {
        if (data.find(key) == data.end()) return -1;
        if (policy == LRU) {
            lruList.remove(key);
            lruList.push_front(key);
        }
        return data[key];
    }

    void display() {
        std::cout << "Cache content: ";
        for (const auto& [k, v] : data) std::cout << k << ":" << v << " ";
        std::cout << "\n";
    }
};

int main() {

    Cache cache(3, LRU);

    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);
    cache.display();

    cache.get(2);
    cache.put(4, 400);
    cache.display();

    cache.put(5, 500);
    cache.display();

    return 0;
}
