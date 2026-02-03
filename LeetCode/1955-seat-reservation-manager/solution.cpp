class SeatManager {
    set<int> seats;
public:
    SeatManager(int n) {
        for (int i=1; i<=n; i++) seats.insert(i);
    }
    
    int reserve() {
        auto it = seats.begin();
        int seat = *it;
        seats.erase(it);
        return seat;
    }
    
    void unreserve(int seatNumber) {
        seats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
