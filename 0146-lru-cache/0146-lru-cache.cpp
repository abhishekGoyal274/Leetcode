#include <unordered_map>
#include <iostream>

using namespace std;

class linked_list {
public:
    int value, key;
    linked_list *next, *prev;
    linked_list() : next(nullptr), prev(nullptr), value(0), key(0) {}
    linked_list(int key, int value) : next(nullptr), prev(nullptr), key(key), value(value) {}
};

class LRUCache {
private:
    int capacity;
    // Sentinel dummy nodes to eliminate boundary edge-cases
    linked_list *head;
    linked_list *tail;
    unordered_map<int, linked_list*> cache;

    // Helper: Removes an existing node from the doubly linked list
    void remove(linked_list* node) {
        linked_list* prev_node = node->prev;
        linked_list* next_node = node->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }

    // Helper: Inserts a node right before the dummy tail (Most Recently Used position)
    void insert_at_tail(linked_list* node) {
        linked_list* prev_to_tail = tail->prev;
        
        prev_to_tail->next = node;
        node->prev = prev_to_tail;
        node->next = tail;
        tail->prev = node;
    }

    // Helper: Moves an existing node to the tail (updates recency)
    void make_recently_used(linked_list* node) {
        remove(node);
        insert_at_tail(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        
        // Initialize dummy head and tail structures
        head = new linked_list(-1, -1);
        tail = new linked_list(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    ~LRUCache() {
        // Clean up remaining allocated memory
        linked_list* current = head;
        while (current != nullptr) {
            linked_list* next = current->next;
            delete current;
            current = next;
        }
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }

        linked_list* node = it->second;
        make_recently_used(node);
        return node->value;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        
        if (it != cache.end()) {
            // Key exists: Update value and refresh recency status
            linked_list* node = it->second;
            node->value = value;
            make_recently_used(node);
            return;
        } 

        if (cache.size() == capacity) {
            // Cache is full: Evict the Least Recently Used (LRU) node, located after dummy head
            linked_list* lru_node = head->next;
            cache.erase(lru_node->key);
            remove(lru_node);
            delete lru_node; // Free memory allocation
        }

        // Insert new element
        linked_list* new_node = new linked_list(key, value);
        cache[key] = new_node;
        insert_at_tail(new_node);
    }
};