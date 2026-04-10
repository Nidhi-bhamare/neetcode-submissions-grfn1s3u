class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Step 1: if lengths different → not anagram
        if len(s) != len(t):
            return False
        
        count = {}
        
        # Step 2: count characters from s
        for ch in s:
            count[ch] = count.get(ch, 0) + 1
        
        # Step 3: subtract using t
        for ch in t:
            if ch not in count:
                return False
            count[ch] -= 1
            if count[ch] == 0:
                del count[ch]
        
        # Step 4: if empty → anagram
        return len(count) == 0