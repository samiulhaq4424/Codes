/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int getMatchCount(const string& str1, const string& str2) {
        int count = 0;
        for (int i = 0; i < 6; i++) {
            if (str1[i] == str2[i]) count++;
        }
        return count;
    }

    void findSecretWord(vector<string>& wordlist, Master& master) {
        srand(time(0));
        vector<string> candidates = wordlist;

        while (!candidates.empty()) {
            int idx = rand() % candidates.size();
            string selected = candidates[idx];
            int matchResult = master.guess(selected);

            if (matchResult == 6) return;

            vector<string> filtered;
            for (const auto& word : candidates) {
                if (getMatchCount(selected, word) == matchResult) {
                    filtered.push_back(word);
                }
            }

            candidates = filtered;
        }
    }
};