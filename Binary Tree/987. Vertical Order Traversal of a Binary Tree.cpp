class Solution {
public:

    int mostNegative = 0;
    bool reached = false;

    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        mostNegative = -(mostNegativee(root, 0)+1);
        vector<vector<vector<int>>> answer(mostNegative);
        vector<vector<int>> ans;

        cout << mostNegative;
        verticalTraversor(root, 0, answer, 0);

        for(int i = 0; i < answer.size(); i++)
        {
            vector<int> aux;
            for(int j = 0; j < answer[i].size(); j++)
            {
                sort(answer[i][j].begin(), answer[i][j].end());
                aux.insert(aux.end(), answer[i][j].begin(), answer[i][j].end());
            }
            ans.push_back(aux);
        }


        return ans;
    }

    void verticalTraversor(TreeNode* root, int col, vector<vector<vector<int>>>& ans, int rows)
    {
        if(root == NULL)
        {
            return;
        }

        verticalTraversor(root->left, col-1, ans, rows+1);

        if(ans.size() <= col + mostNegative)
        {
            vector<vector<int>> aux(rows + 1);
            aux[rows] = {root->val};
            ans.push_back(aux);
        }
        else
        {
            if(ans[mostNegative + col].size() <= rows)
            {
                for(int i = ans[mostNegative + col].size(); i <= rows; i++)
                {
                    ans[mostNegative + col].push_back({});
                }
            }

            ans[mostNegative + col][rows].push_back(root->val);
        }
        
        verticalTraversor(root->right, col+1, ans, rows+1);
    }

    int mostNegativee(TreeNode* root, int col)
    {
        if(root == NULL)
        {
            return col;
        }

        return min(mostNegativee(root->left, col - 1), mostNegativee(root->right, col + 1));
    }
};

// Optimized using STL:

vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map < int, map < int, multiset < int >>> nodes;
  queue < pair < TreeNode * , pair < int, int >>> todo;
  todo.push({
    root,
    {
      0,
      0
    }
  }); //initial vertical and level
  while (!todo.empty()) {
    auto p = todo.front();
    todo.pop();
    TreeNode * temp = p.first;

    //x -> vertical , y->level
    int x = p.second.first, y = p.second.second;
    nodes[x][y].insert(temp -> val); //inserting to multiset

    if (temp -> left) {
      todo.push({
        temp -> left,
        {
          x - 1,
          y + 1
        }
      });
    }
    if (temp -> right) {
      todo.push({
        temp -> right,
        {
          x + 1,
          y + 1
        }
      });
    }
  }
  vector < vector < int >> ans;
  for (auto p: nodes) {
    vector < int > col;
    for (auto q: p.second) {
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  return ans;
    }
