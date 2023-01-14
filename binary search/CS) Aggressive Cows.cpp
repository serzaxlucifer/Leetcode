bool canYouFit(vector<int>& arr, int k, int mid)
{
    int lastPos = arr[0];
    int cowsFitted = 1;        // at starting!
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] - lastPos >= mid)
        {
            cowsFitted ++;
            if(cowsFitted == k)
            {
                return true;
            }
            lastPos = arr[i];        // where the last cow is fit?
         }
         
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your comd here.
    sort(stalls.begin(), stalls.end());
    
    int max = stalls[stalls.size()-1];
    
    int start = 0;
    int end = max;        // search space = [0, max]
    
    int mid = (start + end)/2;        // is mid the answer? let's find out!
    int answer = -1;
    
    while(start <= end)
    {
        if(canYouFit(stalls, k, mid))
        {
            answer = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start+end)/2;
    }
    
    return answer;
}
