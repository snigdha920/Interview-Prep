struct LinkedListNode {
    int val;
    LinkedListNode *next, *prev;
    LinkedListNode() {
        next = prev = nullptr;
    }
    LinkedListNode(int value) {
        val = value;
        next = prev = nullptr;
    }
};
class LRUCache {
public:
    int capacity;
    LinkedListNode *head, *tail;
    unordered_map<int, pair<int, LinkedListNode*>>cache;
    int countNodes;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = tail = nullptr;
        countNodes = 0;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        LinkedListNode* temp = cache[key].second;
        if(temp == tail) return cache[key].first;
        if(temp != head) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        } else {
            head = head->next;
        }
        tail->next = temp;
        temp->prev = tail;
        tail = tail->next;
        tail->next = nullptr;
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            cache[key].first = value;
            int x = get(key);
            return;
        }
        if(countNodes >= capacity) {
            LinkedListNode *temp = head;
            int deleteNode = head->val;
            if(head->next == nullptr) {
                tail = nullptr;
                head = nullptr;
            } else {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            cache.erase(deleteNode);
            countNodes--;
        }
        LinkedListNode *node = new LinkedListNode(key);
        if(head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        countNodes++;
        cache.insert({key, {value, node}});
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
