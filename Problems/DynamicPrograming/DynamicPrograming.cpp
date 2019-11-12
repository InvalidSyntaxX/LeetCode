// DynamicPrograming.cpp : 定义控制台应用程序的入口点。
#pragma once
#include "stdafx.h";
#include"DynamicPrograming.h"
using namespace std;

int MaxProfit::maxProfit(vector<int>& prices) {
	int iMinPrice = prices[0];
	int iMaxPro = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] < iMinPrice)
		{
			iMinPrice = prices[i];
			continue;
		}

		iMaxPro = max(iMaxPro, prices[i] - iMinPrice);
	}

	return iMaxPro;
};

int MaxProfitII::maxProfit(vector<int>& prices)
{
	if (prices.size() == 0)
	{
		return 0;
	}

	int iBuyPri = prices[0];
	int iSellPri = iBuyPri;
	int iBonus = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		if (iBuyPri >= prices[i])
		{
			iBuyPri = prices[i];
			iSellPri = iBuyPri;
			continue;
		}

 		if (iSellPri <= prices[i])
		{
			iSellPri = prices[i];
			if (i == prices.size() - 1)
			{
				iBonus += iSellPri - iBuyPri;
			}

			continue;
		}
		else
		{
			iBonus += iSellPri - iBuyPri;
			iBuyPri = iSellPri = prices[i];
		}
	}

	return iBonus;
}

