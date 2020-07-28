class Solution {
    vector<string> res;
    string solution = "";
public:
    vector<string> restoreIpAddresses(string s) {

        backtrack(s, 0, 0);
        return res;
    }
    void backtrack(string s, int start, int part) {
        if (part == 4 && start == s.size()) {
            res.push_back(solution);
        }

        for (int i = start; i < s.size(); i++) {

            if (part < 4 && i - start < 3 && validip(s, start, i)) {
                solution += s.substr(start, i - start + 1);
                part++;
                if (part < 4)solution += ".";
                backtrack(s, i + 1, part);
                if (part < 4) solution.pop_back();
                part--;
                for (int j = 0; j < i - start + 1; j++) solution.pop_back();
            }
        }
    }
    bool validip(string s, int start, int end) {
        if (s[start] == '0' && start != end) {return false;}
        string temp = s.substr(start, end - start + 1);
        int t = stoll(temp);
        if (t <= 255 && t >= 0) {return true;}
        return false;
    }

};