#pragma once
#include"stdafx.h"
using namespace std;

//// ֻ�ܽ���һ��
class MaxProfit
{
public:
	int maxProfit(vector<int>& prices);
};


//// ���Զ�ν���
class MaxProfitII
{
public:
	//// �ǳ������ķ���
	int maxProfit(vector<int>& prices);

	//// �ǳ����ķ���
	int maxProfitII(vector<int>& prices);
};

class MaxProfitIII
{
public:
	int maxProfit(vector<int>& prices);
};

//// LeetCode.198 ��ҽ���
class DJJS
{
public:
	int rob(vector<int>& nums);

	//// ��ʹ������
	int robII(vector<int>& nums);
};

class JudgeSubsequence
{
public:
	bool isSubsequence(string s, string t);
};

class LeastCostJump
{
public:
	int minCostClimbingStairs(vector<int> &cost);
};

//// ������Ӵ�
class LongestPalindromeSubStr {
public:
	string longestPalindrome(string s);
};

//// ������
class MaxRectangle {
public:
	int maximalRectangle(vector<vector<char>>& matrix);
};

//// LeetCode 62��63
class DifferentPath {
public:
	int uniquePathsI(int m, int n);

	//// �Ż�1
	int uniquePathsOptimizeI(int m, int n);

	//// �Ż�2
	int uniquePathsOptimizeII(int m, int n);

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
};


class MinPath {
public:
	int minPathSum(vector<vector<int>>& grid);
};

class DecodeMethod
{
public:
	int numDecodings(string s);
};

class LongestSubStr
{
public:
	//// ����ظ��Ӵ�
	int lengthOfLongestSubstring(string s);
};

class Convert
{
public:
	//// Z��ת��
	string convert(string s, int numRows);
};

//// https://leetcode-cn.com/problems/longest-common-subsequence
//// ����������һ����Ŀ
class CommonSubstr
{
public:
	int longestCommonSubsequence(string text1, string text2);
};

class PivotIndex
{
public:
	int pivotIndex(vector<int>& nums);

	//// �򵥵ķ���
	int pivotIndexI(vector<int>& nums);
};

class SpiralOrder
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix);
};

//// ˫ָ��������ָ���ƶ��Ĺ�����Ҫ��¼��Ŀǰ���Ž������ֵ
class MaxContainer
{
public:
	//// �����ƽ�
	int maxArea(vector<int>& height);

	//// ˫ָ�뷨
	int maxAreaDoublePtr(vector<int>& height);
};

class SumOfThree
{
public:
	vector<vector<int>> threeSum(vector<int>& nums);
};

class MinSubArr
{
public:
	//// ����ķ���-���ÿ���
	int minSubArrayLenWrong(int s, vector<int>& nums);

	//// ��������
	int minSubArrayLen(int s, vector<int>& nums);
};

class MyCircularQueue {
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k);
	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value);

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue();

	/** Get the front item from the queue. */
	int Front();

	/** Get the last item from the queue. */
	int Rear();

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty();

	/** Checks whether the circular queue is full or not. */
	bool isFull();

private:
	int *arr;
	int iLength;
	int iHead;
	int iRear;
};

//// ���������
class TaskOperator
{
public:
	int leastInterval(vector<char>& tasks, int n);
	//constexpr bool compare(int &a, int &b)
	//{
	//	return a>b;   //�������У������Ϊreturn a<b����Ϊ����
	//}

	int leastIntervalEasy(vector<char>& tasks, int n);
};

class PingCount
{
private:
	queue<int> q;
public:
	PingCount();

	int ping(int t);
};

class ValidSyntax
{
public:
	bool isValid(string s);
};

class DailyTemperatures
{
public:
	//// ��ʱ
	vector<int> dailyTempOverTime(vector<int>& T);
	vector<int> dailyTemp(vector<int>& T);
};

class SimplifyPath
{
public:
	string simplifyPath(string path);
};

class EvalRPN
{
public:
	int evalRPN(vector<string>& tokens);
};

class TrapWater
{

private:
	struct MyStruct
	{
		int iVal;
		int iExp = 1;
	};
public:
	//// ͨ��ջʵ��
	int TrapHardWay(vector<int>& height);

	//// ����򵥵ķ��� ѭ�����ÿ��ֵ��ߵ������ұߵ����
	int TrapEasyWay(vector<int>& height);
};

class MaxRec
{
public:
	//// �ݹ�
	int lgtRectangleArea(vector<int>& heights);

	//// ����ջ
	int largestRectangleArea(vector<int>& heights);


	int CalMinIdx(vector<int>& heights, int iStart, int iEnd);
};

class MyLinkedList {
public:
	struct LinkNode
	{
		int iVal;
		LinkNode *Next;
		LinkNode(int i) :iVal(i), Next(NULL) {};
	};

	/** Initialize your data structure here. */
	MyLinkedList();

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index);

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val);

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val);

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val);

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index);

	//// �Ƴ�������k���ڵ�
	LinkNode* removeNthFromEnd(LinkNode* head, int n);

	//// 23�� �ϲ�k����������
	LinkNode* mergeKLists(vector<LinkNode*>& lists);

private:
	LinkNode *Head;
	LinkNode *Tail;
	int iLength;
};

class NumSquare
{
public:
	int numSquare(int n);
};

class JumpGame
{
public:
	bool CanJump(vector<int>& heights);
};

class RemoveK
{
public:
	string removeKdigits(string num, int k);
};

class FindNumInRotate
{
public:
	int search(vector<int>& nums, int target);
};

class FindWord
{
public:
	//// ����һ
	bool exist(vector<vector<char>>& board, string word);
	bool Find(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string substr);

	//// ������
	bool existSaveTime(vector<vector<char>>& board, string word);
	bool DFS(vector<vector<char>>& board, vector<vector<bool>>& flag, int i, int j, int iCurSize, string word);
};

class FindKClosestNum
{
public:
	//// ����ʵ��
	vector<int> findClosestElements(vector<int>& arr, int k, int x);

	//// ˫ָ�뷨
	vector<int> findClosestElementsDlbPtr(vector<int>& arr, int k, int x);
};

class OpenLock
{
public:
	int openLock(vector<string>& deadends, string target);
};

class MergeSection
{
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals);
	static bool cmp1(const vector<int> &a, const vector<int> &b)
	{
		return a[0] < b[0];
	}
};

class MaxNum
{
public:
	//// �Լ�д�ķ������е�� ����Ч��ͦ��4ms
	string largestNumber(vector<int>& nums);
    static bool cmp(const string &a, const string &b)
	{
		int iLenA = a.length();
		int iLenB = b.length();
		int iMin = min(iLenA, iLenB);
		for (int i = 0; i < iMin; i++)
		{
			if (a[i] > b[i])
			{
				return true;
			}
			else if(a[i] < b[i])
			{
				return false;
			}
		}

		if (iLenA < iLenB)
		{
			return cmp(a, b.substr(iLenA));
		}
		else if(iLenA > iLenB)
		{
			return cmp(a.substr(iLenB), b);
		}

		return false;
	}

	//// ���������΢��ʱһ��12ms
	string largestNumberSuccinct(vector<int>& nums);
};

class WiggleSort
{
public:
	void wiggleSort(vector<int>& nums);
	void wiggleSortII(vector<int>& nums);
};

class FindDuplicate
{
public:
	//// �ѶȽϴ���ʱ�����
	int findDuplicate(vector<int>& nums);
};

class ExchangeNode
{
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}

	};

	//// ����������Ȼ�ܹ�
	ListNode* swapPairs(ListNode* head);

	//// ��������������
	ListNode* swapPairsI(ListNode* head);

	//// �ݹ鷽�� ����Ч
	ListNode* swapPairsII(ListNode* head);
};

class DividSubset
{
public:
	bool canPartitionKSubsets(vector<int>& nums, int k);
};


class MaxSameValuePath
{

private:
	int iMax = 0;
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	int longestUnivaluePath(TreeNode* root);
	int GetMax(TreeNode* root, int iVal);
};

class FindFirstAndLast
{
public:
	//// ����Ƚφ���
	vector<int> searchRange(vector<int>& nums, int target);


	////���һ��
	vector<int> searchRangeII(vector<int>& nums, int target);
};

class LongestIncreasingPath
{
public:
	//// ���������ʱ��
	int longestIncreasingPath(vector<vector<int>>& matrix);

	int DFS(vector<vector<int>>& matrix, int i, int j, int CurVal);

	int longestIncreasingPathSaveTime(vector<vector<int>>& matrix);
};

class CountSmaller
{
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	vector<int> countSmaller(vector<int>& nums);
private:
	TreeNode* ConstructTree(vector<int>& nums)
	{
		if (nums.empty())
		{
			return NULL;
		}

		TreeNode *TopNode = new TreeNode(nums[0]);
		for (int i = 1; i < nums.size(); i++)
		{
			TreeNode *TmpNode = TopNode;
			int iVal = nums[i];
			while (true)
			{
				if (iVal >= TmpNode->val)
				{
					if (TmpNode->right == NULL)
					{
						TmpNode->right = new TreeNode(iVal);
						break;
					}
					else
					{
						TmpNode = TmpNode->right;
					}
				}
				else
				{
					if (TmpNode->left == NULL)
					{
						TmpNode->left = new TreeNode(iVal);
						break;
					}
					else
					{
						TmpNode = TmpNode->left;
					}
				}
			}
			
		}

		return TopNode;
	}

	int NodeCnt(TreeNode* Top)
	{
		if (Top == NULL)
		{
			return 0;
		}

		int iCnt = 1;
		iCnt += NodeCnt(Top->left);
		iCnt += NodeCnt(Top->right);

		return iCnt;
	}
};

class AllPossibleFBT
{
public: 
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	vector<TreeNode*> allPossibleFBT(int N);
};

class AtomCnt
{
public:
	struct Atom {
		string Name;
		int iCnt;
		Atom(string sName, int x) : Name(sName), iCnt(x) {}
	};

	string countOfAtoms(string formula);

};

class GiveOutCandy
{
public:
	int candy(vector<int>& ratings);
};

class BinaryTree
{
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	vector<int> preorderTraversal(TreeNode* root);
	vector<vector<int>> levelOrder(TreeNode* root);


	//// Ѱ����ͬ����
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root);
	bool IsSame(TreeNode* pNode1, TreeNode* pNode2)
	{
		if ((pNode1 == NULL && pNode2 != NULL)
			|| (pNode1 != NULL && pNode2 == NULL))
		{
			return false;
		}

		if (pNode1 == NULL && pNode2 == NULL)
		{
			return true;
		}

		bool bRes = false;

		if (pNode1->val == pNode2->val)
		{
			bRes = true;
		}

		bRes = IsSame(pNode1->left, pNode2->left) && IsSame(pNode1->right, pNode2->right);
		return bRes;
	}

	void PreOrder(vector<TreeNode*> &Res, TreeNode* root)
	{
		if (root == NULL)
		{
			return;
		}

		if (root->left == NULL && root->right == NULL)
		{
			Res.push_back(root);
			return;
		}

		Res.push_back(root);
		if (root->left == NULL)
		{
			Res.push_back(NULL);
		}

		PreOrder(Res, root->left);
		
		if (root->right == NULL)
		{
			Res.push_back(NULL);
		}

		PreOrder(Res, root->right);
	}


	//// �Ż� �ڱ�����ʱ����뼯��
	string PreOrderII(TreeNode* root, map<string, int> &pMap, vector<BinaryTree::TreeNode*> &ResVec)
	{
		string str = "";
		if (root == NULL)
		{
			return str;
		}

		if (root->left == NULL && root->right == NULL)
		{
			//// ����Ҫע�� ��Ҷ�ӽڵ���ҲҪ���뼯�ϴ������жϡ�
			str += to_string(root->val);
			if (pMap[str] == 1)
			{
				ResVec.push_back(root);
			}

			pMap[str] += 1;
			return str;
		}

		str += to_string(root->val);
		if (root->left == NULL)
		{
			str += "null";
		}

		str += PreOrderII(root->left, pMap, ResVec);

		if (root->right == NULL)
		{
			str += "null";
		}

		str += PreOrderII(root->right, pMap, ResVec);

		//// ���ϴ������ж�
		if (pMap[str] == 1)
		{
			ResVec.push_back(root);
		}

		pMap[str] += 1;


		return str;
	}


	bool isValidBST(TreeNode* root);
	bool Test(TreeNode* root, int *iPre)
	{
		if (root == NULL)
		{
			return true;
		}

		bool bLeft = Test(root->left, iPre);
		if (iPre && *iPre >= root->val)
		{
			return false;
		}
		else
		{
			iPre = &root->val;
		}

		bool bRight = Test(root->right, iPre);

		return bLeft && bRight;
	}

	//// ����α���������
	TreeNode* ConstructTreeMain(vector<int>& nums)
	{
		TreeNode* root = new TreeNode(nums[0]);
		
		queue<TreeNode*> pQue;

		pQue.push(root);
		int j = 1;
		while (!pQue.empty())
		{
			int iSize = pQue.size();
			for (int i = 0; i < iSize; i++)
			{
				TreeNode* pTopNode = pQue.front();
				pQue.pop();

				if (j >= nums.size())
				{
					return root;
				}

				if (j < nums.size())
				{
					if (nums[j] != -1)
					{
						TreeNode* pLeft = new TreeNode(nums[j]);
						pTopNode->left = pLeft;
						pQue.push(pLeft);
					}

					j++;
				}

				if (j < nums.size())
				{
					if (nums[j] != -1)
					{
						TreeNode* pRight = new TreeNode(nums[j]);
						pTopNode->right = pRight;
						pQue.push(pRight);
					}

					j++;
				}
			}
		}

		return root;
	}

	int GetMaxLen(TreeNode* root, int iCurMaxVal, int& iMax);

	//// 124. �������е����·����
	int maxPathSum(TreeNode* root, int& iMax);
};

class UglyNum
{
public:
	//// ��ָ�뷨
	int nthUglyNumber(int n);

	//// ��С�ѷ�
	int nthUglyNumberMinHeap(int n);
};

class TopKFrequent
{
public:
	vector<string> topKFrequent(vector<string>& words, int k);

	static bool cmp(pair<string, int>& a, pair<string, int>& b)
	{
		if (a.second > b.second)
		{
			return true;
		}

		if (b.second == a.second)
		{
			return a.first > b.first;
		}

		return false;
	}
};

class MaxSlidingWindow
{
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k);
};

class IsValidSudoku
{
public:
	bool isValidSudoku(vector<vector<char>>& board);
};

class NumIslands
{
public:
	//// �������
	//20 ms, ������ C++ �ύ�л�����	29.54%���û�,�ڴ����� :8.9 MB, ������ C++ �ύ�л�����100.00% ���û� 
	int numIslands(vector<vector<char>>& grid);

	//// �������
	//// 16 ms, ������ C++ �ύ�л�����57.50%���û�,�ڴ����� :8.3 MB, ������ C++ �ύ�л�����100.00%���û�
	int numIslandsDFS(vector<vector<char>>& grid);
	void DFS(vector<vector<char>>& grid, int i, int j);
};

class FindJudge
{
public:
	int findJudge(int N, vector<vector<int>>& trust);
};

class LadderLength
{
public:
	//// ��ʱ�޴���д���������ü��������
	int ladderLength(string beginWord, string endWord, vector<string>& wordList);

	//// ����BFS��Ϊ��ʡʱ��
	int ladderLengthI(string beginWord, string endWord, vector<string>& wordList);

	//// ˫�򣬾������ڲ������ٵ��м���
	int ladderLengthII(string beginWord, string endWord, vector<string>& wordList);
};

class SumOfKNum
{
	vector<vector<int>> kSum(vector<int>& nums, int target);
	vector<vector<int>> fourSum(vector<int>& nums, int target);
};

class FindKLargest
{
public:
	int findKthLargest(vector<int>& nums, int k);
};

class GroupAnagrams
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs);
};

//// 395. ������K���ظ��ַ�����Ӵ�
class LongestSubstring
{
public:
	int longestSubstring(string s, int k);
};


