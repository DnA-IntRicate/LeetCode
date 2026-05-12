class Solution:
    ROMAN_VALUES: list[tuple[int, str]] = [
        (1000, "M"),
        (900, "CM"),
        (500, "D"),
        (400, "CD"),
        (100, "C"),
        (90, "XC"),
        (50, "L"),
        (40, "XL"),
        (10, "X"),
        (9, "IX"),
        (5, "V"),
        (4, "IV"),
        (1, "I")
    ]

    def intToRoman(self, num: int, memo: dict[int, str] = {}) -> str:
        if num in memo.keys():
            return memo[num]

        res = []
        for value, numeral in self.ROMAN_VALUES:
            while num >= value:
                res.append(numeral)
                num -= value

        memo[num] = "".join(res)
        return memo[num]
