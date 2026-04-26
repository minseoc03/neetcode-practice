class Solution:
    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res += str(len(s)) + '#' + s
        return res

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        while i < len(s):
            j = s.index('#', i)          # '#' 위치 찾기
            length = int(s[i:j])         # '#' 앞이 길이
            res.append(s[j+1:j+1+length]) # '#' 뒤로 length만큼 읽기
            i = j + 1 + length
        return res