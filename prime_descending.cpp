#include<bits/stdc++.h>
#include<iostream>
using namespace std;


bool isPrime(int num){
	bool prime = true;
	for(int i = 2; i <= sqrt(num); i++){
		if(num % i == 0){
			prime = false;
			break;
		}
	}
	return prime;
}

bool greaterP(int a, int b){
	return a > b;
}


int main(){
	std::vector<int> v;
	map<int,int>mp;
	int num,t;
	cin>>t;
	for(int i = 0; i < t; i++){
		cin>>num;
		if(isPrime(num)){
			v.push_back(num);
			mp[num] += 1;

		}
	}

	sort(v.begin(), v.end(),greaterP);
	for(auto it = v.begin(); it != v.end(); it++){
		cout<<"Number: "<<(*it)<<" count:"<<mp[*it]<<endl;
	}
return 0;

}