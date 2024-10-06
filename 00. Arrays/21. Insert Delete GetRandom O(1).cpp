
class RandomizedSet {
public:

    unordered_map<int,int>mp; // val & its index in arr;
    vector<int>arr; // stores values usefull for getRandom fun
    int index ;
    RandomizedSet() {
        arr.clear();
        mp.clear();
    }
    
    bool insert(int val) {

        if(mp.find(val) == mp.end()){
            arr.push_back(val);
            mp[val] = arr.size()-1;
            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()){
            return false;
        }

        int i = mp[val];
        swap(arr[i], arr[arr.size()-1]);
        arr.pop_back();
        mp.erase(val);

// If we swapped, update the map for the moved element edge case if only one element in mp is deleted then we should not rassign
        if(i < arr.size())
            mp[arr[i]] = i; 

        return true;
    }
    
    int getRandom() {
        int random_index = rand() % arr.size();
        return arr[random_index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */