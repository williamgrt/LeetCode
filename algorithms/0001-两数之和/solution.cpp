class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_set<int> cnt;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (cnt.count(target - nums[i]) != 0) {
        vector<int> result = {i};
        int j = i - 1;
        while (nums[j] != target - nums[i])
          --j;
        result.push_back(j);
        return result;
      } else {
        if (cnt.count(nums[i]) == 0) {
          cnt.insert(nums[i]);
        }
      }
    }
    return {-1, -1};
  }
};