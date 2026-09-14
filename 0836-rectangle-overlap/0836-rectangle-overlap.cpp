class Solution {
public:
    bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
        
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
        
        bool is_left = x4 <= x1;
        bool is_right = x3 >= x2;
        bool is_below = y4 <= y1;
        bool is_above = y3 >= y2;
        
        return !(is_left || is_right || is_below || is_above);
    }
};