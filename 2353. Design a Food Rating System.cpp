class FoodRatings {
public:
    map<string,string>foodToPlace; 
    map<string,int>foodToRating;
    map<string,set<pair<int,string>>>placeToRating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            foodToPlace[foods[i]]=cuisines[i];
            foodToRating[foods[i]]=ratings[i];
            placeToRating[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        placeToRating[foodToPlace[food]].erase({-foodToRating[food], food});
        foodToRating[food]=newRating;
        placeToRating[foodToPlace[food]].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto it =  *(placeToRating[cuisine].begin());
        return it.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
