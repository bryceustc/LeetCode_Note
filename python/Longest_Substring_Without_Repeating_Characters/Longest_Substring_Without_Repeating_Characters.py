class Solution(object):
    def lengthOfLongestSubstring(self, s):
        freq = {}
        for i in range(256):
            freq[i] = 0
        ls = len(s)
        i = max_len = 0
        for j in range(ls):
            # Note that when charMap[ord(s[j])] >= i, it means that there are
            # duplicate character in current i,j. So we need to update i.
            if freq[ord(s[j])] == 0:
                freq(ord(s[j]) += 1
            else
            {
                freq(ord(s[i])) -= 1
                i +=1
            }
            max_len = max(max_len, j - i + 1)
        return max_len
