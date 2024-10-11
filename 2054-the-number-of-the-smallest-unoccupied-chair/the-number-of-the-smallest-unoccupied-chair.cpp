#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    int smallestChair(std::vector<std::vector<int>>& times, int targetFriend) {
        int n = times.size();
        std::vector<std::pair<int, int>> arrival;

       
        for (int i = 0; i < n; i++) {
            arrival.push_back({times[i][0], i});
        }

       
        std::sort(arrival.begin(), arrival.end());

      
        std::priority_queue<int, std::vector<int>, std::greater<int>> chair;

      
        for (int i = 0; i < n; i++) {
            chair.push(i);
        }

       
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> leaving;

       
        std::unordered_map<int, int> chairAssignment;

        for (int i = 0; i < n; i++) {
            
            while (!leaving.empty() && leaving.top().first <= arrival[i].first) {
                chair.push(chairAssignment[leaving.top().second]);
                leaving.pop();
            }

          
            int assignedChair = chair.top();
            chair.pop();
            chairAssignment[arrival[i].second] = assignedChair;

          
            if (arrival[i].second == targetFriend) {
                return assignedChair;
            }

          
            leaving.push({times[arrival[i].second][1], arrival[i].second});
        }

        return -1; 
    }
};
