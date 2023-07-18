class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node *prev;
        node *next;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };
    
    // Head and tail dummy nodes for the doubly linked list
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    
    int cap = 0; // Capacity of the LRUCache.
    unordered_map<int, node*> ma; // Unordered map to store key-node pairs
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    // Function to delete a node from the doubly linked list
    void deletenode(node *curr) {
        node *prevnode = curr->prev;
        node *nextnode = curr->next;
        
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }
    
    // Function to add a node to the beginning of the doubly linked list
    void addnode(node *curr) {
        node *temp = head->next;
        curr->next = temp;
        curr->prev = head;
        
        temp->prev = curr;
        head->next = curr;
    }
    
    int get(int key) {
        if (ma.find(key) != ma.end()) {
            node *curr = ma[key];
            
            int ans = curr->val;
            
            // Move the accessed node to the beginning of the list (most recently used)
            deletenode(curr);
            addnode(curr);
            
            ma[key] = head->next; // Update the position of the node in the map
            
            return ans;
        }
        
        return -1; // Key not found, return -1
    }
    
    void put(int key, int value) {
        if (ma.find(key) != ma.end()) {
            // Key already exists update the value and move the node to the beginning (most recently used)
            node *curr = ma[key];
            deletenode(curr);
            ma.erase(key);
        }
        
        if (ma.size() == cap) {
            // Cache is full evict the least recently used node (before the tail) from both the list and map
            ma.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        // Add a new node with the key-value pair to the beginning of the list
        addnode(new node(key, value));
        ma[key] = head->next; // Update the map with the key-node pair of the new node
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */