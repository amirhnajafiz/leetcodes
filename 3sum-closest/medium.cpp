class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = INT_MAX;
        int out;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                long long sum = (long long)nums[i] + nums[left] + nums[right];
                long long tmp = abs(sum - target);

                if (tmp < res) {
                    res = tmp;
                    out = sum;
                }

                if (sum < target) left++;
                else right--;
            }
        }

        return out;
    }
};
