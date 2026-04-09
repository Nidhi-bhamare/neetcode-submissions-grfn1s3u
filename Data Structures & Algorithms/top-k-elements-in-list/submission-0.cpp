class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto x: nums){
            m[x]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto X : m){
            pq.push(make_pair(X.second, X.first));
            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            pq.pop();

            ans.push_back(temp.second);
        }
        return ans;
    }
};
