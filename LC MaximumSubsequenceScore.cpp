class Solution {
public:
    typedef long long ll;
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        ll sum=0;
        vector<pair<ll, ll>> nums;
        for(int i=0; i<n; i++){
            nums.push_back({nums2[i], nums1[i]});
        }
        sort(nums.rbegin(), nums.rend());
        priority_queue<ll> pq;
        ll ans=0;

        for(int i=0; i<k-1; i++){
            sum += nums[i].second;
            pq.push(-nums[i].second);
        }

        for(int i=k-1; i<n; i++){
            sum += nums[i].second;
            pq.push(-nums[i].second);
            ans = max(ans, sum*nums[i].first);
            sum += pq.top();
            pq.pop();
        }
        return ans;
    }
};
