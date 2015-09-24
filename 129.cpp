/*
129. Rehashing

The size of the hash table is not determinate at the very beginning. If the total size of keys is too large (e.g. size >= capacity / 10), we should double the size of the hash table and rehash every keys. Say you have a hash table looks like below:
size=3, capacity=4
[null, 21, 14, null]
       ↓    ↓
       9   null
       ↓
      null


The hash function is:
int hashcode(int key, int capacity) {
    return key % capacity;
}


here we have three numbers, 9, 14 and 21, where 21 and 9 share the same position as they all have the same hashcode 1 (21 % 4 = 9 % 4 = 1). We store them in the hash table by linked list.
rehashing this hash table, double the capacity, you will get:
size=3, capacity=8
index:   0    1    2    3     4    5    6   7
hash : [null, 9, null, null, null, 21, 14, null]


Given the original hash table, return the new hash table after rehashing .
*/

// This problem is a bit unreasonable.
// Why must the nodes be appended to the end of the list?
/**
* Definition of ListNode
* class ListNode {
* public:
*     int val;
*     ListNode *next;
*     ListNode(int val) {
*         this->val = val;
*         this->next = NULL;
*     }
* }
*/
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */   
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        int n1 = hashTable.size();
        int n2 = n1 * 2;
        vector<ListNode *> ans(n2, NULL);
        vector<ListNode *> tail(n2, NULL);
        
        int i, j;
        ListNode *p, *q;
        for (i = 0; i < n1; ++i) {
            p = hashTable[i];
            while (p != NULL) {
                q = p->next;
                j = addr(p->val, n2);
               
                if (ans[j] == NULL) {
                    ans[j] = tail[j] = p;
                } else {
                    tail[j]->next = p;
                    tail[j] = p;
                }
                tail[j]->next = NULL;
               
                p = q;
            }
            hashTable[i] = NULL;
        }
        return ans;
    }
private:
    int addr(int val, int cap) {
        return val >= 0 ? val % cap : (val % cap + cap) % cap;
    }
};
