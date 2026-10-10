class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> survivors;
        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                survivors.push_back(asteroid);
            } else {
                int currentSize = abs(asteroid);
                bool destroyed = false;
                    while (!survivors.empty() && survivors.back() > 0) {
                    int topSize = abs(survivors.back());
                    if (topSize < currentSize) {
                        survivors.pop_back();
                    } else {
                        if (topSize == currentSize) {
                            survivors.pop_back();
                        } 
                        destroyed = true;
                        break;
                    }
                }
                if (!destroyed) {
                    survivors.push_back(asteroid);
                }
            }
        } 
        return survivors;
    }
};