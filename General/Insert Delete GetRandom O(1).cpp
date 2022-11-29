class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool prst = false;
        if(mp.find(val) == mp.end()){
            mp[val] = v.size();
            v.push_back(val);
            prst = true;
        }
        return prst;
    }
    
    bool remove(int val) {
          bool prst = false;
        if(mp.find(val) != mp.end()){
            if(mp[val] == v.size()-1){
                v.pop_back();
            }
            else{
                int idx = mp[val];
                //Trick swap with the last element which we have to delete
                v[idx] = v[v.size()-1];
                mp[ v[v.size()-1] ] = idx;
                v.pop_back();
            }
            mp.erase(val);
            prst = true;
        }
        return prst;
        
    }
    
    int getRandom() {
        int max = v.size() - 1;
        int min = 0;
        int randNum = rand()%(max-min + 1) + min;
        return v[randNum];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
