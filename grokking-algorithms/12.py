#tempo de execucao O(V+A) numero de vertices mais numeros de arestas
# R <- H means H depende de R
#WIDTH SEARCH AND GRAPH

from collections import deque

graph = {}
graph["voce"] = ["alice", "bob", "claire"]
graph["bob"] = ["anuj", "peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["thom", "jonny"]
graph["anuj"] = []
graph["peggy"] = ["seller"]
graph["thom"] = []
graph["jonny"] = []

def personSeller(name):
    return name == "seller"

def search(name):
    fila_de_pesquisa = deque()
    fila_de_pesquisa += graph[name]
    verified = [] #list of people already verified
    while fila_de_pesquisa: #while fila != NULL
        person = fila_de_pesquisa.popleft()
        #if person not in verified:
        if personSeller(person):
            print(person + " é um vendedor de manga!")
            return True #then stop
        else:
            fila_de_pesquisa += graph[person]  
            verified.append(person)
    return False

search("voce")