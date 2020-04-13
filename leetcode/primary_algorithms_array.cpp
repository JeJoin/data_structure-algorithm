#include <common.h>

#if PRIMARY_ALGORITHMS_ARRAY

static void displayArr(vector<int> & nums)
{
	for (auto & i : nums) {
		cout << i << " ";
	}
	cout << endl;
}

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

/*给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。*/
int maxProfit(vector<int>& prices)
{
    if (prices.size() <= 1) {
        return 0;
    }

    int max = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {
        if (prices[i] < prices[i + 1]) {
            max += prices[i + 1] - prices[i];
        }
    }
    return max;
}

void testMaxProfit()
{
    vector<int> prices = { 7,1,5,3,6,4 };
    cout << maxProfit(prices) << endl;
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

/*给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一
最高位数字存放在数组的首位， 数组中每个元素只存储一个数字
你可以假设除了整数 0 之外，这个整数不会以零开头*/
vector<int> plusOne(vector<int>& digits)
{
	bool denary = false;
	int size = digits.size();

	while (size-- && (digits[size] += 1) == 10) {
		digits[size] = 0;
	}

	if (size + 1 != digits.size()) {
		denary = digits[size + 1] == 0;
	}
		
	if (size == -1 && denary) {
		digits.insert(digits.begin(), 1);
	}

	return digits;
}

void testPlusOne()
{
	vector<int> nums1 = { 0 };
	nums1 = plusOne(nums1);
	for (auto & i : nums1) {
		cout << i << " ";
	}
	cout << endl;
}

/*给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，
同时保持非零元素的相对顺序*/
void moveZeroes(vector<int>& nums)
{
	int zeros = 0;
	int size = nums.size();
	int j = size - 1;
	for (int i = j - 1; i >= 0; --i) {
		if (nums[i] == 0) {
			zeros++;
			for (int k = i; k < j; k++) {
				nums[k] = nums[k + 1];
			}
			j--;
		}
	}

	for (int i = size - zeros; i < size; ++i) {
		nums[i] = 0;
	}

	/*  best algorithms
	if(nums.empty())return;
    int j = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != 0)
        {
            nums[j++] = nums[i];
        }
    }

    while(j < nums.size())
    {
        nums[j++] = 0;
    }
	*/
}

vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> ret;
	map<int, int> m;
	for (int i = 0; i < nums.size(); ++i) {

		int tmp = nums[i];

		if (m.find(tmp) != m.end()) {
			ret.push_back(m[tmp]);
			ret.push_back(i);
			break;
		} else {
			m[target - tmp] = i;
		}
	}
	return ret;
}

void testTwoSum()
{
	vector<int> v = { 2, 7, 11, 15 };
	vector<int> ret = twoSum(v, 9);

	for (auto i : ret) {
		cout << i << " ";
	}
	cout << endl;
}

void testMoveZeroes()
{
	vector<int> nums1 = { 0,0,6,1,6,2,2,4 };
	moveZeroes(nums1);
	displayArr(nums1);
}

void displayMatrix(vector<vector<int>> & matrix)
{
    for (auto i : matrix) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

/*给定一个 n × n 的二维矩阵表示一个图像。
将图像顺时针旋转 90 度。*/
void rotateEdge(vector<vector<int>> & m, int topRow, int topCol, int lowRow, int lowCol)
{
    //每一条边都要进行times次交换
    int times = lowCol - topCol;
    int tmp = 0;
    /**
     * 上边框:m[topRow][topCol + i]
     * 右边框:m[topRow + i][lowCol]
     * 下边框:m[lowRow][lowCol - i]
     * 左边框:m[lowRow - i][topCol]
     */
    for (int i = 0; i != times; i++) {
        tmp = m[topRow][topCol + i];
        m[topRow][topCol + i] = m[lowRow - i][topCol];
        m[lowRow - i][topCol] = m[lowRow][lowCol - i];
        m[lowRow][lowCol - i] = m[topRow + i][lowCol];
        m[topRow + i][lowCol] = tmp;
    }
}

void rotate(vector<vector<int>>& matrix)
{
#if 0
    int topRow = 0;
    int topCol = 0;
    int lowRow = matrix.size()- 1;
    int lowCol = matrix[0].size()- 1;
    while (topRow < lowRow) {
        rotateEdge(matrix, topRow++, topCol++, lowRow--, lowCol--);
    }
#else 
    int n = matrix.size();
    int tmp;
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = i; j != n; ++j) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != n / 2; ++j) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = tmp;
        }
    }
#endif
}

void testRotateMatrix()
{
    vector<vector<int>> matrix = {
    {11,12,13,21},
    {14,15,16,24},
    {17,18,19,27},
    {21,22,23,21}
    };

    displayMatrix(matrix);
    cout << "=============" << endl;
    rotate(matrix);
    displayMatrix(matrix);
}

/*给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。
我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。*/
int pivotIndex(vector<int>& nums)
{
    int sum = 0, ln = 0;
    for (auto i : nums) {
        sum += i;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (sum - nums[i] - ln == ln) {
            return i;
        }
        ln += nums[i];
    }
    return -1;
}

void testPivotIndex()
{
    vector<int> nums = { 7, 3, 6, 5, 6, 9, 1};
    cout << __FUNCTION__ << pivotIndex(nums) << endl;
}

int main()
{
	//testRemoveDuplicates();
    //testMaxProfit();
	//testRotate();
	//testContainsDuplicate();
	//testSingleNumber();
	//testIntersect();
	//testPlusOne();
	//testMoveZeroes();
    //testRotateMatrix();
    testPivotIndex();

	system("pause");
	return 0;

}

#endif // PRIMARY_ALGORITHMS_ARRAY
