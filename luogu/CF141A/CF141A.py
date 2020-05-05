let = {'A': 0,'B': 1,'C': 2,'D': 3,'E': 4,'F': 5,'G': 6,'H': 7,'I': 8,'J': 9,'K': 10,'L': 11,'M': 12,'N': 13,'O': 14,'P': 15,'Q': 16,'R': 17,'S': 18,'T': 19,'U': 20,'V': 21,'W': 22,'X': 23,'Y': 24,'Z': 25}
list1 = [0 for i in range(26)]
list2 = [0 for i in range(26)]
str1 = str(input())
str2 = str(input())
str3 = str(input())
for letter in str1:
    list1[let[letter]] += 1
for letter in str2:
    list1[let[letter]] += 1
for letter in str3:
    list2[let[letter]] += 1
if list1 == list2:
    print('YES')
else:
    print("NO")