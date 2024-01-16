class RandomizedSet {
public:
    vector<int>elements;
    unordered_map<int,int>isAvaialble;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(isAvaialble.find(val)!=isAvaialble.end()){
            return false;
        }
        else{
            elements.push_back(val);
            int position=elements.size()-1;
            isAvaialble[val]=position;
            return true;
        }
    }
    
    bool remove(int val) {
        if(isAvaialble.find(val)==isAvaialble.end()){
            return false;
        }
        else{
            int oldPosition = isAvaialble[val]; 
            int lastPositon=elements.size()-1;
            int newVal=elements[lastPositon];
            elements[oldPosition]=newVal;
            elements.pop_back();
            isAvaialble[newVal]=oldPosition;
            isAvaialble.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int curr_size=elements.size();
        int position = rand()%curr_size;
        return elements[position];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
