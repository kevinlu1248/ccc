# ccc02s1

'''
Sample Input
Copy

1
2
3
4
3

Sample Output
Copy

# of PINK is 0 # of GREEN is 0 # of RED is 1 # of ORANGE is 0
# of PINK is 1 # of GREEN is 1 # of RED is 0 # of ORANGE is 0
# of PINK is 3 # of GREEN is 0 # of RED is 0 # of ORANGE is 0
Total combinations is 3.
Minimum number of tickets to print is 1.
'''

pink, green, yellow, orange, i = (int(input()) for _ in range(5))
sols = []
for p in range(1 + i // pink):
    for g in range(1 + i // green):
        for y in range(1 + i // yellow):
            for o in range(1 + i // orange):
                if (p * pink + g * green + y * yellow + o * orange == i):
                    sols.append((p, g, y, o))
for sol in sols: print("# of PINK is {} # of GREEN is {} # of RED is {} # of ORANGE is {}".format(sol[0], sol[1], sol[2], sol[3]))
print("Total combinations is {}.".format(len(sols)))
print("Minimum number of tickets to print is {}.".format(min(map(sum, sols))))