class Solution {
public:
	int hammingDistance(int x, int y) {
		int res = 0;
		int n = x ^ y;
		while (n > 0) {
			res += (n & 1) ? 1 : 0;
			n >>= 1;
		}
		return res;
	}
};