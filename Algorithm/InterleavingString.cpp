// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         int l1 = s1.length();
//         int l2 = s2.length();
//         int l3 = s3.length();
//         if (l1 + l2 != l3) return false;
//         // dp[i][j]: wheter s3[0:i+j] is a interleva of s2[0:i] ans s2[0:j]
//         vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
//         dp[0][0] = true;
//         for (int i = 0; i <= l1; ++i)
//             for (int j = 0; j <= l2; ++j) {
//                 if (i > 0) dp[i][j] |= dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
//                 if (j > 0) dp[i][j] |= dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
//             }
//         return dp[l1][l2];
//     }
// };

// Recursion + Memorization
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        m_ = vector<vector<int>>(s1.length() + 1, vector<int>(s2.length() + 1, INT_MIN));
        return dp(s1, s1.length(), s2, s2.length(), s3, s3.length());
    }
private:
    // m_[i][j]: wheter s3[0:i+j] is a interleva of s1[0:i] and s2[0:j]
    vector<vector<int>> m_;
    
    bool dp(const string& s1, int l1, const string& s2, int l2, const string& s3, int l3) {
        if (l1 + l2 != l3) return false;
        if (l1 == 0 && l2 == 0) return true;
        if (m_[l1][l2] != INT_MIN) return m_[l1][l2];
        // 下面l1 > 0 后面的&& 与 l2 > 0 后面的&& 和花花代码不同，但是运行答案正确，花花blog代码运行错误。所以应该是花花代码少写&。
        if (l1 > 0 && s3[l3 - 1] == s1[l1 - 1] && dp(s1, l1 - 1, s2, l2, s3, l3 - 1)
          ||l2 > 0 && s3[l3 - 1] == s2[l2 - 1] && dp(s1, l1, s2, l2 - 1, s3, l3 - 1))
            m_[l1][l2] = 1;
        else
            m_[l1][l2] = 0;
        return m_[l1][l2];
    }
};
