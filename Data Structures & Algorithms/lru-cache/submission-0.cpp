class Node {
public:
    int key, val;
    Node* prev;
    Node* next;
    
    Node( int _key, int _val) {
        key = _key;
        val = _val;

        prev = nullptr;
        next = nullptr;
    }
};



class LRUCache {
private:
    unordered_map<int, Node *> cache;
    int capacity = 0;
    Node * left;
    Node * right;
    

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
        
    }
    //remove node from list
    void remove(Node * node){
        Node * prev = node->prev;
        Node * next = node->next;
        prev->next = next;
        next->prev = prev;

    }
    //insert at right
    void insert(Node * node){
        Node * prev = right->prev;
        Node * next = right;
        prev->next = next->prev = node;
        node->next = next;
        node->prev = prev;
    }
    
    int get(int key) {
        if (cache.contains(key)){
            //need to remove then insert at right
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)){
            Node * node = cache[key];
            node->val = value;
            remove(node);
            insert(node);
            return;      
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);

        if ((int)cache.size() > capacity){
            Node * lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;

        }

        
    }
};
