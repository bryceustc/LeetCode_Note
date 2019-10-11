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
        max_len = 0
        l=0
        for r in range(ls):
            # Note that when charMap[ord(s[j])] >= i, it means that there are
            # duplicate character in current i,j. So we need to update i.
            
            if freq[ord(s[r])] ==0:
                freq[ord(s[r])] += 1
            else:
                freq[ord(s[l])] -= 1
                l +=1
            max_len = max(max_len, r - l )
        return max_len
