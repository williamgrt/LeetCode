bool knows(int a, int b);

class Solution {
public:
  int findCelebrity(int n) {
    int left = 0, right = n - 1;
    while (left < right) {
      // 1. 如果left知道right, 那么left就不是名人
      // 2. 如果left不知道right, 那么right就不是名人
      if (knows(left, right)) {
        ++left;
      } else {
        --right;
      }
    }
    // 验证最终得到的left是否是名人
    for (int i = 0; i < n; ++i) {
      if (i != left && knows(left, i))
        return -1;
      if (!knows(i, left))
        return -1;
    }
    return left;
  }
};