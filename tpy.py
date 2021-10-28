def isPowerOfTwo(n: int) -> bool:
    return (n & (n - 1)) == 0

class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        nums = sorted(list(str(n)))
        m = len(nums)
        vis = [False] * m

        def backtrack(idx: int, num: int) -> bool:
            if idx == m:
                return isPowerOfTwo(num)
            for i, ch in enumerate(nums):
                # 不能有前导零
                if (num == 0 and ch == '0') or vis[i] or (i > 0 and not vis[i - 1] and ch == nums[i - 1]):
                    continue
                vis[i] = True
                if backtrack(idx + 1, num * 10 + ord(ch) - ord('0')):
                    return True
                vis[i] = False
            return False

        return backtrack(0, 0)


s = Solution()
print(s.reorderedPowerOf2(10))
