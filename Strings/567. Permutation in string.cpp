class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        // s1 and s2 will be anagrams if any one combination of s1 can form s2 or vice versa.
        // eg "cab" and "bca" are anagrams.
        
        // So this question can ve converted to - 
        // find any substring of s2 which is anagram of s1.
        
        // Now for s1 and s2 to be anagrams-
        // (i) s1 and s2 must have equal length.
        // (ii) s1 and s2 must have same frequency of all corresponding unique characters.
        
        // So we can use a sliding window approach to solve this in O(n) time as s1 and s2 must be of equal length
        
        
        vector<int> s1hash(26,0);
        vector<int> s2hash(26,0);
        
        int s1len = s1.length(), s2len = s2.length();
        
        if(s1len > s2len) return false;
        
        // precalculating first window of size s1len moving in s1 and storing it in s1hash and s2hash.
        int left = 0, right = 0;
        while(right < s1len){         
            s1hash[s1[right] - 'a']++;
            s2hash[s2[right] - 'a']++;
            right++;
        }
        
        right--;                      // to point right to the end of the window
         
        while(right < s2len){         // start moving our window on s2
            if(s1hash == s2hash){
                return true;
            }
            right++;
            if(right != s2len){
                s2hash[s2[right] - 'a']++;
            }
            s2hash[s2[left] - 'a']--;
            left++;
        }
        return false;
    }
};

// Time Complexity analysis:
// s1hash and s2hash are of size 26 as given all letters are lowercase.
// so in worst case we are traversing string s2 completely and matching the entire s1hash and s2hash.
// TC =  O(length of s2-length of s1+1)*alphabetsize = O(alphabet_size * len(s2));
