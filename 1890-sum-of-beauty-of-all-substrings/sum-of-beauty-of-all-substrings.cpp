class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int totalBeauty = 0;

        // Iterate through all possible substrings
        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0); // Frequency array for each character in the substring
            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++; // Increment the frequency of the current character
                
                // Find the minimum and maximum frequency in the current substring
                int maxFreq = 0, minFreq = n; // maxFreq is the maximum frequency, minFreq is the minimum frequency
                for (int k = 0; k < 26; ++k) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }
                
                // The beauty of the substring is the difference between maxFreq and minFreq
                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};
