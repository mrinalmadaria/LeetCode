#include<bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    vector<pair<int, int>> vp;
    MyCalendarTwo() {
        // Don't do anything
    }
    
    bool book(int start, int end) {
        for(auto &val : vp){
            int a = val.first, b = val.second;

            if((start<b) and (end>a)){
                int new_start = max(a, start);
                int new_end = min(b, end);

                if(check(new_start, new_end)){
                    return false;
                }
            }
        }

        vp.push_back({start, end});
        return true;
    }

     bool check(int x, int y){
        int overlapp_cnt = 0;

        for(int i=0;i<vp.size();i++){
            int a = vp[i].first, b = vp[i].second;

            if((x<b) and (y>a)){ // strict condition for overlapping
                overlapp_cnt++;
                if(overlapp_cnt == 2){
                    return true;
                }
            }
        }

        return false;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */