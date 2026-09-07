class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_dict = {}
        t_dict = {}
        if len(s) != len(t):
            return False
        counts = {}
        for cs, ct in zip(s, t):
            counts[cs] = counts.get(cs, 0) + 1
            counts[ct] = counts.get(ct, 0) - 1
        return all(v == 0 for v in counts.values())

         