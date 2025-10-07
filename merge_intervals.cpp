#include <vector>
#include <algorithm> // For std::sort and std::max

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        // Handle the edge case of an empty input list
        if (intervals.empty()) {
            return {};
        }

        // --- Step 1: Sort the intervals by their start times ---
        // We can use a lambda function for custom sorting.
        std::sort(intervals.begin(), intervals.end(), 
                  [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        std::vector<std::vector<int>> merged;
        merged.push_back(intervals[0]); // Add the first interval to start

        // --- Step 2: Iterate and merge overlapping intervals ---
        for (int i = 1; i < intervals.size(); ++i) {
            // Get the last interval in our merged list
            std::vector<int>& last_interval = merged.back();
            // Get the current interval from the sorted input
            std::vector<int>& current_interval = intervals[i];

            // Check for overlap: current interval's start <= last interval's end
            if (current_interval[0] <= last_interval[1]) {
                // Merge by updating the end of the last interval
                last_interval[1] = std::max(last_interval[1], current_interval[1]);
            } else {
                // No overlap, so add the current interval as a new one
                merged.push_back(current_interval);
            }
        }

        return merged;
    }
};
