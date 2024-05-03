#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i, j;

        vector<int> version1Parts;
        vector<int> version2Parts;

        for (i = 0; i < version1.size(); i++) {
            string part;
            j = i;
            while (j < version1.size() && version1[j] != '.') part += version1[j++];

            i = j;
            version1Parts.push_back(stoi(part));
        }

        for (i = 0; i < version2.size(); i++) {
            string part;
            j = i;
            while (j < version2.size() && version2[j] != '.') part += version2[j++];

            i = j;
            version2Parts.push_back(stoi(part)); 
        }

        i = 0;
        j = 0;
        while (i < version1Parts.size() && j < version2Parts.size()) {
            if (version1Parts[i] > version2Parts[j]) return 1;
            else if (version1Parts[i] < version2Parts[j]) return -1;
            i++;
            j++;
        }

        while (i < version1Parts.size() && version1Parts[i] == 0) i++;
        while (j < version2Parts.size() && version2Parts[j] == 0) j++;

        if (i < version1Parts.size()) return 1;
        if (j < version2Parts.size()) return -1;
        return 0;

        
        return 1;
    }
};