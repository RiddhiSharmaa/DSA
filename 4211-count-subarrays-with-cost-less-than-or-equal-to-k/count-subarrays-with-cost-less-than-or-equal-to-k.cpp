class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long left = 0, cost = 0, cnt = 0;
        deque<long long>maxDq, minDq;

        for (int right = 0; right < nums.size(); right++){
            while (!maxDq.empty() && nums[right] >= nums[maxDq.back()]){
                maxDq.pop_back();
            }
            maxDq.push_back(right);

            while (!minDq.empty() && nums[right] <= nums[minDq.back()]){
                minDq.pop_back();
            }
            minDq.push_back(right);

            while (!maxDq.empty() && !minDq.empty()){
                long long maxVal = nums[maxDq.front()];
                long long minVal = nums[minDq.front()];
                long long len = right - left + 1;

                cost = (maxVal - minVal) * len;

                if (cost <= k) break;
                if (maxDq.front() == left) maxDq.pop_front();
                if (minDq.front() == left) minDq.pop_front();

                left++;
            }

            cnt += (right-left+1);
        }

        return cnt;
    }
};