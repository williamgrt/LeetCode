func minDistance(word1 string, word2 string) int {
    m, n := len(word1), len(word2)
    // 我们需要使用一个temp数组保存上一轮迭代的状态
    dp, temp := make([]int, m + 1), make([]int, m + 1)
    for i := 1; i <= m; i++ {
        dp[i] = i
        temp[i] = i
    }
    for j := 1; j <= n; j++ {
        dp[0] = j
        for i := 1; i <= m; i++ {
            dp[i] = min(dp[i], dp[i-1]) + 1
            if (word1[i-1] == word2[j-1]) {
                dp[i] = min(dp[i], temp[i-1])
            } else {
                dp[i] = min(dp[i], temp[i-1] + 1)
            }
        }
        for i := 0; i <= m; i++ {
            temp[i] = dp[i]
        } 
    }
    return dp[m]
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}