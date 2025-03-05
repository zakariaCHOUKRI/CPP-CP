def are_the_points_on_the_same_side(x1, y1, x2, y2, x3, y3, x4, y4):
    if y1 == y2 and y2 == y3 and y3 == y4:
        if (min(x1, x2) <= x3 <= max(x1, x2)) or (min(x1, x2) <= x4 <= max(x1, x2)) or (min(x3, x4) <= x1 <= max(x3, x4)) or (min(x3, x4) <= x2 <= max(x3, x4)):
            return True
        else:
            return False
    if x1 == x2 and x2 == x3 and x3 == x4:
        if (min(y1, y2) <= y3 <= max(y1, y2)) or (min(y1, y2) <= y4 <= max(y1, y2)) or (min(y3, y4) <= y1 <= max(y3, y4)) or (min(y3, y4) <= y2 <= max(y3, y4)):
            return True
        else:
            return False
    if (y2-y1)*(x3-x2) == (y3-y2)*(x2-x1) and (y4-y3)*(x3-x2) == (y3-y2)*(x4-x3):
        if (min(y1, y2) <= y3 <= max(y1, y2)) or (min(y1, y2) <= y4 <= max(y1, y2)) or (min(y3, y4) <= y1 <= max(y3, y4)) or (min(y3, y4) <= y2 <= max(y3, y4)):
            return True
        elif (min(x1, x2) <= x3 <= max(x1, x2)) or (min(x1, x2) <= x4 <= max(x1, x2)) or (min(x3, x4) <= x1 <= max(x3, x4)) or (min(x3, x4) <= x2 <= max(x3, x4)):
            return True
        else:
            return False
    n1 = (y3 - y1) * (x2 - x1) - (x3 - x1) * (y2 - y1)
    n2 = (y4 - y1) * (x2 - x1) - (x4 - x1) * (y2 - y1)
    if n1 * n2 > 0:
        return False
    return True

t = int(input().strip())
for _ in range(t):
    x1, y1, x2, y2, x3, y3, x4, y4 = map(int, input().strip().split())
    if (are_the_points_on_the_same_side(x1, y1, x2, y2, x3, y3, x4, y4) and
            are_the_points_on_the_same_side(x3, y3, x4, y4, x1, y1, x2, y2)):
        print("YES")
    else:
        print("NO")