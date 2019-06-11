#include <common.h>

#if PRIMARY_ALGORITHMS_ARRAY
/* 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。*/
int removeDuplicates(vector<int>& nums)
{
#ifndef OPTIMIZE
	if (nums.empty()) {
		return 0;
	}
	for (auto itr = nums.begin(); itr + 1 != nums.end(); ++itr) {
		int tmp = *itr;
		while (tmp == *(itr + 1)) {
			nums.erase(itr + 1);
			if (itr + 1 == nums.end()) {
				return nums.size();
			}
		}
	}

	return nums.size();
#else
	if (nums.empty()) {
		return 0;
	}
	int ans = 1;
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] != nums[i - 1]) nums[ans++] = nums[i];
	}
	return ans;
#endif
}

void testRemoveDuplicates()
{
	vector<int> nums = { 0,0 };
	cout << "nums size: " << removeDuplicates(nums) << endl;
}

/*给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数*/
void rotate(vector<int>& nums, int k)
{
	if (nums.empty() || (k %= nums.size()) == 0) {
		return;
	}
	int size = nums.size();
	reverse(nums.begin(), nums.end() - k);
	reverse(nums.begin() + size - k, nums.end());
	reverse(nums.begin(), nums.end());
}

void testRotate()
{
	vector<int> nums = { 1,2,3,4,5,6,7 };
	rotate(nums, 3);
	for (auto & i : nums) {
		cout << i << " ";
	}
	cout << endl;
}

/*给定一个整数数组，判断是否存在重复元素。
如果任何值在数组中出现至少两次，函数返回 true。
如果数组中每个元素都不相同，则返回 false*/
bool containsDuplicate(vector<int>& nums)
{
	map<int, int> m;
	for (auto i : nums) {
		if (m.find(i) != m.end()) {
			return true;
		}
		m[i] = i;
	}
	return false;
}

void testContainsDuplicate()
{
	vector<int> nums = { 1,1,1,3,3,4,3,2,4,2 };
	cout << containsDuplicate(nums) << endl;
}

/*给定一个非空整数数组，除了某个元素只出现一次以外，
其余每个元素均出现两次。找出那个只出现了一次的元素*/
int singleNumber(vector<int>& nums)
{
	sort(nums.begin(), nums.end());

	int i = 0;
	for (; i < nums.size() - 1; i += 2) {
		if (nums[i] != nums[i + 1]) {
			return nums[i];
		}
	}

	return nums[i];
}

void testSingleNumber()
{
	vector<int> nums = { 4,1,2,1,2 };
	cout << singleNumber(nums) << endl;
}

/*给定两个数组，编写一个函数来计算它们的交集*/
vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	int length1 = nums1.size();
	int length2 = nums2.size();
	int i = 0;
	int j = 0;
	vector<int> answer;
	while ((i < length1) && (j < length2)) {
		if (nums1[i] > nums2[j]) {
			j++;
		} else if (nums1[i] < nums2[j]) {
			i++;
		} else {
			answer.insert(answer.end(), nums1[i]);
			i++;
			j++;
		}
	}
	return answer;
}

void testIntersect()
{
	/*
	[4,7,9,7,6,7]
	[5,0,0,6,1,6,2,2,4]
	*/
	vector<int> nums1 = { 4,7,9,7,6,7 };
	vector<int> nums2 = { 5,0,0,6,1,6,2,2,4 };
	for (auto & i : intersect(nums1, nums2)) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	//testRemoveDuplicates();
	//testRotate();
	//testContainsDuplicate();
	//testSingleNumber();
	testIntersect();

	system("pause");
	return 0;

}

#endif // PRIMARY_ALGORITHMS_ARRAY
