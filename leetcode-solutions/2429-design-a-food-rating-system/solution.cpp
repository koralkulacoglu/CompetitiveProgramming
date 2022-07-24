class FoodRatings {
    string convert(string a) {
        for (int i=0; i<a.size(); i++) {
            a[i] = char('a' + ('z' - a[i]));
        }
        return a;
    }
    
    public:
    unordered_map<string, pair<int, string>> value;
    unordered_map<string, set<pair<int, string>>> menu;
    unordered_map<string, string> categories;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i=0; i<foods.size(); i++) {
            string val = convert(foods[i]);
            menu[cuisines[i]].insert(make_pair(ratings[i], val));
            categories[val] = cuisines[i];
            value[val] = make_pair(ratings[i], val);
        }
    }
    
    void changeRating(string val, int newRating) {
        val = convert(val);
        string cs = categories[val];
        menu[cs].erase(value[val]);
        menu[cs].insert(make_pair(newRating, val));
        value[val] = make_pair(newRating, val);
    }
    
    string highestRated(string cuisine) {
        auto it = menu[cuisine].end();
        it--;
        string val = (*it).second;
        val = convert(val);
        return val;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
