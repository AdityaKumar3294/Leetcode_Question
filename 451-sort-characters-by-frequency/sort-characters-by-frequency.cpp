class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        int maxFreq = 0;
        for (char c : s) {
            freqMap[c]++;
            maxFreq = max(maxFreq, freqMap[c]);
        }

        vector<vector<char>> buckets(maxFreq + 1);
        for (auto& [c, count] : freqMap) {
            buckets[count].push_back(c);
        }

        string result = "";
        result.reserve(s.length());

        for (int freq = maxFreq; freq > 0; --freq) {
            for (char c : buckets[freq]) {
                result.append(freq, c);
            }
        }

        return result;
    }
};