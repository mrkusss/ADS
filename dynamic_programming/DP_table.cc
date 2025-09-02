/*
Dynamic Programming table is a data structure — usually a 1D or 2D array — 
    used to store the results of subproblems in dynamic programming
        so that they don’t have to be recomputed multiple times.

        to show how it works I solved knapsack problem with dp table
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximize_profit(const vector<int>& w, const vector<int>& v, int capacity) 
{
    vector<vector<int>> DP(w.size()+1, vector<int>(capacity+1,0));

    for (size_t item_index = 0; item_index < w.size();  ++item_index) {
        for (int item = 0; item <= capacity; ++item) {
            if (item >= w[item_index]) {
                DP[item_index+1][item] = max(
                    DP[item_index][item],
                    (DP[item_index][item - w[item_index]] + v[item_index])
                );
            }
            else {
                DP[item_index+1][item] = DP[item_index][item];
            }
        }
    }
    return DP[w.size()][capacity];
}
int main() 
{
    vector<int> w = {2, 3, 6};
    vector<int> v = {60, 100, 150};
    int capacity = 9;

    cout << maximize_profit(w, v, capacity) << endl;

    return 0;
}