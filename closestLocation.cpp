#include<bits/stdc++.h>
using namespace std;

vector<bool> isPrefix(std::string address,std::vector<std::string>names){
    vector<bool> isprefix;
    bool flag = true;
    for(int i = 0; i < names.size(); i++){
        if(names[i].size() < address.size()){
            flag = false;
            break;
        }
        for(int j = 0; j < names[i].size(), j < address.size(); j++){
            if(address[j] != names[i][j]){
                flag = false;
                break;
            }
        }
        isprefix.push_back(flag);
        
    }
    return isprefix;
    
}
vector<bool> differ_by_one_symbol(std::string address,std::vector<std::string>names){
    vector<bool> isdiffer_by_one_symbol;
    bool flag = true;
    int differ = 0;
    for(int i = 0; i < names.size(); i++){
        if(names[i].size() < address.size()){
            flag = false;
            break;
        }
        for(int j = 0; j < names[i].size(), j < address.size(); j++){
            if(address[j] != names[i][j]){
               differ++;
            }
        }
        if(differ > 1 && flag)
        isdiffer_by_one_symbol.push_back(false);
        else
             isdiffer_by_one_symbol.push_back(true);
        
    }
    return  isdiffer_by_one_symbol;
    
    
    
}
vector<bool> Extra_one_symbol(std::string address,std::vector<std::string>names){
    vector<bool> extra_one_symbol;
    bool flag = true,jump = false;
    for(int i = 0; i < names.size(); i++){
        if(names[i].size() < address.size()){
            flag = false;
            break;
        }
        int k = 0;
        for(int j = 0; j < names[i].size(), k < address.size(); j++,k++){
            if(address[k] != names[i][j]){
                if(!jump){
                    jump = true;
                    k--;
                }
                else{
                flag = false;
                break;
                }
            }
            
        }
        extra_one_symbol.push_back(flag);
        
    }
    return extra_one_symbol;
    
}
vector<bool> Has_one_missing_symbol(std::string address,std::vector<std::string>names){
    vector<bool> has_one_missing_symbol;
    bool flag = true;
    for(int i = 0; i < names.size(); i++){
        if(names[i].size() < address.size()-1){
            flag = false;
            break;
        }
        int k = 1;
        for(int j = 0; j < names[i].size(), k < address.size(); j++,k++){
            if(address[k] != names[i][j]){
                flag = false;
                break;
            }
        }
        has_one_missing_symbol.push_back(flag);
        
    }
    return has_one_missing_symbol;
    
}

vector<int> distances(std::vector<std::vector<int>> objects){
    vector<int>rdis;
    for(int i = 0; i < objects.size(); i++){
        if(objects[i].size() == 2){
            rdis.push_back(sqrt(objects[i][0]*objects[i][0] + objects[i][1]*objects[i][1]));
        }
        else{
            if(objects[i][0] > 0 && objects[i][1] > 0 && objects[i][2] > 0 && objects[i][3] > 0 ){
                if(objects[i][1] > objects[i][3]){
                    rdis.push_back(sqrt(objects[i][0]*objects[i][0] + objects[i][1]*objects[i][1] ));
                }
                else{
                    rdis.push_back(sqrt(objects[i][2]*objects[i][2] + objects[i][3]*objects[i][3] ));
                }
            }
            else if(objects[i][0] < 0 && objects[i][1] < 0 && objects[i][2] < 0 && objects[i][3] < 0 ){
                if(objects[i][1] > objects[i][3]){
                    rdis.push_back(sqrt(objects[i][0]*objects[i][0] + objects[i][1]*objects[i][1] ));
                }
                else{
                    rdis.push_back(sqrt(objects[i][2]*objects[i][2] + objects[i][3]*objects[i][3] ));
                }
            }
            else if(objects[i][0] < 0 && objects[i][1] > 0 && objects[i][2] < 0 && objects[i][3] > 0 ){
                if(objects[i][1] > objects[i][3]){
                    rdis.push_back(sqrt(objects[i][0]*objects[i][0] + objects[i][1]*objects[i][1] ));
                }
                else{
                    rdis.push_back(sqrt(objects[i][2]*objects[i][2] + objects[i][3]*objects[i][3] ));
                }
            }
            else if(objects[i][0] > 0 && objects[i][1] < 0 && objects[i][2] > 0 && objects[i][3] < 0 ){
                if(objects[i][1] > objects[i][3]){
                    rdis.push_back(sqrt(objects[i][0]*objects[i][0] + objects[i][1]*objects[i][1] ));
                }
                else{
                    rdis.push_back(sqrt(objects[i][2]*objects[i][2] + objects[i][3]*objects[i][3] ));
                }
            }
            else if(objects[i][0] == objects[i][2] ){
                
                    rdis.push_back(objects[i][0]);
                
                
            }
            else
                rdis.push_back(objects[i][1]);
        }
    }
    return rdis;
    
}

std::string closestLocation(std::string address, std::vector<std::vector<int>> objects, std::vector<std::string> names) {
   



    vector<bool> isprefix,isdiffer_by_one_symbol,extra_one_symbol,has_one_missing_symbol,istrue;
    vector<int> rdis;
    isprefix = isPrefix(address,names);
    isdiffer_by_one_symbol = differ_by_one_symbol(address,names);
    extra_one_symbol = Extra_one_symbol(address,names);
    has_one_missing_symbol = Has_one_missing_symbol(address,names);
    rdis = distances(objects);
    for(int i = 0; i < isprefix.size();i++){
        istrue.push_back(isprefix[i] || isdiffer_by_one_symbol[i] || extra_one_symbol[i] || has_one_missing_symbol[i]);
        
    }
    int min = 999999, index;
    for(int i = 0; i < istrue.size(); i++){
        if(istrue[i] && rdis[i] < min){
            min = rdis[i];
            index = i;
        }
    }
    return names[index];

}

int main(){
   
 std::  cout<<closestLocation("Location",{{5,-10,5,10},{3,3}},{"loocationnnn","lcationaaaa"});



    return 0;
}