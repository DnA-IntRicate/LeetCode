class Solution:
    NUMERAL_MAP: dict[int, str] = {
        1: "I",
        5: "V",
        10: "X",
        50: "L",
        100: "C",
        500: "D",
        1000: "M"
    }

    def intToRoman(self, num: int) -> str:
        if num == 1:
            return self.NUMERAL_MAP[1]

        if num >= 1000:
            if str(num)[0] in ['4', '9']:
                return self.NUMERAL_MAP[500] + self.NUMERAL_MAP[100] + self.intToRoman(num - 1000)

            return self.NUMERAL_MAP[1000] + self.intToRoman(num - 1000)

        if num >= 500:
            if str(num)[0] in ['4', '9']:
                return self.NUMERAL_MAP[100] + self.NUMERAL_MAP[500] + self.intToRoman(num - 500)

            return self.NUMERAL_MAP[500] + self.intToRoman(num - 500)

        if num >= 100:
            if str(num)[0] in ['4', '9']:
                return self.NUMERAL_MAP[50] + self.NUMERAL_MAP[100] + self.intToRoman(num - 100)

            return self.NUMERAL_MAP[100] + self.intToRoman(num - 100)

        if num >= 50:
            if str(num)[0] in ['4', '9']:
                return self.NUMERAL_MAP[10] + self.NUMERAL_MAP[50] + self.intToRoman(num - 50)

            return self.NUMERAL_MAP[50] + self.intToRoman(num - 50)

        if num >= 10:
            if str(num)[0] in ['4', '9']:
                return self.NUMERAL_MAP[5] + self.NUMERAL_MAP[10] + self.intToRoman(num - 10)

            return self.NUMERAL_MAP[10] + self.intToRoman(num - 10)

        if num >= 5:
            if str(num)[0] in ['4', '9']:
                return self.NUMERAL_MAP[1] + self.NUMERAL_MAP[5] + self.intToRoman(num - 5)

            return self.NUMERAL_MAP[5] + self.intToRoman(num - 5)

        return ""

# If the value does not start with 4 or 9,
# select the symbol of the maximal value that
# can be subtracted from the input,
# append that symbol to the result,
# subtract its value, and convert the
# remainder to a Roman numeral.
