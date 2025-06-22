class Solution {
public:
    int minRefuelStops(int destination, int initialFuel, vector<vector<int>>& fuelStations) {
        int stationCount = fuelStations.size();
        int currentFuel = initialFuel, stationIndex = 0;
        int refuelCount = 0;

        priority_queue<int> availableFuel;

        while (currentFuel < destination) {
            while (stationIndex < stationCount && currentFuel >= fuelStations[stationIndex][0]) {
                availableFuel.push(fuelStations[stationIndex][1]);
                stationIndex++;
            }

            if (availableFuel.empty()) return -1;
            currentFuel += availableFuel.top();
            availableFuel.pop();
            refuelCount++;
        }

        return refuelCount;
    }
};