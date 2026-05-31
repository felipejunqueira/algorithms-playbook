def soma(lista):
    if lista == []: return 0
    return lista[0] + soma(lista[1:])

def cont(lista):
    if lista == []: return 0
    return 1 + cont(lista[1:])

def max(lista):
    if len(lista) == 2:
        return lista[0] if lista[0] > lista [1] else lista[1]
    sub_max = max(lista[1:])
    return lista[0] if lista[0] > sub_max else sub_max


list = [5, 2, 9, 4]
print("a soma de tudo é", soma(list))
print("there are", cont(list), "items")
print("the biggest is", max(list))

