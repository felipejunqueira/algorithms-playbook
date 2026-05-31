def searchSmall(array):
    small = array[0]
    small_index = 0
    for i in range(1, len(array)):
        if array[i] < small:
            small = array[i]
            small_index = i
    return small_index
    
def orderSelection(array):
    newArr = []
    for i in range(len(array)):
        small = searchSmall(array)
        newArr.append(array.pop(small))
    return newArr

print(orderSelection([5, 3, 6, 2, 10]))