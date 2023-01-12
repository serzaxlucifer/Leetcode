int containsDuplicate(vector<int>& prices) {
        
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unordered_set<int> map;

    for(int i : prices)
    {
        if(!map.insert(i).second) return true;
    }
    return false;
       
    }
