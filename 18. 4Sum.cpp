class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tg) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {

            int tar = tg - nums[i];

            for (int j = i + 1; j < n; j++) {

                int target = tar - nums[j];

                int front = j + 1;
                int back = nums.size() - 1;

                while (front < back) {

                    int sum = nums[front] + nums[back];


                    if (sum < target)
                        front++;

                    else if (sum > target)
                        back--;

                    else {
                        vector<int> triplet(4, 0);
                        triplet[0] = nums[i];
                        triplet[1] = nums[j];
                        triplet[2] = nums[front];
                        triplet[3] = nums[back];
                        res.push_back(triplet);
                        while (front < back && nums[front] == triplet[2]) {front++;}
                        while (front < back && nums[back] == triplet[3]) {back--;}

                    }


                }
                while (j + 1 < nums.size() && nums[j + 1] == nums[j])
                    j++;

            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;

        }
        return res;

    }
};