#include <unordered_map>
#include <list>

class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;
        // Move the accessed node to the front
        order.splice(order.begin(), order, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            // Update value and move to front
            it->second->second = value;
            order.splice(order.begin(), order, it->second);
        } else {
            if (order.size() == cap) {
                // Remove least recently used
                int old_key = order.back().first;
                order.pop_back();
                cache.erase(old_key);
            }
            order.emplace_front(key, value);
            cache[key] = order.begin();
        }
    }

private:
    int cap;
    std::list<std::pair<int, int>> order; // {key, value}
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;
};

// Example usage:
int main() {
    LRUCache lru(2);
    lru.put(1, 1); // cache is {1=1}
    lru.put(2, 2); // cache is {1=1, 2=2}
    int val1 = lru.get(1); // returns 1
    lru.put(3, 3); // evicts key 2, cache is {1=1, 3=3}
    int val2 = lru.get(2); // returns -1 (not found)
    lru.put(4, 4); // evicts key 1, cache is {3=3, 4=4}
    int val3 = lru.get(1); // returns -1 (not found)
    int val4 = lru.get(3); // returns 3
    int val5 = lru.get(4); // returns 4
    return 0;
}
