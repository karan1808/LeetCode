class CombinationIterator {
public:
    vector<string> com;
    int cou = 0;
    CombinationIterator(string characters, int combinationLength) {
        permu("", 0, combinationLength, characters);
    }

    void permu(string s, int st, int len, string characters) {
        if (s.size() == len) {
            com.push_back(s);
        } else {
            for (int i = st; i < characters.size(); i++) {
                s += characters[i];
                permu(s, i + 1, len, characters);
                s.pop_back();
            }
        }
    }
    string next() {
        return com[cou++];
    }

    bool hasNext() {
        return cou == com.size() ? false : true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */