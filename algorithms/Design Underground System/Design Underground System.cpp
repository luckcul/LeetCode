class UndergroundSystem {
    unordered_map<string, int>  tour_sum; 
    unordered_map<string, int>  tour_cnt; 
    unordered_map<int, string> check_in_s; 
    unordered_map<int, int> check_in_t; 
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        // string key = stationName+ std::to_string(id); 
        check_in_t[id] = t; 
        check_in_s[id] = stationName; 
        
    }
    
    void checkOut(int id, string stationName, int t) {
        string station = check_in_s[id]; 
        int in_t = check_in_t[id]; 
        string key = station + "_" + stationName; 
        // cout<<key<<", "<<t-in_t<<endl;
        if(tour_sum.find(key) == tour_sum.end()) {
            tour_sum[key] = t - in_t; 
            tour_cnt[key] = 1; 
        }
        else {
            tour_sum[key] += t-in_t; 
            tour_cnt[key] += 1; 
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation+"_"+endStation; 
        if(tour_sum.find(key) == tour_sum.end()) {
            return 0.0; 
        }
        else {
            return 1.0*tour_sum[key] / tour_cnt[key]; 
        }
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */