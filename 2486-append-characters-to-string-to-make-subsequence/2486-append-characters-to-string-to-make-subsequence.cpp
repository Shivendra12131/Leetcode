class Solution {
public:
 int appendCharacters(string s, string t) {
    int m = s.size();
    int n = t.size();
  int i=0;
     int j=0;
     while(i<m)
     {
         if(s[i]==t[j])
         {
             i++;
             j++;
         }
         else{
             i++;
         }
     }
     return n-(j);
 }
};