class MovieRentingSystem {
    unordered_map<int, set<pair<int, int>>> unrentedMovieMap; // movie -> {price, shop}, ... 
    map<pair<int, int>, pair<int, int>> movieShopMap; // {movie, shop} -> {rented, price}
    set<vector<int>> rentedSet; // {price, shop, movie}

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        unrentedMovieMap.clear();
        movieShopMap.clear();
        rentedSet.clear();
        for (vector<int>& i : entries) {
            int shop = i[0];
            int movie = i[1];
            int price = i[2];
            unrentedMovieMap[movie].insert({price, shop});
            movieShopMap[{movie, shop}] = {false, price};
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        for (auto i : unrentedMovieMap[movie]) {
            if (res.size() == 5) break;
            res.push_back(i.second);
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = movieShopMap[{movie, shop}].second;
        unrentedMovieMap[movie].erase({price, shop});
        movieShopMap[{movie, shop}] = {true, price};
        rentedSet.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = movieShopMap[{movie, shop}].second;
        unrentedMovieMap[movie].insert({price, shop});
        movieShopMap[{movie, shop}] = {false, price};
        rentedSet.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto i : rentedSet) {
            if (res.size() == 5) break;
            int shop = i[1];
            int movie = i[2];
            res.push_back({shop, movie});
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
