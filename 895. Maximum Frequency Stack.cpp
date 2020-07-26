class FreqStack {
    priority_queue<pair<int, pair<int, int>>> pq;
    unordered_map<int, int> mp;
    int yo = 0;
public:
    FreqStack() {

    }

    void push(int x) {
        pq.push(make_pair(++mp[x], make_pair(yo++, x)));
    }

    int pop() {
        auto yy = pq.top();
        int x = yy.second.second;
        mp[x]--;
        pq.pop();
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */