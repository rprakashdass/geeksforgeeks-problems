#include <bits/stdc++.h> 

int k(vector<vector<int>> &memo, vector<int> &val, vector<int> &wt, int i, int w) {
	if(w == 0) return 0;
	if(i == val.size() || w < 0) return 0;
	if(memo[i][w] != -1) return memo[i][w];
	if(wt[i] > w) return k(memo, val, wt, i+1, w);
	int pick = val[i] + k(memo, val, wt, i+1, w-wt[i]);
	int notPick = k(memo, val, wt, i+1, w);
	
	return memo[i][w] = max(pick,  notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> memo(n, vector<int>(maxWeight+1, -1));
	return k(memo, value, weight, 0, maxWeight);
}
