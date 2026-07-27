class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> mp;
        for(auto x:tasks)mp[x]++;
        priority_queue<int> pq;
        for(auto cnt:mp)pq.push(cnt.second);
        int time=0;
        queue<pair<int,int>> q;
        while(!pq.empty() || !q.empty()){
            time++;
            if(pq.empty()){
                time=q.front().second;
            }
            else{
                int cnt = pq.top() -1;
                pq.pop();
                if(cnt>0)
                q.push({cnt,time+n});
            }
            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
