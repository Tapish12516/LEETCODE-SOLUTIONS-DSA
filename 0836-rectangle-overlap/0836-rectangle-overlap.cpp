class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];
        int x12 = rec2[0];
        int y12 = rec2[1];
        int x22 = rec2[2];
        int y22 = rec2[3];
        return x1 < x22 && x12 < x2 && y1 < y22 && y12 < y2;
    }
};