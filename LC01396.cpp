/*

https://leetcode.com/problems/design-underground-system/description/
Time Complexity: O(n)
Space Complexity: O(n)

*/


class UndergroundSystem {
public:

    unordered_map<int, pair<string, int>> in;
    unordered_map<string, pair<int, int>> route;
    unordered_map<string, int> station_id;
    UndergroundSystem() {
        station_id.clear();
        route.clear();
        in.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        if(station_id.count(stationName) == 0)
            station_id[stationName] = station_id.size();
            //cout<<station_id.size()<<endl;
        in[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        if(station_id.count(stationName) == 0)
            station_id[stationName] = station_id.size();
        int get_out_id = station_id[stationName];
        string get_in_name = in[id].first;
        //cout<<get_in_name<<endl;
        int get_in_time = in[id].second;
        int get_in_id = station_id[get_in_name];
        //cout<<get_in_id<<" "<<get_out_id<<endl;
        string r = get_in_name + "_" + stationName;
        if(route.count(r) == 0)
            route[r] = make_pair(t - get_in_time, 1);
        else
            {route[r].first+= t - get_in_time;
            route[r].second+=1;}
    }
    
    double getAverageTime(string startStation, string endStation) {
        int get_in_id = station_id[startStation];
        int get_out_id = station_id[endStation];
        //return avg_time[get_in_id][get_out_id];
        string r = startStation+"_"+endStation;
        return (double)(route[r].first) / (route[r].second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */