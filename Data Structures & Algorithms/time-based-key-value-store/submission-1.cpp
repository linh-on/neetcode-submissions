class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});    // [1, "string"]
    }

    string get(string key, int timestamp) {
        string result = "";
        if (!store.count(key)) return result;



        vector<pair<int, string>> & entries = store[key];

        int left = 0;
        int right = entries.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (entries[mid].first <= timestamp){
                result = entries[mid].second;
                left = mid + 1;
            } else {
                right = mid;
            }


        }
        return result;


        
    }
};
