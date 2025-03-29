#394. Decode String

#The algorithm is simple. Just using the stack. But the implement by python is much more easier.
#The method of this solution is much better and more convenient. Each time when read the '[', we can just push the string and num
#into the stack, and it will not affect anything if it empty because we use the concat method.

class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        num = 0
        string = ''

        for c in s:
            if c == '[':
                stack.append(string)
                stack.append(num)
                string = ''
                num = 0
            elif c == ']':
                cur = stack.pop()
                preString = stack.pop()
                string = preString + cur * string
            elif c.isdigit():
                num = num * 10 + int(c)
            else:
                string += c
        
        return string