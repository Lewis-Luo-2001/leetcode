class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> hash;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<string, int> p({value, timestamp});

        hash[key].push_back(p);
    }
    
    string get(string key, int timestamp) {
        string result = "";
        
        int left = 0, right = hash[key].size() - 1, mid;
        while(left <= right) {
            mid = (left + right) / 2;
            
            if(hash[key][mid].second <= timestamp) {
                result = hash[key][mid].first;
                left = mid + 1;
            }
            else { 
                right = mid - 1;
            }
        }

        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */