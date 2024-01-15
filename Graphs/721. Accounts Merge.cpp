class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adjacent;
    
    void DFS(vector<string>& mergedAccount, string& email) {
        visited.insert(email);
        // Add the email vector that contains the current component's emails
        mergedAccount.push_back(email);
        
        for (string& neighbor : adjacent[email]) {
            if (visited.find(neighbor) == visited.end()) {
                DFS(mergedAccount, neighbor);
            }
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) {
        int accountListSize = accountList.size();
        
         for (vector<string>& account : accountList) {
            int accountSize = account.size();
            
            // Building adjacency list
            // Adding edge between first email to all other emails in the account
            string accountFirstEmail = account[1];
            for (int j = 2; j < accountSize; j++) {
                string email = account[j];
                adjacent[accountFirstEmail].push_back(email);
                adjacent[email].push_back(accountFirstEmail);
            }
        }
        
        // Traverse over all th accounts to store components
        vector<vector<string>> mergedAccounts;
        for (vector<string>& account : accountList) {
            string accountName = account[0];
            string accountFirstEmail = account[1];
            
            // If email is visited, then it's a part of different component
            // Hence perform DFS only if email is not visited yet
            if (visited.find(accountFirstEmail) == visited.end()) {
                vector<string> mergedAccount;
                // Adding account name at the 0th index
                mergedAccount.push_back(accountName);
                DFS(mergedAccount, accountFirstEmail);
                // Skip the first element (name)
                // Name should be the first element, we only need to sort the emails
                sort(mergedAccount.begin() + 1, mergedAccount.end());
                mergedAccounts.push_back(mergedAccount);
            }
        }
        
        return mergedAccounts;
    }
};


// dsu:

class DSU {
public:
    vector<int> representative;
    vector<int> size;
    
    DSU(int sz) : representative(sz), size(sz) {
        for (int i = 0; i < sz; ++i) {
            // Initially each group is its own representative
            representative[i] = i;
            // Intialize the size of all groups to 1
            size[i] = 1;
        }
    }
    
    // Finds the representative of group x
    int findRepresentative(int x) {
        if (x == representative[x]) {
            return x;
        }
        
        // This is path compression
        return representative[x] = findRepresentative(representative[x]);
    }
    
    // Unite the group that contains "a" with the group that contains "b"
    void unionBySize(int a, int b) {
        int representativeA = findRepresentative(a);
        int representativeB = findRepresentative(b);
        
        // If nodes a and b already belong to the same group, do nothing.
        if (representativeA == representativeB) {
            return;
        }
        
        // Union by size: point the representative of the smaller
        // group to the representative of the larger group.
        if (size[representativeA] >= size[representativeB]) {
            size[representativeA] += size[representativeB];
            representative[representativeB] = representativeA;
        } else {
            size[representativeB] += size[representativeA];
            representative[representativeA] = representativeB;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) {
        int accountListSize = accountList.size();
        DSU dsu(accountListSize);
        
        // Maps email to their component index
        unordered_map<string, int> emailGroup;
        
        for (int i = 0; i < accountListSize; i++) {
            int accountSize = accountList[i].size();

            for (int j = 1; j < accountSize; j++) {
                string email = accountList[i][j];
                string accountName = accountList[i][0];
                
                // If this is the first time seeing this email then
                // assign component group as the account index
                if (emailGroup.find(email) == emailGroup.end()) {
                    emailGroup[email] = i;
                } else {
                    // If we have seen this email before then union this
                    // group with the previous group of the email
                    dsu.unionBySize(i, emailGroup[email]);
                }
            }
        }
    
        // Store emails corresponding to the component's representative
        unordered_map<int, vector<string>> components;
        for (auto emailIterator : emailGroup) {
            string email = emailIterator.first;
            int group = emailIterator.second;
            components[dsu.findRepresentative(group)].push_back(email);
        }

        // Sort the components and add the account name
        vector<vector<string>> mergedAccounts;
        for (auto componentIterator : components) {
            int group = componentIterator.first;
            vector<string> component = {accountList[group][0]};
            component.insert(component.end(), componentIterator.second.begin(), 
                             componentIterator.second.end());
            sort(component.begin() + 1, component.end());
            mergedAccounts.push_back(component);
        }
        
        return mergedAccounts;
    }
};
