class SummaryRanges {
    private:
    map<int, int> intervals;

    public:
    SummaryRanges() {}

    void addNum(int value) {
        auto right = intervals.upper_bound(value);
        auto left = right;
        bool hasLeft = (right != intervals.begin());
        if (hasLeft) {
            --left;
        }

        if (hasLeft && left->first <= value && value <= left->second) {
            return;
        }

        bool connectLeft = (hasLeft && left->second + 1 == value);
        bool connectRight = (right != intervals.end() && right->first == value + 1);

        if (connectLeft && connectRight) {
            left->second = right->second;
            intervals.erase(right);
        } else if (connectLeft) {
            left->second = value;
        } else if (connectRight) {
            int rightEnd = right->second;
            intervals.erase(right);
            intervals[value] = rightEnd;
        } else {
            intervals[value] = value;
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (const auto& [start, end] : intervals) {
            result.push_back({start, end});
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */