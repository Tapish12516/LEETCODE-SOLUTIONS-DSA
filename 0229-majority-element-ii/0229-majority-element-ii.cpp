class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mapp;
        for(int number : nums){
            mapp[number]++;
        }
        vector<int> answer;
        int threshold = nums.size()/3;
        for (const auto& entry : mapp) {
            if (entry.second > threshold) {
                answer.push_back(entry.first);
            }
            if (answer.size() == 2) {
                break;
            }
        }
        return answer;
    }
};