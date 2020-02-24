int sharedInterests(int friends_nodes, int friends_edges, std::vector<int> friends_from, std::vector<int> friends_to, std::vector<int> friends_weight) {
     map<int,vector<int>>mp;
    for(int i = 0; i < friends_edges; i++){
        mp[friends_from[i]].push_back(friends_weight[i]);
        mp[friends_to[i]].push_back(friends_weight[i]);
    }
    map<pair<int,int>,int>common;
    set<int>s;
    set<int>s1,s2;
    for(int i = 1; i <= friends_nodes; i++){
        for(int j = i+1; j <= friends_nodes; j++){
            
            for(int p = 0; p < mp[i].size(); p++){
                s1.insert(mp[i][p]);
                s.insert(mp[i][p]);
            }
            for(int p = 0; p < mp[j].size(); p++){
                s2.insert(mp[j][p]);
                s.insert(mp[j][p]);
            }
    
        
            common[make_pair(i,j)] = (s1.size()+s2.size()) - s.size();
            s1.clear();
            s2.clear();
            s.clear();
    }
    }
    int max=-1,max_value=-1;
    for(int i = 1; i <= friends_nodes; i++){
        for(int j = i+1; j <= friends_nodes; j++){
            if(common[make_pair(i,j)] == max ){
                if(max_value < i*j){
                    max_value = i*j;
                }
            }
            else if(common[make_pair(i,j)] > max ){
                max = common[make_pair(i,j)];
                max_value = i*j;
            }
            
        }
    }
    return max_value;

}
