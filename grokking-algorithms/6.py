def fat(x):
    if x == 1: 
        return 1
    else:
        return x * fat(x-1)
    
x = 3
print(fat(x))