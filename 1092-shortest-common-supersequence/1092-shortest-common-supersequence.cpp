class Solution {
public:
    string lcs(string str1,string str2,int n,int m){
        int t[n+1][m+1];
        for(int i=0;i<=n;i++){  // initialization
            for(int j=0;j<=m;j++ ){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(str1[i-1]==str2[j-1]){
                    
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        // yaha tak longest common subseuqence ban gya hai
        
       //-> // ab longest common subsequence jo hai usko nikalo 
        
        int i=n;int j=m;
        string s="";//empty string
        
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                s+=str1[i-1];
                i--;
                j--;
            }
            else{
                if(t[i-1][j]<t[i][j-1]){
                    s+=str2[j-1];
                    j--;
                }
                else{       
                    s+=str1[i-1];
                    i--;
                }
            }  
        }
        // ab longest common subsequence nikalne ke baad jo bacha hua hai dono me usko string me bhar do
        // aur uske baad return kar do string ko
        
        while(i>0){
             s+=str1[i-1];
             i--;
         } 
         while(j>0){
             s+=str2[j-1];
             j--;     
         }
         reverse(s.begin(),s.end());
        return s;
    }
// main function
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        
        return lcs(str1,str2,n,m);
    }
};