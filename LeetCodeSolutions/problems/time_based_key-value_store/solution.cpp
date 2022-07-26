// Uploaded from ahmed-mobile

class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) 
    {
        // if key does not exist in map create a key with a new vector
        valueTimestampMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) 
    {
        // base case -- key not found
        if (valueTimestampMap.find(key) == valueTimestampMap.end())
        {
            return "";
        }
        
        // since timestamp always ascending -- Binary search
        int low = 0;
        int high = valueTimestampMap[key].size() - 1;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int currentTimestamp = valueTimestampMap[key][mid].second;
            std::string currentValue = valueTimestampMap[key][mid].first;
            if (timestamp > currentTimestamp)
            {
                low = mid + 1;
            } else if (timestamp < currentTimestamp)
            {
                high = mid - 1;
            } else 
            {
                return currentValue;
            }   
        }
        if (high >= 0)
        {
            return valueTimestampMap[key][high].first;
        }
        return "";
    }
private:
    unordered_map<string, vector<pair<string, int>>> valueTimestampMap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */