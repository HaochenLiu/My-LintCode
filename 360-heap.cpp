class HHeapMin {
private:
    int A[5001];
    int __size;

public:
    HHeapMin() {
        memset(A, 0, sizeof(A));
        __size = 0;
    }
	
    void check() {
        cout<<"size: "<<__size<<endl;
        cout<<"[";
        for(int i = 0; i < __size - 1; i++) {
            cout<<A[i]<<", ";
        }
        cout<<A[__size - 1]<<"]"<<endl;
    }
	
    int size() {
        return __size;
    }

    void push(int n) {
        A[__size] = n;
        __size++;
        int i = __size - 1;
        while(i > 0) {
            int j = (i - 1) / 2;
            if(A[j] > A[i]) {
                swap(A[j], A[i]);
                i = j;
            } else {
                break;
            }
        }
        return;
    }
    
    int top() {
        return A[0];
    }
    
    void pop() {
        A[0] = A[__size - 1];
        __size--;
        int i = 0;
        while(2 * i + 1 < __size) {
            int minIdx = i;
            if(A[2 * i + 1] < A[minIdx]) {
                minIdx = 2 * i + 1;
            }
            if(2 * i + 2 < __size && A[2 * i + 2] < A[minIdx]) {
                minIdx = 2 * i + 2;
            }
            if(minIdx == i) {
                break;
            }
            swap(A[i], A[minIdx]);
            i = minIdx;
        }
        return;
    }
    
    void erase(int n) {
        if(__size == 0) return;
        int i;
        for(i = 0; i < __size; i++) {
            if(A[i] == n) {
                break;
            }
        }
        if(i == __size) {
            return;
        }
        if(A[__size - 1] == n) {
            __size--;
            return;
        } else if(A[__size - 1] > n) {
            A[i] = A[__size - 1];
            __size--;
            while(2 * i + 1 < __size) {
                int minIdx = i;
                if(A[2 * i + 1] < A[minIdx]) {
                    minIdx = 2 * i + 1;
                }
                if(2 * i + 2 < __size && A[2 * i + 2] < A[minIdx]) {
                    minIdx = 2 * i + 2;
                }
                if(minIdx == i) {
                    break;
                }
                swap(A[i], A[minIdx]);
                i = minIdx;
            }
            return;
        } else {
            A[i] = A[__size - 1];
            __size--;
            while(i > 0) {
                int j = (i - 1) / 2;
                if(A[j] > A[i]) {
                    swap(A[j], A[i]);
                    i = j;
                } else {
                    break;
                }
            }
            return; 
        }
    }
    
    bool find(int n) {
        if(__size == 0 || n < A[0]) return false;
        for(int i = 0; i < __size; i++) {
            if(A[i] == n) {
                return true;
            }
        }
        return false;
    }
};

class HHeapMax {
private:
    int A[5001];
    int __size;

public:
    HHeapMax() {
        memset(A, 0, sizeof(A));
        __size = 0;
    }

	
    void check() {
        cout<<"size: "<<__size<<endl;
        cout<<"[";
        for(int i = 0; i < __size - 1; i++) {
            cout<<A[i]<<", ";
        }
        cout<<A[__size - 1]<<"]"<<endl;
    }
	
    int size() {
        return __size;
    }

    void push(int n) {
        A[__size] = n;
        __size++;
        int i = __size - 1;
        while(i > 0) {
            int j = (i - 1) / 2;
            if(A[j] < A[i]) {
                swap(A[j], A[i]);
                i = j;
            } else {
                break;
            }
        }
        return;
    }
    
    int top() {
        return A[0];
    }
    
    void pop() {
        A[0] = A[__size - 1];
        __size--;
        int i = 0;
        while(2 * i + 1 < __size) {
            int maxIdx = i;
            if(A[2 * i + 1] > A[maxIdx]) {
                maxIdx = 2 * i + 1;
            }
            if(2 * i + 2 < __size && A[2 * i + 2] > A[maxIdx]) {
                maxIdx = 2 * i + 2;
            }
            if(maxIdx == i) {
                break;
            }
            swap(A[i], A[maxIdx]);
            i = maxIdx;
        }
        return;
    }

    void erase(int n) {
        if(__size == 0) return;
        int i;
        for(i = 0; i < __size; i++) {
            if(A[i] == n) {
                break;
            }
        }
        if(i == __size) {
            return;
        }
        if(A[__size - 1] == n) {
            __size--;
            return;
        } else if(A[__size - 1] < n) {
            A[i] = A[__size - 1];
            __size--;
            while(2 * i + 1 < __size) {
                int maxIdx = i;
                if(A[2 * i + 1] > A[maxIdx]) {
                    maxIdx = 2 * i + 1;
                }
                if(2 * i + 2 < __size && A[2 * i + 2] > A[maxIdx]) {
                    maxIdx = 2 * i + 2;
                }
                if(maxIdx == i) {
                    break;
                }
                swap(A[i], A[maxIdx]);
                i = maxIdx;
            }
            return;
        } else {
            A[i] = A[__size - 1];
            __size--;
            while(i > 0) {
                int j = (i - 1) / 2;
                if(A[j] < A[i]) {
                    swap(A[j], A[i]);
                    i = j;
                } else {
                    break;
                }
            }
            return; 
        }
    }
    
    bool find(int n) {
        if(__size == 0 || n > A[0]) return false;
        for(int i = 0; i < __size; i++) {
            if(A[i] == n) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        HHeapMax small;
        HHeapMin large;
        vector<int> res;
        int n = nums.size();
        if(n < 1 || k < 1 || n < k) return res;
        if(k == 1) return nums;
        small.push(INT_MIN);
        large.push(INT_MAX);

        for(int i = 0; i < n; i++) {
            if(i >= k) {
                int toDelete = nums[i - k];
                if(large.find(toDelete)) {
                    large.erase(toDelete);
                    if(small.size() > large.size() + 1) {
                        large.push(small.top());
                        small.pop();
                    }
                } else {
                    small.erase(toDelete);
                    if(large.size() > small.size()) {
                        small.push(large.top());
                        large.pop();
                    }
                }
            }
            
            if(nums[i] <= small.top()) {
                small.push(nums[i]);
                if(small.size() > large.size() + 1) {
                    large.push(small.top());
                    small.pop();
                }
            } else {
                large.push(nums[i]);
                if(large.size() > small.size()) {
                    small.push(large.top());
                    large.pop();
                }
            }
            
            if(i >= k - 1) {
                res.push_back(small.top());
            }
        }
        return res;
    }
};
