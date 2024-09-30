#include <deque>
#include <queue>

class CustomStack {
public:
    std::deque<int> q;
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (q.size() == maxSize) {
            return;
        } else {
            q.push_front(x);
        }
    }

    int pop() {
        if (q.empty()) {
            return -1;
        }

        int val = q.front();
        q.pop_front();
        return val;
    }

    void increment(int k, int val) {
        if (k > q.size()) {
            k = q.size();
        }

        std::deque<int> temp;
        while (k--) {
            temp.push_front(q.back() + val);
            q.pop_back();
        }

        while (!temp.empty()) {
            q.push_back(temp.front());
            temp.pop_front();
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