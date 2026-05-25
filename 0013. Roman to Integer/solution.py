class Solution:
    # I             1
    # V             5
    # X             10
    # L             50
    # C             100
    # D             500
    # M             1000
    NUMERAL_MAP: dict[str, int] = {
        "I": 1,
        "V": 5,
        "X": 10,
        "L": 50,
        "C": 100,
        "D": 500,
        "M": 1000
    }

    def romanToInt(self, s: str) -> int:
        if not s:
            return 0

        if len(s) == 1:
            return self.NUMERAL_MAP[s[0]]

        if self.NUMERAL_MAP[s[0]] < self.NUMERAL_MAP[s[1]]:
            return (self.NUMERAL_MAP[s[1]] - self.NUMERAL_MAP[s[0]]) + self.romanToInt(s[2:])

        return self.NUMERAL_MAP[s[0]] + self.romanToInt(s[1:])
