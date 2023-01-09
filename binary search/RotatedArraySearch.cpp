// My Solution:



/*
1st Solution:
class Solution {
public:
    int search(int A[], int n, int target) {
        int lo=0,hi=n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(A[mid]>A[hi]) lo=mid+1;
            else hi=mid;
        }
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=n-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};

2nd Solution:
public class Solution {
public int search(int[] nums, int target) {
    int start = 0, end = nums.length - 1;
    while (start < end) {
        int mid = (start + end) / 2;
        if (nums[mid] > nums[end]) {  // eg. 3,4,5,6,1,2
            if (target > nums[mid] || target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        } else {  // eg. 5,6,1,2,3,4
            if (target > nums[mid] && target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
    }
    if (start == end && target != nums[start]) return -1;
    return start;
}
}
*/
