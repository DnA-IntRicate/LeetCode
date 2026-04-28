import re


class Solution:
    # '.' - Match any single character
    # '*' - Match zero or more of the preceeding character
    def isMatch(self, s: str, p: str) -> bool:
        return bool(re.fullmatch(p, s))
