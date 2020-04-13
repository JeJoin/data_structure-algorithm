#include <common.h>

#if PRIMARY_ALGORITHMS_ARRAY

static void displayArr(vector<int> & nums)
{
	for (auto & i : nums) {
		cout << i << " ";
	}
	cout << endl;
}

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

/*����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
���һ���㷨�����������ܻ�ȡ�������������Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����
ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����*/
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

/*����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ
���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢һ������
����Լ���������� 0 ֮�⣬��������������㿪ͷ*/
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

/*����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��
ͬʱ���ַ���Ԫ�ص����˳��*/
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

/*����һ�� n �� n �Ķ�ά�����ʾһ��ͼ��
��ͼ��˳ʱ����ת 90 �ȡ�*/
void rotateEdge(vector<vector<int>> & m, int topRow, int topCol, int lowRow, int lowCol)
{
    //ÿһ���߶�Ҫ����times�ν���
    int times = lowCol - topCol;
    int tmp = 0;
    /**
     * �ϱ߿�:m[topRow][topCol + i]
     * �ұ߿�:m[topRow + i][lowCol]
     * �±߿�:m[lowRow][lowCol - i]
     * ��߿�:m[lowRow - i][topCol]
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

/*����һ���������͵����� nums�����дһ���ܹ��������顰�����������ķ�����
���������������������������ģ����������������������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ͡�
������鲻����������������ô����Ӧ�÷��� -1����������ж��������������ô����Ӧ�÷��������ߵ���һ����*/
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
