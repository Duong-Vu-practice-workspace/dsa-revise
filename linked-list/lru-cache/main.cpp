#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    int sz;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;

    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        sz = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        Node* node = cache[key];
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;
            moveToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            addToHead(newNode);
            cache[key] = newNode;
            sz++;
            if (sz > cap) {
                Node* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                sz--;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    LRUCache* obj = nullptr;
    vector<string> operations(n);
    vector<vector<int>> args(n);

    for (int i = 0; i < n; ++i) {
        cin >> operations[i];
        if (operations[i] == "LRUCache") {
            int cap;
            cin >> cap;
            args[i].push_back(cap);
        } else if (operations[i] == "get") {
            int key;
            cin >> key;
            args[i].push_back(key);
        } else if (operations[i] == "put") {
            int key, value;
            cin >> key >> value;
            args[i].push_back(key);
            args[i].push_back(value);
        }
    }

    vector<string> results;
    for (int i = 0; i < n; ++i) {
        if (operations[i] == "LRUCache") {
            obj = new LRUCache(args[i][0]);
            results.push_back("null");
        } else if (operations[i] == "get") {
            int result = obj->get(args[i][0]);
            results.push_back(to_string(result));
        } else if (operations[i] == "put") {
            obj->put(args[i][0], args[i][1]);
            results.push_back("null");
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << ", ";
        cout << results[i];
    }
    cout << endl;

    return 0;
}
