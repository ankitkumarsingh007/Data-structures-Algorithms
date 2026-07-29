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
    unordered_map<string, unordered_map<string, int>> mp;

    int diff(string s1, string s2) {
        int res = 0;
        for (int i = 0; i < 6; i++)
            if (s1[i] == s2[i])
                res++;

        return res;
    }

    int getPos(vector<string>& words) {
        int bestPos = 0;
        int bestWorst = INT_MAX;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            vector<int> bucket(7, 0);

            for (int j = 0; j < n; j++) {
                int m = diff(words[i], words[j]);
                bucket[m]++;
            }

            int worst = *max_element(bucket.begin(), bucket.end());

            if (worst < bestWorst) {
                bestWorst = worst;
                bestPos = i;
            }
        }
        return bestPos;
    }

    void findSecretWord(vector<string>& words, Master& master) {
        int n = words.size();

        while (true) {
            n = words.size();
            int pos = getPos(words);
            int c = master.guess(words[pos]);
            if (c == 6)
                return;

            vector<string> temp;
            for (int i = 0; i < n; i++) {
                if (diff(words[i], words[pos]) == c)
                    temp.push_back(words[i]);
            }
            words.swap(temp);
        }
        return;
    }
};