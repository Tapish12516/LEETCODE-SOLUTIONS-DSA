class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;                          //empty fncs return 1 when array is empty
    int k =1;
    for(int i =1 ; i<nums.size() ; i++){
        if(nums[i] != nums[i-1]){                       //TC = O(N)
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
    }
};


    // int i = 0 ;
    // while(i < nums.size()-1){
    //     if (nums[i] == nums[i+1]) 
    //         nums.erase(nums.begin()+i);
    //     else i++;                         // this doesn't allows i to increase when the third element is same  (repetitive ex: 1 1 1)
    // }                                     // TC = O(N) but when WORST case when all elements are same then O(N^2)
    // return nums.size() ; 

    // 5/10 approach , fails for the larger size array and larger values 