/*
Memoization is an optimization technique used to speed up algorithms by storing the results
    of expensive function calls and reusing them when the same inputs occur again

                theres simple algorithm which uses memoization  
*/
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>

std::pair<int,int> find_pair_of_numbers(const std::vector<int>& list1, int target) 
{
    std::unordered_set<int> seen;

    for (int i : list1) {
        if (seen.find(target-i) != seen.end()) {
            return {target-i, i};
        }
        seen.insert(i);
    }
    return {-1,-1};
}

int main() 
{
    std::vector<int> list1 = {0, 2, 5, 7, 8, 9, 10};
    int target = 11;

    auto n = find_pair_of_numbers(list1, target);
    std::cout << n.first << " " << n.second << std::endl;
}
