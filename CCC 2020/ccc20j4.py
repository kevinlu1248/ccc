
'''
ABCCDEABAA
ABCDE
'''

t, s = input(), input()

for i in range(len(s)):
    print()
    for j in range(len(s)):
        print(s[(i + j) % len(s)])