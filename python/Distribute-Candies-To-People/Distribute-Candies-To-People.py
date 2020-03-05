class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res = [0]*num_people
        i =0
        while candies >i:
            res[i%num_people] += i+1
            candies -= i+1
            i+=1
        res[i%num_people]+= candies
        return res
      
      
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        # 为了方便理解，把num_people赋值给n，即n个小朋友
        n = num_people
        # 套用上面推出来的公式，直接计算可以完整发放糖果的次数p
        p = int((2 * candies + 0.25)**0.5 - 0.5) 
        # 继续套用公式，算出完整发放糖果以后剩余的糖果数量
        R = int(candies - (p + 1) * p * 0.5)
        # 迭代rows轮，cols是倒霉孩子的下标
        rows, cols = p // n, p % n
        
        # 小朋友们端好了碗，等你发糖
        kids = [0] * n
        for i in range(n):
            # 性感coder，在线发糖
            kids[i] = (i + 1) * rows + int(rows * (rows - 1) * 0.5) * n
            # 最后一轮or在p<n时的第一轮
            if i < cols:
                d[i] += i + 1 + rows * n
        # 最后的那个倒霉孩子开心的拿到了R颗糖       
        kids[cols] += R
        return kids
