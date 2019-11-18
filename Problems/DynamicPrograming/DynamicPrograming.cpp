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
	bool bBuy = false;


	for (int i = 1; i < prices.size(); i++)
	{
		if (iBuyPri >= prices[i])
		{
			iBuyPri = prices[i];
			iSellPri = iBuyPri;
		}

 		if (iSellPri <= prices[i])
		{
			if (!bBuy)
			{
				iBuyPri = iSellPri;
				bBuy = true;
			}

			iSellPri = prices[i];
		}

		int iNxt = i + 1;
		if ((iNxt == prices.size() - 1 && iSellPri > prices[iNxt]) 
			|| iNxt > prices.size() - 1)
		{
			iBonus += iSellPri - iBuyPri;
			return iBonus;
		}
		else if (iSellPri > prices[iNxt])
		{
			iBonus += iSellPri - iBuyPri;
			iBuyPri = iSellPri = prices[i + 1];
			bBuy = false;
		}
	}

	return iBonus;
}

int MaxProfitII::maxProfitII(vector<int>& prices)
{
	int iBonus = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		int iTmp = prices[i] - prices[i - 1];
		if (iTmp > 0)
		{
			iBonus += iTmp;
		}
	}

	return iBonus;
}

int MaxProfitIII::maxProfit(vector<int>& prices)
{
	return -1;
}

