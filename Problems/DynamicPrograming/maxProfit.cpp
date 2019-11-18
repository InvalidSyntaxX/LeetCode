#include"DynamicPrograming.h"
using namespace std;
int main()
{
	MaxProfit pTes;
	vector<int> iVec = { 2,6,3,6,9 };
	int iMax = pTes.maxProfit(iVec);

	MaxProfitII pTesII;
	int iMaxII = pTesII.maxProfitII(iVec);
	return 0;
}

