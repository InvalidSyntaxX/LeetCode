#include"DynamicPrograming.h"
using namespace std;
int main()
{
	MaxProfit pTes;
	vector<int> iVec = { 2,4,1 };
	int iMax = pTes.maxProfit(iVec);

	MaxProfitII pTesII;
	int iMaxII = pTesII.maxProfit(iVec);
	return 0;
}

