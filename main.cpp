#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int i=0, j=0, k=0;
		int closeSum,num,closeNum;
		sort(nums.begin(), nums.end());
		if (nums.size() < 3)
			return 0;
		else
		{
			closeNum = num = nums[0] + nums[1] + nums[2];
			closeSum = abs(target - (nums[0] + nums[1] + nums[2]));
		}

		while (i<nums.size())
		{
			j = i + 1;
			k = nums.size() - 1;
			while (k > j)
			{
				num = nums[i] + nums[j] + nums[k];
				if (closeSum > abs(target - num))
				{
					closeSum = abs(target - num);
					closeNum = num;
				}
				if (num > target)
					k--;
				else if (num < target)
					j++;
				else return num;
			}
			i++;
		}
		return closeNum;
	}
};
int main()
{
	Solution s;
	vector<int> v = {1,1,1,0};
	int i = s.threeSumClosest(v, -100);
	cout << i << endl;
}