// This requires the use of a stack and a map or an array (as I have used. Array can be used as a good substitute for map as maximum elements are 10000).

/*
  THING IS: How do we build this reasoning, how do we identify that these data structures are required here for most time-optimal solution?
  This is what is to be realized. Let's try to break this down.
  
  Supposing, n = nums1.size() and m = nums2.size() [following C++ syntax], we're to do this in O(n+m) time.
  That means one iteration of both arrays. Definitely, some data structures are required, you won't be able to think of any other way. Think of some time-efficient data structures
  to keep on your radar: Maps, Arrays, Stacks, Priority Queues etc. Avoiding logarithmic data structures, we're left with unordered map and
  stacks, so to speak.
  
  Try to devise a method to attain the result in single traversals. The first thing you'd think in a 2 vector situation is to simultaneously traverse both and 
  derive the results as we speed through. However, realize that again you can look from multiple ways to this, observe that nums1 is a subset of nums2. Say what if
  we traverse nums2 and find all results of all elements of nums2 first in O(m) time and then we simply need to map them to elements present in nums1 which can be done
  in O(n) time! Basically, find next greater elements of elements present in nums2 in O(1). Either use a map or an array to store the results to process nums1 in constant time per element.
  
  Now how do you process nums2 in (almost) constant time per element?
  
  Suppose nums2[4] = [1, 3, 4, 2]
  Now, you need to find greater element on the RIGHT(!). and in single traversal. So why don't we start from the right itself (reverse iteration)?!
  For 2, no elements exist on right so 2's next greater element = -1.
  For 4, we see no greater element, so -1.
  For 3, we see that 4 is that greater element.
  For 1, we see that 3 will do.
  
  Basically, you need information of nearest elements to do comparisons. A stack will do perfectly fine!
  
  If at any point, stack is empty then it means that no elements exist on right side that are greater, so do a -1.
  And as we traverse, we push elements into the stack. If stack's top isn't greater than current element, that element will not be required further and pop it.
  Then traverse and compute the results. Then just crop out the results required for nums1.
  
  The dressing of this question is amazingly good to lead you to mulitple wrong ways.
  
*/

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) // RUNTIME: 100%, SPACE: 95%
    {
        int array[10001];        // reduce time in searching, trading it for space.

        stack<int> stack;
        int s1 = nums1.size(), s2 = nums2.size();

        for(int i = s2-1; i >= 0; i--)
        {
            while(!stack.empty() && stack.top() < nums2[i])
            {
                stack.pop();
            }

            if(stack.empty())
            {
                array[nums2[i]] = -1;
            }
            else
            {
                array[nums2[i]] = stack.top();
            }
            stack.push(nums2[i]);
        }

        for(int i = 0; i < s1; i++)
        {
            nums1[i] = array[nums1[i]];
        }

        return nums1;

    }
