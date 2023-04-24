class Solution {
public:
    vector<string> generateParenthesis(int n) {
       
     set<string>Ansset;
     string t = "()";
     Ansset.insert(t);
     
     for(int i=2;i<=n;i++){

       set<string>New_set;
      for (auto itr : Ansset){
      //  for(int j= Ansset.begin() ; j!=Ansset.end();j++){
          
          string z = itr;

              for(int k=0;k<z.length();k++){
                     string r = itr;
                     string s = "()" ;
                   
                     r.insert(k, s);
                     New_set.insert(r);
                  }
              }
              Ansset=New_set;
     
       }
         vector<string>vect;
    for (auto itr : Ansset){
      vect.push_back(itr);
   }


         return vect;

    }
 
};