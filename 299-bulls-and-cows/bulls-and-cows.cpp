class Solution {
public:
    string getHint(string& secret, string& guess) {
        int size = secret.size();
        int bulls = 0, cows = 0;
        int freq[10] = {0};
        for (int i = 0; i < size; ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                freq[secret[i] - '0']++;
                freq[guess[i] - '0']--;
            }
        }
        for (int i = 0; i < 10; ++i) {
            if (freq[i] > 0) cows += freq[i];
        }
        cows = size - bulls - cows;
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};