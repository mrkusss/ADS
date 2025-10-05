/*
Converging pointers technic uses two pointers that start at different positions (usually the beginning and end of an array or string) 
                                    and move toward each other until they meet.
    This technique helps efficiently solve problems like finding pairs, checking palindromes, or partitioning data.
        It reduces time complexity by avoiding unnecessary nested loops, often achieving O(n) performance.
*/

/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

                 Find two lines that together with the x-axis form a container, such that the container contains the most water.

                                        Return the maximum amount of water a container can store.

                                                Notice that you may not slant the container.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(const vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
        int width = right - left;
        int current_height = min(height[left], height[right]);
        int current_area = width * current_height;
        max_area = max(max_area, current_area);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    int n;
    cout << "Enter the number of lines: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the heights of the lines:\n";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int result = maxArea(height);
    cout << "The maximum area of water that can be contained is: " << result << endl;

    return 0;
}

