class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        last = len(nums) - 1
        index = 0

        while index <= last:
            current = nums[index]
            if current == val:
                nums[index] = nums[last]
                nums[last] = current
                last -= 1
            else:
                index += 1

        return index
