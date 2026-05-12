class Solution:
    NUMERAL_MAP: dict[int, str] = {
        1: "I",
        4: "IV",
        5: "V",
        9: "IX",
        10: "X",
        40: "XL",
        50: "L",
        90: "XC",
        100: "C",
        400: "CD",
        500: "D",
        900: "CM",
        1000: "M"
    }

    def intToRoman(self, num: int) -> str:
        if num in self.NUMERAL_MAP.keys():
            return self.NUMERAL_MAP[num]

        highest = max(x for x in self.NUMERAL_MAP.keys() if x <= num)
        return self.NUMERAL_MAP[highest] + self.intToRoman(num - highest)
