#include"DynamicPrograming.h"
using namespace std;
int main()
{
	vector<vector<string>> iVec = {
		{"1","0","1","0","0"},
		{"1","0","1","1","1"},
		{"1","1","1","1","1"},
		{"1","0","0","1","0"}
	};

	int iSize = iVec.size();
	cout << iVec[0][1] << endl;

	vector<vector<int>> obstacleGrid = { {1, 2},{5, 6},{1, 1}};

	MinPath difPath;
	int i = difPath.minPathSum(obstacleGrid);

	return 0;
}

