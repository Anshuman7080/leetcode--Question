class CustomStack {
public:
    class Node {
    public:
        int data;
        Node* front;
        Node* prev;
        Node(int data) {
            this->data = data;
            front = nullptr;
            prev = nullptr;
        }
    };

    Node* root;
    int cnt;
    int size;

    CustomStack(int maxSize) {
        this->cnt = maxSize;
        size = 0;
        root = nullptr;
    }

    void push(int x) {
        if (size == cnt) {
            return;
        }
        Node* temp = new Node(x);
        if (size == 0) {
            root = temp;
        } else {
            temp->front = root;
            root->prev = temp;
            root = temp;
        }
        size++;
    }

    int pop() {
        if (size == 0) {
            return -1;
        }
        int val = root->data;
        Node* temp = root;
        root = root->front;
        if (root != nullptr) {
            root->prev = nullptr;
        }
        delete temp;
        size--;
        return val;
    }

    void increment(int k, int val) {
        if (size == 0) {
            return;
        }
        Node* temp = root;
        if (size < k) {
            k = size;
        }
        while (temp->front) {
            temp = temp->front;
        }
        while (k > 0 && temp) {
            temp->data += val;
            temp = temp->prev;
            k--;
        }
    }
};


/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */