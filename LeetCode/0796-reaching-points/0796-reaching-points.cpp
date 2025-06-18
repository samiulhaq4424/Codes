class Solution {
public:
    bool reachingPoints(int startX, int startY, int targetX, int targetY) {
        while (startX < targetX && startY < targetY) {
            if (targetX < targetY) {
                targetY %= targetX;
            } else {
                targetX %= targetY;
            }
        }
        return (startX == targetX && startY <= targetY && (targetY - startY) % startX == 0) ||
               (startY == targetY && startX <= targetX && (targetX - startX) % startY == 0);
    }
};