class Solution {
public:
	int minAddToMakeValid(string S) {
		stack<char> kl;
		for (int i = 0; i < S.length(); i++) {
			if (kl.empty()) {kl.push(S[i]);} else {
				char c = kl.top();
				if (c != S[i] && c == '(') {kl.pop();} else {kl.push(S[i]);}
			}
		}
		return kl.size();
	}
};