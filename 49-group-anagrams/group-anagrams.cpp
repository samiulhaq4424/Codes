class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> storageMap;

        for (const string& word : strs) {
            string sortedKey = word;

            for (int i = 0; i < sortedKey.length(); i++) {
                for (int j = i + 1; j < sortedKey.length(); j++) {
                    if (sortedKey[i] > sortedKey[j]) {
                        char temp = sortedKey[i];
                        sortedKey[i] = sortedKey[j];
                        sortedKey[j] = temp;
                    }
                }
            }

            storageMap[sortedKey].push_back(word);
        }

        vector<vector<string>> organizedGroups;
        for (auto pairItem = storageMap.begin(); pairItem != storageMap.end(); ++pairItem) {
            organizedGroups.push_back(pairItem->second);
        }

        return organizedGroups;
    }
};