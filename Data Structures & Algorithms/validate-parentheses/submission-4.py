class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        pair = {')' : '(', '}' : '{', ']' : '['}

        for i in s:
            if i not in pair:
                stack.append(i)
            else:
                if not stack or stack[-1] != pair[i]:
                    return False
                stack.pop()
                
        return len(stack) == 0