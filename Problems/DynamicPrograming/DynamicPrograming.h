#pragma once
#include"stdafx.h"
using namespace std;

//// 只能交易一次
class MaxProfit
{
public:
	int maxProfit(vector<int>& prices);
};


//// 可以多次交易
class MaxProfitII
{
public:
	//// 非常繁琐的方法
	int maxProfit(vector<int>& prices);

	//// 非常简答的方法
	int maxProfitII(vector<int>& prices);
};

class MaxProfitIII
{
public:
	int maxProfit(vector<int>& prices);
};

//// LeetCode.198 打家劫舍
class DJJS
{
public:
	int rob(vector<int>& nums);

	//// 不使用数组
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

//// 最长回文子串
class LongestPalindromeSubStr {
public:
	string longestPalindrome(string s);
};

//// 最大矩形
class MaxRectangle {
public:
	int maximalRectangle(vector<vector<char>>& matrix);
};

//// LeetCode 62、63
class DifferentPath {
public:
	int uniquePathsI(int m, int n);

	//// 优化1
	int uniquePathsOptimizeI(int m, int n);

	//// 优化2
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
	//// 最长无重复子串
	int lengthOfLongestSubstring(string s);
};

class Convert
{
public:
	//// Z型转换
	string convert(string s, int numRows);
};

//// https://leetcode-cn.com/problems/longest-common-subsequence
//// 讲究方法的一道题目
class CommonSubstr
{
public:
	int longestCommonSubsequence(string text1, string text2);
};

class PivotIndex
{
public:
	int pivotIndex(vector<int>& nums);

	//// 简单的方法
	int pivotIndexI(vector<int>& nums);
};

class SpiralOrder
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix);
};

//// 双指针问题在指针移动的过程中要记录下目前最优解或最优值
class MaxContainer
{
public:
	//// 暴力破解
	int maxArea(vector<int>& height);

	//// 双指针法
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
	//// 错误的方法-不好控制
	int minSubArrayLenWrong(int s, vector<int>& nums);

	//// 滑动窗口
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

//// 任务调度器
class TaskOperator
{
public:
	int leastInterval(vector<char>& tasks, int n);
	//constexpr bool compare(int &a, int &b)
	//{
	//	return a>b;   //降序排列，如果改为return a<b，则为升序
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
	//// 超时
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
	//// 通过栈实现
	int TrapHardWay(vector<int>& height);

	//// 极其简单的方法 循环求出每个值左边的最大和右边的最大
	int TrapEasyWay(vector<int>& height);
};

class MaxRec
{
public:
	//// 递归
	int lgtRectangleArea(vector<int>& heights);

	//// 单调栈
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