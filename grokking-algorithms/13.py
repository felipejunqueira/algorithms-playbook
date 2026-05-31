#DIJKSTRA ALGORITHM

'''
       6  -> A ->  1
             ^
start      3 |       -> end
       2  -> B ->  5 
'''


graph = {} #hash table GRAPH

graph["start"] = {}
graph["start"]["a"] = 6 #neighbors weight
graph["start"]["b"] = 2

print(graph["start"].keys())
print(graph["start"]["a"])
print(graph["start"]["b"])

graph["a"] = {} #hash table inside graph
graph["a"]["end"] = 1

graph["b"] = {} #hash table inside graph
graph["b"]["a"] = 3
graph["b"]["end"] = 5

graph["end"] = {} #hash table, there is no neighbors, inside graph

infinity = float("inf") #infinity in python

costs = {} #hash table costs
costs["a"] = 6
costs["b"] = 2
costs["end"] = infinity

parents = {} #hash table PARENTS
parents["a"] = "start"
parents["b"] = "start"
parents["end"] = None
parents["start"] = None  # <-- Adicione esta linha

verified = []

def find_cheaper(costs):
    cheapest_cost = infinity
    cheapest_node = None #we don't know yet
    for node in costs: #check each node
        cost = costs[node]
        if cost < cheapest_cost and node not in verified:
            cheapest_cost = cost
            cheapest_node = node
    return cheapest_node


#the algorithm itself
node = find_cheaper(costs) #the cheapest not verified
while node is not None: #if all verified, it finish
    time = costs[node]
    neighbors = graph[node]
    for n in neighbors.keys(): #check all node neighbors
        new_time = time + neighbors[n] 
        if costs[n] > new_time: #if way is cheaper
            costs[n] = new_time #update it cost
            parents[n] = node #new neighbor's dad
    verified.append(node)
    node = find_cheaper(costs)

#rebuild the cheapest way
path = []
node = "end"
while node:
    path.append(node)
    node = parents[node]
path.reverse()

print("the best route is:")
print(" -> ".join(path))
print("the cost for it is:", costs["end"])