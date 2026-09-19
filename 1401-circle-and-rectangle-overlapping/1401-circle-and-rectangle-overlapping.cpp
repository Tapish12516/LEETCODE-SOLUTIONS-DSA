class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int clox = max(x1, min(xCenter , x2));
        int cloy = max(y1, min(yCenter , y2));
        int dx = xCenter - clox;
        int dy = yCenter - cloy;
        int disq = dx*dx + dy*dy;
        if(disq<=radius*radius) return true;
        return false;
    }
};