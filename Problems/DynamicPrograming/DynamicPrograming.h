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
private:
	struct LinkNode
	{
		int iVal;
		LinkNode *Next;
		LinkNode(int i) :iVal(i), Next(NULL){};
	};

	LinkNode *Head;
	LinkNode *Tail;
	int iLength;
public:
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
	bool exist(vector<vector<char>>& board, string word);
};