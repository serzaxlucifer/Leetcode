// Primer on Aho-Corasick:    https://cp-algorithms.com/string/aho_corasick.html
// Code courtesy of: https://leetcode.com/problems/construct-string-with-minimum-cost/solutions/5431950/monster-problem-4-nsqrtn-trie-aho-corasick-dp/

struct TrieNode 
{
    TrieNode *sfx = nullptr;            // suffix links for aho corasick algorithm
    TrieNode *dict = nullptr;           // 
    std::array<TrieNode*, 26> child{};  // trie children
    int word_id = -1;                   // ID in words or costs. (positive if word exists)
};

static TrieNode preallocated_nodes[(int)5e4 + 5];       // pre-allocated
static TrieNode *preallocated_queue[(int)5e4 + 5];      // pre-allocated
static int dp[(int)1e5 + 5];                            // pre-allocated

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) 
    {
        auto trie = Trie(words, costs);     // Get the Aho-Corasick Automaton.
        int n = target.size();

        dp[0] = 0;

        for (int i = 1; i <= n; ++i) 
        {
            dp[i] = 1e9;        // Erase previous results.

            for (int j : trie.suffixesAfterAppending(target[i - 1]))        // need an iterator since we return trie itself here.
            {
                dp[i] = std::min(dp[i], dp[i - words[j].size()] + costs[j]);
            }
        }

        return dp[n] == 1e9 ? -1 : dp[n];
    }

    struct Trie 
    {
        int count = 0;      // no. of nodes.

        TrieNode *newTrieNode()
        {
            preallocated_nodes[count] = TrieNode();         // no intialization parameter needed.
            return &preallocated_nodes[count++];
        }

        TrieNode *root = nullptr, *curr = nullptr;          // curr keeps track of state of automaton

        Trie(vector<string>& words, vector<int> &costs) 
        {
            root = newTrieNode();
            root->sfx = root->dict = root;                  // for root, these point to root itself

            for (int i = 0; i < words.size(); ++i) 
            {
                auto &&word = words[i];                     // auto&& handles both lvalue and rvalue types of values. 
                                                            // not needed here but a good practice. auto& would also 
                                                            // do fine since we're dealing with lvalue here.

                TrieNode *u = root;

                for (auto c : word) 
                {
                    if (!u->child[c - 'a']) 
                    {
                        u->child[c - 'a'] = newTrieNode();
                    }
                    u = u->child[c - 'a'];
                }

                if (u->word_id < 0 || costs[i] < costs[u->word_id])     // remove duplicate with higher cost, it has no need.
                {
                    u->word_id = i;
                }
            }

            /* BUILD SUFFIX LINKS USING AHO-CORASICK BFS STYLE */
    
            Queue q;            // our custom queue!
            q.push(root);

            while (!q.empty()) 
            {
                TrieNode *u = q.pop();

                for (int i = 0; i < 26; ++i) 
                {
                    auto v = u->child[i];
                    if (!v) 
                    {
                        continue;
                    }
    
                    TrieNode *p = u->sfx;
                    while (p != root && !p->child[i]) 
                    {
                        p = p->sfx;
                    }
    
                    if (u != root && p->child[i]) 
                    {
                        v->sfx = p->child[i];
                    } 
                    else 
                    {
                        v->sfx = root;
                    }
    
                    v->dict = v->sfx->word_id >= 0 ? v->sfx : v->sfx->dict;     // suppose its suffix isn't a pattern in our dictionary! then backtrack!

                    q.push(v);
                }
            }

            curr = root;
        }

        TrieNode *start = root;

        Trie &suffixesAfterAppending(char letter) 
        {
            while (curr != root && !curr->child[letter - 'a']) 
            {
                curr = curr->sfx;
            }
    
            if (curr->child[letter - 'a']) 
            {
                curr = curr->child[letter - 'a'];
                start = curr->word_id >= 0 ? curr : curr->dict;
            } 

            else 
            {
                start = root;
            }

            return *this;       // return your own address.
        }

        struct Iterator 
        {
            TrieNode *u = nullptr;
            Iterator &operator++() { u = u->dict; return *this; }
            bool operator==(Iterator &o) { return u == o.u; }
            int operator*() { return u->word_id; }
        };

        Iterator begin() { return Iterator{start}; } 
        Iterator end() { return Iterator{root}; } 

        struct Queue 
        {
            int start = 0, end = 0;
            inline void push(TrieNode *u) { preallocated_queue[end++] = u; }
            inline TrieNode *pop() { return preallocated_queue[start++]; }
            bool empty() { return start == end; }
        };
    };
};
