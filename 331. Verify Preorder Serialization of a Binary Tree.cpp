class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = 0;
        int x = 0;
        stack<char> s;
        s.push('s');
        for (int c = 0; c < preorder.size(); c++) {
            if (s.empty()) {return false;}
            if (preorder[c] == ',') {} else {
                if (preorder[c] == '#') {s.pop();} else {
                    s.push('s');
                    while (c < preorder.size() && preorder[c] != ',') {c++;}
                }
            }
        }



        return s.size() == 0 ? true : false;
    }
};