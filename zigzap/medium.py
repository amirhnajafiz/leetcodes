class Solution:
    def convert(self, s: str, numRows: int) -> str:
        i = 0
        normal = True
        rows = numRows

        index = 0
        output = [""] * rows

        while index < len(s):
            output[i] = output[i] + s[index]
            index += 1

            if normal:
                i += 1
            else:
                i -= 1

            if i >= numRows - 1:
                normal = False
                i = numRows - 1
            elif i <= 0:
                normal = True
                i = 0

        return ''.join(output)
