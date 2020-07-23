class CustomStack {
public:
    int n;
    vector<int> stk;
    int tos=0;
	CustomStack(int n) {
		this->n=n;
		stk.assign(n,0);
	}

	void push(int x) {
		if(tos == n)
			return;

		stk[tos++] = x;
	}

	int pop() {
		if(tos == 0)
			return -1;

		return stk[--tos];
	}

	void increment(int k, int val) {
		for(int i = 0; i < min(k,tos); ++i)
			stk[i] += val;
	}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */