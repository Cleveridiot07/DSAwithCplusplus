
class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<>();
        int l = 0, r = 0, max = 0;
        
        while (r < s.length()) {
            char ch = s.charAt(r);
            if (!set.contains(ch)) {
                set.add(ch);
                max = Math.max(max, r - l + 1);
                r++;
            } else {
                set.remove(s.charAt(l));
                l++;
            }
        }
        
        return max;
    }
}
