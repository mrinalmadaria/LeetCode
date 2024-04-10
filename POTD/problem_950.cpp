#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> merge(vector<int>& left, vector<int>& right) {
        int merged_size = left.size() + right.size();
        if (merged_size % 2 == 1) {
            int last_element = right[right.size() - 1];

            for (int i = right.size() - 1; i > 0; i--) {
                right[i] = right[i - 1];
            }
            right[0] = last_element;
        }

        vector<int> merged(merged_size);
        int left_index = 0, right_index = 0, merged_index = 0;

        while (left_index < left.size() && right_index < right.size()) {
            merged[merged_index++] = left[left_index++];
            merged[merged_index++] = right[right_index++];
        }

        while (left_index < left.size()) {
            merged[merged_index++] = left[left_index++];
        }

        while (right_index < right.size()) {
            merged[merged_index++] = right[right_index++];
        }
        return merged;
    }

    vector<int> divide(vector<int>& array, int start, int end) {
        if (start > end) return {};
        if (start == end) return {array[start]};
        
        int mid = start + (end - start) / 2;
        vector<int> left_half;
        for(int i = start; i <= mid; i++){
            left_half.push_back(array[i]);
        }
        vector<int> right_half = divide(array, mid + 1, end);
        return merge(left_half, right_half);
    }
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        return divide(deck, 0, deck.size() - 1);
    }
};