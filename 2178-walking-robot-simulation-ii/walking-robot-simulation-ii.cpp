class Robot {
    int w, h, p;
    bool moved;
public:
    Robot(int width, int height) {
        w = width;
        h = height;
        p = 0;
        moved = false;
    }
    
    void step(int num) {
        moved = true;
        p = (p + num) % (2 * (w - 1) + 2 * (h - 1));
    }
    
    vector<int> getPos() {
        if (p == 0) return {0, 0};
        if (p <= w - 1) return {p, 0};
        if (p <= w - 1 + h - 1) return {w - 1, p - (w - 1)};
        if (p <= 2 * w - 2 + h - 1) return {w - 1 - (p - (w - 1 + h - 1)), h - 1};
        return {0, h - 1 - (p - (2 * w - 2 + h - 1))};
    }
    
    string getDir() {
        if (p == 0) return moved ? "South" : "East";
        if (p <= w - 1) return "East";
        if (p <= w - 1 + h - 1) return "North";
        if (p <= 2 * w - 2 + h - 1) return "West";
        return "South";
    }
};