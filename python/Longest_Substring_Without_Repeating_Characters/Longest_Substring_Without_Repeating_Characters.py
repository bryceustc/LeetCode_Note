class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        freq = {}
        for i in range(256):
            freq[i] = 0
        ls = len(s)
        l=max_len = 0
        r=-1
        while(r+1 < len(s)):
            if freq[ord(s[r+1])] ==0:
                freq[ord(s[r+1])] += 1
                r+=1
            else:
                freq[ord(s[l])] -= 1
                l +=1
            max_len = max(max_len, r - l +1 )
        return max_len
