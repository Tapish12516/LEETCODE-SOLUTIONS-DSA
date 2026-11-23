class ProductOfNumbers {
public:
    vector<int> prefix;
    ProductOfNumbers() {
        prefix.push_back(1);
    }
    void add(int num) {
        if(num == 0) {
            prefix.clear();
            prefix.push_back(1);
        }
        else {
            int product = prefix.back() * num;
            prefix.push_back(product);
        }
    }
    int getProduct(int k) {
        if(k >= prefix.size())                                      //optimal soln , prfix product , O(1)
            return 0;
        return prefix.back() / prefix[prefix.size() - k - 1];
    }
};


// class ProductOfNumbers {
// public:
//     vector<int> arr;
//     ProductOfNumbers() {
//     }
//     void add(int num) {
//         arr.push_back(num);
//     }
//     int getProduct(int k) {
//         int product = 1;
//         int n = arr.size();
//         for(int i = n - 1; i >= n - k; i--) {           //bruteforce solution with TC O(K)
//             product *= arr[i];
//         }
//         return product;
//     }
// };

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */ 