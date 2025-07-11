class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> roomEndTimes(n, 0);
        vector<int> roomUsage(n, 0);
        sort(meetings.begin(), meetings.end());

        for (auto& m : meetings) {
            int begin = m[0], finish = m[1];
            long long earliestAvailable = LLONG_MAX;
            int earliestRoom = 0;
            bool roomFound = false;

            for (int i = 0; i < n; i++) {
                if (roomEndTimes[i] <= begin) {
                    roomFound = true;
                    roomUsage[i]++;
                    roomEndTimes[i] = finish;
                    break;
                }
                if (earliestAvailable > roomEndTimes[i]) {
                    earliestAvailable = roomEndTimes[i];
                    earliestRoom = i;
                }
            }

            if (!roomFound) {
                roomEndTimes[earliestRoom] += finish - begin;
                roomUsage[earliestRoom]++;
            }
        }

        int maxMeetings = 0, maxRoom = 0;
        for (int i = 0; i < n; i++) {
            if (roomUsage[i] > maxMeetings) {
                maxMeetings = roomUsage[i];
                maxRoom = i;
            }
        }
        return maxRoom;
    }
};