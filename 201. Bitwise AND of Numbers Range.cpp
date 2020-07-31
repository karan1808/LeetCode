class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		if (m == n) {return m;} else {
			int cou = 0;
			while (m != n) {
				m = m >> 1;
				n = n >> 1;
				cou++;
			}
			return m << cou;
		}
	}
};