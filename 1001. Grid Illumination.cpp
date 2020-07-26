class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {

        set<pair<int, int>> lmp;

        unordered_map<int, int> x;
        unordered_map<int, int> y;
        unordered_map<int, int> xpa;
        unordered_map<int, int> xna;

        for (auto l : lamps) {
            int a = l[0];
            int b = l[1];
            lmp.insert(make_pair(a, b));
            x[a]++;
            y[b]++;
            xpa[a - b]++;
            xna[a + b]++;
        }
        vector<int> ans;
        for (auto q : queries) {
            int a = q[0];
            int b = q[1];
            // cout<<a<<" "<<b<<endl;

            // if(x.find(a)!=x.end()){cout<<1<<endl;}
            // if(y.find(b)!=y.end()){cout<<2<<endl;}
            // if(xpa.find(a-b)!=xpa.end()){cout<<3<<endl;}
            // if(xna.find(a+b)!=xna.end()){cout<<4<<endl;}

            if (x.find(a) != x.end() || y.find(b) != y.end() || xpa.find(a - b) != xpa.end() || xna.find(a + b) != xpa.end()) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }



            for (int i = a - 1; i <= a + 1; i++) {
                for (int j = b - 1; j <= b + 1; j++) {
                    // cout<<i<<" i j "<<j<<endl;
                    int xx = i;
                    int yy = j;
                    if (lmp.find(make_pair(xx, yy)) != lmp.end()) {
                        // cout<<xx<<" xx yy "<<yy<<endl;
                        lmp.erase(make_pair(xx, yy));
                        x[xx]--;
                        y[yy]--;
                        xpa[xx - yy]--;
                        xna[xx + yy]--;
                        if (x[xx] == 0) {x.erase(xx);}
                        if (y[yy] == 0) {y.erase(yy);}
                        if (xpa[xx - yy] == 0) {xpa.erase(xx - yy);}
                        if (xna[xx + yy] == 0) {xna.erase(xx + yy);}
                    }

                }
            }






        }

        return ans;
    }
};