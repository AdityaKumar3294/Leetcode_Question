/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { // TC : O(N+M+K) & SC : O(N+M+K)

        // N = length of l1
        // M = length of l2
        // K = length of the resulting linked list

        stack<int>sum;// SC : O(K)

        stack<int>list1;// SC : O(N)
        stack<int>list2;// SC : O(M)

        ListNode* h1 = l1;
        ListNode* h2 = l2;

        while(h1){// TC : O(N)
            list1.push(h1->val);
            h1 = h1->next;
        }

        while(h2){// TC : O(M)
            list2.push(h2->val);
            h2 = h2->next;
        }

        int carry = 0;

        while(!list1.empty() || !list2.empty()){// TC : O(max(N,M)) And since : O(max(N,M))⊆O(N+M) so TC : O(M+N)

            int val1 = 0;
            int val2 = 0;

            if(!list1.empty()){
                val1 = list1.top();
                list1.pop();
            }

            if(!list2.empty()){
                val2 = list2.top();
                list2.pop();
            }

            int add = val1+val2+carry;

            carry = add/10;

            sum.push(add%10);
        }

        if(carry != 0){
            sum.push(carry);
        }
        

        ListNode* head = new ListNode(-1);
        ListNode* curr = head;

        while(!sum.empty()){// TC : O(K) = O(max(M,N))
            curr->next = new ListNode(sum.top());
            sum.pop();

            curr = curr->next;
        }

        return head->next;
    }


    //while(!list1.empty() || !list2.empty())

    // The loop runs max(N, M) times because it continues
    // until both stacks become empty.
    //
    // max(N, M) <= N + M
    // Therefore, O(max(N, M)) can also be written as O(N + M).
    //
    // When N = M:
    // max(N, M) = N
    // N + M = 2N
    // Since constants are ignored in Big-O:
    // O(2N) = O(N)
    //
    // So:
    // O(max(N, M)) = O(N + M) when N = M.
};