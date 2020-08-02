class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long size = 0;
        for (auto s : S) {
            if (isalpha(s)) {size++;}
            if (isdigit(s)) {size *= (s - '0');}
        }
        int n = S.size();
        for (int i = n - 1; i >= 0; i--) {
            K %= size;
            if (K == 0 && isalpha(S[i])) {return (string)((string)"" + S[i]);} else {

                if (isdigit(S[i])) {size /= (S[i] - '0');} else {size--;}

            }

        }
        return "";
    }
};