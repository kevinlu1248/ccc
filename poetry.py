# ccc 2003 s2

'''
Sample Input 1
Copy

1
One plus one is small
one hundred plus one is not
you might be very tall
but summer is not

Output for Sample Input 1
Copy

cross

Sample Input 2
Copy

2
I say to you boo
You say boohoo
I cry too
It is too much foo
Your teacher has to mark
and mark and mark and teach
To do well on this contest you have to reach
for everything with a lark

Output for Sample Input 2
Copy

perfect
shell

Sample Input 3
Copy

2
It seems though
that without some dough
creating such a bash
is a weighty in terms of cash
But how I see
the problem so fair
is to write subtle verse
with hardly a rhyme

Output for Sample Input 3
Copy

even
free
'''

vowels = set('aeiou')

def last_syl(s):
    out = ""
    for char in s:
        if char in vowels:
            return out + char
        out += char
    return s

for _ in range(int(input())):
    poem = [input().lower().split() for __ in range(4)]
    syl = [last_syl(line[-1][::-1]) for line in poem]
    # print(syl)
    if (syl[0] == syl[1] == syl[2] == syl[3]):
        print("perfect")
    elif (syl[0] == syl[2] and syl[1] == syl[3]):
        print('cross')
    elif (syl[0] == syl[1] and syl[2] == syl[3]):
        print('even')
    elif (syl[0] == syl[3] and syl[1] == syl[2]):
        print('shell')
    else:
        print('free')