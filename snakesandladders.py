# ccc03s1

'''
Sample Input
Copy

9
11
12
7
3
5
10
9

Sample Output
Copy

You are now on square 10
You are now on square 21
You are now on square 33
You are now on square 64
You are now on square 86
You are now on square 91
You are now on square 91
You are now on square 100
You Win!
'''

map = {54: 19, 90: 48, 99: 77, 9: 34, 40: 64, 67: 86}

i = 1
while True:
    try:
        add = int(input())
        print(i)
        if i == 0:
            print("You Quit!")
            break
        i += add
        if i in map: 
            i = map[i]
        if i >= 100:
            print("You are on square 100!")
            print("You Win!")
            break
        else:
            print("You are now on square {}".format(i))
    except:
        break