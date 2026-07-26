class MinStack {
   public:
    stack<int> st;
    vector<int> minPref = {INT_MAX};
    int stackSize = 0;
    MinStack() {}

    void push(int val) {
        st.push(val);
        stackSize++;
        minPref.push_back(min(minPref[stackSize - 1], val));
    }

    void pop() {
        st.pop();
        minPref.pop_back();
        stackSize--;
    }

    int top() { return st.top(); }

    int getMin() { return minPref[stackSize]; }
};
