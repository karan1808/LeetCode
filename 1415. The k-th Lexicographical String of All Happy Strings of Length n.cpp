class Solution {
    vector<string> v;
    string s = "";
public:
    string getHappyString(int n, int k) {
        permu(s, n);

        if (k > v.size()) {return "";} else {
            return v[k - 1];
        }
    }
    void permu(string s, int n) {
        if (s.length() == n) {
            v.push_back(s);
            cout << s << " s " << endl;
        } else {
            for (int i = 0; i < 3; i++) {
                char c = 'a';
                c += i;
                s += c;
                if (s.size() == 1) {permu(s, n);} else {
                    if (s[s.size() - 1] != s[s.size() - 2]) {permu(s, n);}
                }
                s.pop_back();
            }
        }
    }
};