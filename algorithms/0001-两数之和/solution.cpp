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
        // 添加当前的数
        // 如果当前数已经在哈希表中存在，直接忽略
        if (cnt.count(nums[i]) == 0) {
          cnt.insert(nums[i]);
        }
      }
    }
    return {-1, -1};
  }
};