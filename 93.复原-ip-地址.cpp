/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        path.clear();
        res.clear();

        path.push_back(-1);

        backtracking(0, s);

        return res;
    }

    void backtracking(int st, string s) {
        if (path.size() == 4) {
            // 保证最后一段有数字
            if (st >= s.size() || !isIP(s, st, s.size() - 1)) {
                return;
            }
            string str;
            for (int i = 1; i < 4; i++) {
                str.append(s.substr(path[i-1] + 1, path[i]-path[i-1]));
                str.append(".");
            }
            str.append(s.substr(path[3] + 1, s.size() - path[3] - 1));
            res.push_back(str);
            cout << str << endl;
            return;
        }

        for (int i = st; i < s.size(); i++) {
            // [st, i]
            if (isIP(s, st, i)) {
                path.push_back(i);

                backtracking(i + 1, s);

                path.pop_back();
            }
            else {
                continue;
            }
        }
    }

    bool isIP(string s, int begin, int end) {
        int i = begin, j = end;
        // 0开头不行，但单独的0可以
        if (s[begin] == '0' && begin != end) {
            return false;
        }
        int num = atoi(s.substr(begin, end - begin + 1).c_str());
        if (num >= 0 && num <= 255) {
            return true;
        }
        return false;
    }

    vector<string> res;
    vector<int> path;
};


// @lc code=end

