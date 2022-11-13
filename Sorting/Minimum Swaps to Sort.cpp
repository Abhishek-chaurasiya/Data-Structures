//Given array find Minimum number of moves to sort the array
//Case 1 - WHEN ALL ELEMENTS ARE DISTINCT
//THE LOGIC IS SIMPLE WE BASICALLY HAVE TO TRANSFORM THE SORTED ARRAY TO THE NUMS ARRAY GOING IN BACKWARD DIRECTION
//EX-NUMS=[17,11,3,15]
//TMP=[3,11,15,17]
int minSwaps(vector<int>&nums)
	{
	    std::map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        vector<int> tmp=nums;
        sort(tmp.begin(),tmp.end());



          int ope=0;
        
          for(int i=0;i<nums.size();i++){
            while(mp[tmp[i]]!=i){
              int org=tmp[i];
              int index=mp[tmp[i]];
              tmp[i]=tmp[index];
              tmp[index]=org;
              //swap(tmp[i],mp[tmp[i]]);
             
              ope++;
            }
          }
          return ope;
	}

////second code
int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>> hash(nums.size());
       for(int i=0;i<nums.size();i++)hash[i]={nums[i],i};
    
      sort(hash.begin(),hash.end());
      
    
      int swapcnt=0 ,i=0;
      while(i<nums.size()){
    
        if(hash[i].first==nums[i] && hash[i].second==i){
          i++; 
          continue;
        }
       
        swap(hash[i].first,hash[hash[i].second].first);
        swap(hash[i].second,hash[hash[i].second].second);
       //debug(hash);
        if(hash[i].second!=i)i--;
        
        i++;
        swapcnt++;  
    
    
      }
      return swapcnt;
	}


