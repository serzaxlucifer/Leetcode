// My 1st implementation:

/*


  What leverage can I take of the problem statement? Notice that the given lists are sorted. I can
  choose a list and append all other lists into it. Say I choose lists[0] to add other lists to. And let's add lists[1] elements.
  Start iterating lists[0] and find a suitable position for first element of lists[1]. Then, for second element of lists[1],
  you don't need to start traversing lists[0] from start, as the second element is greater than first.
  
  So the position for 2nd element will be farther than where we placed the first, so simply continue iterating lists[0] and add the entire
  list. Then for lists[2] same procedure, start at beginning of lists[0].... then same for lists[3], lists[4], ... lists[k].
  
  SPACECOMPLEXITY:   O(1)
  TIME COMPLEXITY:   Assuming there are 'n' elements in each list and there are 'k' lists, we iterate each list to add them --> O((k-1)n) and for each list, 
                     we also iterate the main list again so (k-1)*n.
                     
                     Adding, we obtain O(2kn) = O(kn)
  
  
*/

// I swear to god It took me a day to handle cases and debug this code... but worth it I guess :(
// Didn't even have the dream tonight I wished for with a special someone who doesn't know... sad.
// DUHHHH RUNTIME : 25% at 138ms 

ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.empty())
        {
            return NULL;
        }

        ListNode* aux = lists[0];
        ListNode* temp, *temp2;

        int i = 0;
        int num;
        for(auto m : lists)
        {
            i++;
            if(m)       // find the first list that isn't empty!
            {
                aux = m;
                temp = temp2 = m;
                break;
            }
        }

        int count = 0;
        
        
        for(auto k : lists)
        {
            count++;
            if(count == i)
            {
                continue;
            }

            for(;k != NULL ;)
            {
                num = k->val;
                for(;;)
                {

                    if(temp == NULL)                // if adding at the end of list
                    {
                        ListNode* add = new ListNode;
                        add->val = num;
                        add->next = NULL;
                        temp2->next = add;
                        temp2 = add;
                        break;
                    }
                    if(temp->val > num)
                    {

                        ListNode* add = new ListNode;
                        add->val = num;

                        if(temp == temp2)           // if to add at beginning
                        {
                            lists[0] = aux = add;
                            add->next = temp;
                            temp2 = add;
                            break;
                        }

                        temp2->next = add;
                        (add)->next = temp;
                        temp2 = add;
                        break;
                    }
                    
                    temp2 = temp;
                    temp = (temp)->next;
                }
                
                k = k->next;
            }
            temp = temp2 = aux;
        }
        
        return aux;
    }

// https://leetcode.com/problems/merge-k-sorted-lists/editorial/ (also see approach 2 in O(kN) time.)

/*

  Let's talk of optimizing it further. To O(nlogk). Tough task, eh? Yeah, im' tired i wanna be spiderman. :(
  
  It appears that you either gotta use a priority queue or Divide and Conquer to achieve runtimes of near 20ms.
  No wonder, it is a hard problem.
  
*/
  

// Priority Queue Implementation: 

class compare{
        public:
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
    };
class Solution {
public:

    


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        ListNode* head= new ListNode();
        ListNode* tail= head;
        if(lists.size()==0){
            return NULL;
        }
        for(int i=0;i<lists.size();i++){

            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
        }


        while(!pq.empty()){

            ListNode* temp=pq.top();
            cout<<temp->val<<" ";
            ListNode* temp1= new ListNode(temp->val);
            tail->next=temp1;
            tail=temp1;
            pq.pop();

            if(temp->next!=NULL){
                pq.push(temp->next);
            }

        }

        head=head->next;

        return head;

    }


// Divide and Conquer Implementation: (Runtime: 11ms)

ListNode* mergeKLists(vector<ListNode*>& lists)
    {

        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        if(lists.empty())
        {
            return NULL;
        }

        int interval = 1;
        int listss = lists.size();            // how many linked lists?

        while(interval < listss)
        {
            for(int i = 0; i < listss - interval; i += interval*2)
            {
                lists[i] = merge2Lists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }

        return lists[0];

    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    {
        ListNode* merged = new ListNode(0);
        ListNode* current = merged;

        while(l1 && l2)
        {
            if(l1->val > l2->val)                  /* insert here any comment */
            {
                current->next = l2;
                current = l2;
                l2 = l2->next;
            }
            else
            {
                current->next = l1;
                current = l1;
                l1 = l1->next;
            }
        }

        while(l1)
        {
            current->next = l1;
            current = l1;
            l1 = l1->next;
        }
        while(l2)
        {
            current->next = l2;
            current = l2;
            l2 = l2->next;
        }

        return merged->next;
    }
