
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        
        if(s1.length() > s2.length()){
            return false;
        }
        
        int[] mp1 = new int[26];
        int[] mp2 = new int[26];

        int left = 0;
        int right = 0;
        while(right<s1.length()){
            mp1[s1.charAt(right)-'a']+=1;
            mp2[s2.charAt(right)-'a']+=1;
            right+=1;
        }
        right-=1; // to point to end t
        
        while(right<s2.length()){
            // if(mp1.equals(mp2)){
            //     return true;
            // }
            int i=0;
            for(i=0;i<26;i++){
                if(mp1[i]!=mp2[i]){
                    break;
                }
            }
            if(i==26){
                return true;
            }
            right+=1;
            if(right!=s2.length())
                mp2[s2.charAt(right)-'a']+=1;
            mp2[s2.charAt(left)-'a']-=1;
            left+=1;
        }
        return false;
    
    }
};