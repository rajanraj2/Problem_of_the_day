// https://leetcode.com/problems/product-of-the-last-k-numbers/description/
// 1352. Product of the Last K Numbers


class ProductOfNumbers {
    public:
        vector<int> arr;
        int s = 0;
    
        ProductOfNumbers() {
            arr.push_back(1);
            s = 0;
        }
    
        void add(int num) {
            if (num == 0) {
                arr = {1};
                s = 0;
            }
            else {
                arr.push_back(arr[s] * num);
                s++;
            }
        }
        
        int getProduct(int k) {
            if (k > s) return 0;
            return arr[s] / arr[s - k];
        }
    };
    
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */