class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        outputs = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']
        }

        stack = []
        for i in digits:
            pairs = outputs[i]
            if len(stack) == 0:
                for j in pairs:
                    stack.append(j)
            else:
                tmp = []
                while len(stack) > 0:
                    item = stack.pop()
                    for j in pairs:
                        tmp.append(item + j)
                stack = tmp

        return stack
