class Solution {
    public String reverseWords(String s) {
        String str[] = s.split(" ");
        StringBuilder result = new StringBuilder();
        
        for(String word : str){
            StringBuilder sb = new StringBuilder(word);
            sb = sb.reverse();
            result.append(sb);
            result.append(" ");
        }
    return result.toString().trim();
    }
}