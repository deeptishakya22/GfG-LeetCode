//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    int size = 0;
    int capacity = 0;
    struct Node {
        int key;
        int data;
        struct Node* next;
        struct Node* prev;
        Node(int k, int v) {
            data = v;
            key = k;
            next = NULL;
            prev = NULL;
        }
    };
    Node* head = NULL;
    Node* tail = NULL;
    unordered_map<int, Node*> mp;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        capacity = cap;
        size = 0;
        
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        // Check hashtable to key -> node and if doesn't exist return -1;
        if (mp[key] == NULL) {
            return -1;
        }
        if (mp[key]) {
            if (mp[key] != head) {
                swap(head, mp[key]);
            }
            return head->data;
        }
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here 
        // if node exists, change and add it to the end
        //cout<<"Setting "<<key<<" "<<value<<endl;
        if (mp[key]) {
            mp[key]->data = value;
            if (mp[key] != head) {
                swap(head, mp[key]);
            }
            return;
        }
        if (size < capacity) {
            //insert
            Node *node = new Node(key, value);
            size++;
            mp[key] = node;
            if (head==NULL) {
                tail = head = node;
                return;
            }
            node->next = head;
            head->prev = node;
            head = node;
        } else {
            // Remove from the tail
            Node *node = new Node(key, value);
            mp[key] = node;
            if (head==NULL) {
                tail = head = node;
                return;
            }
            node->next = head;
            head->prev = node;
            head = node;
            
            // TBD
            if (tail) {
                mp.erase(tail->key);
                tail->prev->next = NULL;
                tail = tail->prev;
            }
        }
        
    }
    
    void swap(Node* node1, Node* node2) {
        
   
        if (node2 == tail) {
            tail = node2->prev;
        }
        
        if (node2->prev) {
            node2->prev->next = node2->next;
        }
        if (node2->next) {
            node2->next->prev = node2->prev;
        }
        node2->next = node1;
        node2->prev = NULL;
        head->prev = node2;
        head = node2;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends