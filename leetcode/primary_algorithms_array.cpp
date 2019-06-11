#include <common.h>

#if PRIMARY_ALGORITHMS_ARRAY
/* ����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�*/
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

/*����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ���*/
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

/*����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
����κ�ֵ�������г����������Σ��������� true��
���������ÿ��Ԫ�ض�����ͬ���򷵻� false*/
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

/*����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬
����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ��*/
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

/*�����������飬��дһ���������������ǵĽ���*/
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
