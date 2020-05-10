import math
a, b, c = map(int, input().split())
print(int(4 * (math.sqrt(a * b * c) / a + math.sqrt(a * b * c) / b + math.sqrt(a * b * c) / c)))