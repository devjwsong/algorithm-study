#include <iostream>
#include <vector>

using namespace std;


/*
Prefix product + math.
If the number is 0, the product including the number is set to 0 consistently.
So we clear the vector and when we get access to the index which is out of bound,
that means we want to get the product 0.
The rest of idea is the similar with prefix sum.
Time: O(1) (add), O(1) (getProduct).
Space: O(k).
*/
class ProductOfNumbers {
public:
    vector<int> pProds;

    ProductOfNumbers() {
        pProds.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            pProds.clear();
            pProds.push_back(1);
        } else {
            pProds.push_back(pProds.back() * num);
        }
    }
    
    int getProduct(int k) {
        int len = pProds.size();
        if (len - 1 - k >= 0) {
            return pProds.back() / pProds[len-1-k];
        }

        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
