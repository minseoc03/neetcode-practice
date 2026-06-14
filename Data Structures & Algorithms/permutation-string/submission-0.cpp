class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // edge case : s1 is longer than s2
        if (s1.length() > s2.length())
            return false;
        vector<int> s1_count (26, 0);
        vector<int> s2_count (26, 0);
        for (int i = 0; i < s1.length(); ++i) {
            int index = s1[i] - 'a';
            s1_count[index]++;
            index = s2[i] - 'a';
            s2_count[index]++;
        }

        int match = 0;
        for (int i = 0; i < 26; ++i) {
            if (s1_count[i] == s2_count[i]) match++;
        }

        int l = 0;
        for (int r = s1.length(); r < s2.length(); ++r) {
            if (match == 26)
                return true;
            int index = s2[r] - 'a';
            s2_count[index]++;
            if (s1_count[index] == s2_count[index]) match++;
            else if (s1_count[index] + 1 == s2_count[index]) match--;
            
            index = s2[l] - 'a';
            s2_count[index]--;
            if (s1_count[index] == s2_count[index]) match++;
            else if (s1_count[index] - 1 == s2_count[index]) match--;
            l++;
        }
        return match == 26;
    }
};
