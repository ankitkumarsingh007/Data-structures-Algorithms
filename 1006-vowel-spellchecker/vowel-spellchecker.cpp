class Solution {
public:
    string toLowerCase(string s) {
        string res = "";
        for (char c : s) {
            if (islower(c)) {
                res += c;
            } else
                res += (c - 'A' + 'a');
        }
        return res;
    }
    string eraseVowel(string s) {
        s = toLowerCase(s);
        string res = "";
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (j < s.size()) {
                char c = s[j];
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    j++;
                else
                    break;
            }
            if (j == i) {
                res += s[i];
                i++;
            } else {
                res += to_string(j - i);
                i = j;
            }
        }
        return res;
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> st;
        unordered_map<string, int> lowermap;
        unordered_map<string, int> vowelErrorMatch;

        for (int i = 0; i < wordlist.size(); i++) {
            string s = wordlist[i];
            string strLow = toLowerCase(s), strVowelErased = eraseVowel(s);
            st.insert(s);
            if (lowermap.find(strLow) == lowermap.end()) {
                lowermap[strLow] = i;
            }
            if (vowelErrorMatch.find(strVowelErased) == vowelErrorMatch.end()) {
                vowelErrorMatch[strVowelErased] = i;
            }
        }

        vector<string> res;

        for (string s : queries) {
            string strLow = toLowerCase(s), strVowelErased = eraseVowel(s);

            if (st.find(s) != st.end()) {
                res.push_back(s);
            } else if (lowermap.find(strLow) != lowermap.end()) {
                res.push_back(wordlist[lowermap[strLow]]);
            } else if (vowelErrorMatch.find(strVowelErased) !=
                       vowelErrorMatch.end()) {
                res.push_back(wordlist[vowelErrorMatch[strVowelErased]]);
            } else {
                res.push_back("");
            }
        }

        return res;
    }
};