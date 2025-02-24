class RecentCounter {
    queue<int> qt;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        while(qt.size() > 0 && qt.front() < t-3000) qt.pop();
        qt.push(t);
        return qt.size();
    }
};