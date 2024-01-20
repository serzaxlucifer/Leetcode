// Brute but good:

    bool checkSubstring(unordered_map<string, int> wordCount, string s, int wordLen) {
        for(int j=0; j<s.size(); j+=wordLen) {
            string w = s.substr(j, wordLen);
            if(wordCount.find(w) != wordCount.end()) {
                if(--wordCount[w] == -1) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordLen = words[0].size();
        int sLen = s.size();
        int wordsWindow = words.size() * wordLen;
        
        unordered_map<string, int> wordCount;
        for(int i=0; i<words.size(); i++) {
            wordCount[words[i]]++;
        }
        
        int i = 0;
        while(i + wordsWindow <= sLen) {
            if(checkSubstring(wordCount, s.substr(i, wordsWindow), wordLen)) {
                res.push_back(i);
            }
            i++;
        }
        return res;
    }

// TLE haha

// ,,,

vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        int n = S.size(), cnt = L.size();
        if (n <= 0 || cnt <= 0) return ans;
        
        // init word occurence
        unordered_map<string, int> dict;
        for (int i = 0; i < cnt; ++i) dict[L[i]]++;
        
        // travel all sub string combinations
        int wl = L[0].size();
        for (int i = 0; i < wl; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> tdict;
            for (int j = i; j <= n - wl; j += wl) {
                string str = S.substr(j, wl);
                // a valid word, accumulate results
                if (dict.count(str)) {
                    tdict[str]++;
                    if (tdict[str] <= dict[str]) 
                        count++;
                    else {
                        // a more word, advance the window left side possiablly
                        while (tdict[str] > dict[str]) {
                            string str1 = S.substr(left, wl);
                            tdict[str1]--;
                            if (tdict[str1] < dict[str1]) count--;
                            left += wl;
                        }
                    }
                    // come to a result
                    if (count == cnt) {
                        ans.push_back(left);
                        // advance one word
                        tdict[S.substr(left, wl)]--;
                        count--;
                        left += wl;
                    }
                }
                // not a valid word, reset all vars
                else {
                    tdict.clear();
                    count = 0;
                    left = j + wl;
                }
            }
        }
        
        return ans;
    }

// OR


class Solution {
public:
	struct matcher {
		struct info { int mtindex, count; };
		unordered_map<string_view, info>dict;
		int different_word_count;

		vector<int>slot;
		int maching_slot_count;

		matcher(const vector<string>& words) {
			int mtind = 0;
			for (auto& word : words) {
				auto find = dict.find(word);
				if (find != dict.end()) {
					++find->second.count;
				}
				else { dict[word] = { mtind++,1 }; }
			}
			different_word_count = mtind;
			slot = vector<int>(different_word_count, 0);
			maching_slot_count = 0;
		}

		void reset() {
			for (auto& i : slot) { i = 0; }
			maching_slot_count = 0;
		}
		bool match() {
			return maching_slot_count == different_word_count;
		}
		void push(string_view sv) {
			auto find = dict.find(sv);
			if (find == dict.end())return;
			if (++slot[find->second.mtindex] == find->second.count) {
				++maching_slot_count;
			}
		}
		void pop(string_view sv) {
			auto find = dict.find(sv);
			if (find == dict.end())return;
			if (--slot[find->second.mtindex] == find->second.count - 1) {
				--maching_slot_count;
			}
		}
	};
	vector<int> findSubstring(string s, const vector<string>& words) {
		int word_count = words.size();
		int word_len = words[0].size();

		matcher matcher(words);

		const char* str = s.c_str();
		int len = s.size();
		vector<int> ret;

		for (int off = 0; off < word_len; off++) {
			const char* beg = str + off, * end = str + len;
			if (beg + word_len * word_count <= end) {
				matcher.reset();
				for (int i = 0; i < word_count; i++) {
					string_view sv(beg + i * word_len, word_len);
					matcher.push(sv);
				}
				if (matcher.match()) {
					ret.push_back(beg - str);
				}
				const char* pos = beg + word_len * word_count;
				while (pos + word_len <= end) {
					string_view del(beg, word_len);
					string_view add(pos, word_len);
					beg += word_len;
					pos += word_len;
					matcher.pop(del);
					matcher.push(add);
					if (matcher.match()) {
						ret.push_back(beg - str);
					}
				}
			}
		}
		return ret;
	}
};

// OR

class Solution {
// The general idea:
// Construct a hash function f for L, f: vector<string> -> int, 
// Then use the return value of f to check whether a substring is a concatenation 
// of all words in L.
// f has two levels, the first level is a hash function f1 for every single word in L.
// f1 : string -> double
// So with f1, L is converted into a vector of float numbers
// Then another hash function f2 is defined to convert a vector of doubles into a single int.
// Finally f(L) := f2(f1(L))
// To obtain lower complexity, we require f1 and f2 can be computed through moving window.
// The following corner case also needs to be considered:
// f2(f1(["ab", "cd"])) != f2(f1(["ac", "bd"]))
// There are many possible options for f2 and f1. 
// The following code only shows one possibility (probably not the best), 
// f2 is the function "hash" in the class,
// f1([a1, a2, ... , an]) := int( decimal_part(log(a1) + log(a2) + ... + log(an)) * 1000000000 )
public:
    // The complexity of this function is O(nW).
    double hash(double f, double code[], string &word) {
        double result = 0.;
        for (auto &c : word) result = result * f + code[c];
        return result;
    }
    vector<int> findSubstring(string S, vector<string> &L) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        uniform_real_distribution<double> unif(0., 1.);
        default_random_engine seed;
        double code[128];
        for (auto &d : code) d = unif(seed);
        double f = unif(seed) / 5. + 0.8;
        double value = 0;

        // The complexity of the following for loop is O(L.size( ) * nW).
        for (auto &str : L) value += log(hash(f, code, str));

        int unit = 1e9;
        int key = (value-floor(value))*unit;
        int nS = S.size(), nL = L.size(), nW = L[0].size();
        double fn = pow(f, nW-1.);
        vector<int> result;
        if (nS < nW) return result;
        vector<double> values(nS-nW+1);
        string word(S.begin(), S.begin()+nW);
        values[0] = hash(f, code, word);

        // Use a moving window to hash every word with length nW in S to a float number, 
        // which is stored in vector values[]
        // The complexity of this step is O(nS).
        for (int i=1; i<=nS-nW; ++i) values[i] = (values[i-1] - code[S[i-1]]*fn)*f + code[S[i+nW-1]];

        // This for loop will run nW times, each iteration has a complexity O(nS/nW)
        // So the overall complexity is O(nW * (nS / nW)) = O(nS)
        for (int i=0; i<nW; ++i) {
            int j0=i, j1=i, k=0;
            double sum = 0.;

            // Use a moving window to hash every L.size() continuous words with length nW in S.
            // This while loop will terminate within nS/nW iterations since the increasement of j1 is nW,
            // So the complexity of this while loop is O(nS / nW).
            while(j1<=nS-nW) {
                sum += log(values[j1]);
                ++k;
                j1 += nW;
                if (k==nL) {
                    int key1 = (sum-floor(sum)) * unit;
                    if (key1==key) result.push_back(j0);
                    sum -= log(values[j0]);
                    --k;
                    j0 += nW;
                }
            }
        }
        return result;
    }
};

// OR

