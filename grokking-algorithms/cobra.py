print("hello world py")

def binsearch(lista, item):
    start = 0 #always as position
    end = len(lista) - 1
    while start <= end: #until have only one
        mid = (start + end) // 2 #as index
        print (mid)
        kick = lista[mid]
        if kick == item: return mid
        if kick > item: end = mid - 1
        else: start = mid + 1
    return None
    
lis = [1, 3, 5, 7, 9]
print (binsearch(lis, 3))
print (binsearch(lis, -1))