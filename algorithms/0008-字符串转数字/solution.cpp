class Solution {
public:
  int myAtoi(string str) {
    int i = 0, s = str.size();
    // 忽视所有字符串之前的空格
    while (i < s && str[i] == ' ')
      ++i;
    // 当前的输入内容不是数字
    if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
      return 0;
    // 判断结果的正负
    bool flag = str[i] == '-';
    int sum = 0;
    if (str[i] == '-' || str[i] == '+')
      ++i;
    // 处理溢出
    int max_cmp = INT_MAX / 10, min_cmp = INT_MIN / 10;
    while (i < s && str[i] >= '0' && str[i] <= '9') {
      if (sum > max_cmp || sum < min_cmp) {
        // 肯定会溢出
        // 根据每个数的符号，返回合适的返回值
        sum = flag ? INT_MIN : INT_MAX;
        break;
      } else {
        sum = sum * 10;
        // 加上下一位数后会溢出
        // 正数：是否>=2147483648
        // 负数：是否<=-2147483649
        if (sum == 2147483640 && str[i] >= '8') {
          sum = INT_MAX;
          break;
        } else if (sum == -2147483640 && str[i] == '9') {
          sum = INT_MIN;
          break;
        } else
          sum += flag ? '0' - str[i] : str[i] - '0';
      }
      ++i;
    }
    return sum;
  }
};