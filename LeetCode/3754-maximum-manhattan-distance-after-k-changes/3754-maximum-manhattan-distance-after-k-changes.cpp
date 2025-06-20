class Solution {
public:
    int maxDistance(string moves, int changes) {
        int north = 0, south = 0, east = 0, west = 0;
        int maxDistance = 0;

        for (size_t i = 0; i < moves.size(); i++) {
            char direction = moves[i];
            if (direction == 'N') north++;
            else if (direction == 'S') south++;
            else if (direction == 'E') east++;
            else if (direction == 'W') west++;

            int currentDistance = abs(north - south) + abs(east - west) + 2 * changes;
            maxDistance = max(maxDistance, min(currentDistance, static_cast<int>(i + 1)));
        }

        return maxDistance;
    }
};