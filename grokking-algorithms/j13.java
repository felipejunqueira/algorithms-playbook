import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class j13 {
    public static void main(String[] args) {
        //create the graph as a HashMap of HashMaps
        Map<String, Map<String, Integer>> graph = new HashMap<>();

        //add "start" node neighbors 
        Map<String, Integer> startNeighbors = new HashMap<>();
        startNeighbors.put("a", 6);
        startNeighbors.put("b", 2);
        graph.put("start", startNeighbors);

        //add "a" neighbors
        Map<String, Integer> aNeighbors = new HashMap<>();
        aNeighbors.put("end", 1);
        graph.put("a", aNeighbors);

        //add "b" neighbors
        Map<String, Integer> bNeighbors = new HashMap<>();
        bNeighbors.put("a", 3);
        bNeighbors.put("end", 5);
        graph.put("b", bNeighbors);

        //"end" has no neighbors
        graph.put("end", new HashMap<>());

        Map<String, Integer> costs = new HashMap<>();
        int infinity = Integer.MAX_VALUE; 
        costs.put("a", 6); //beginning costs
        costs.put("b", 2);
        costs.put("end", infinity);

        Map<String, String> parents = new HashMap<>();
        parents.put("a", "start");
        parents.put("b", "start");
        parents.put("end", null);

        Set<String> verified = new HashSet<>();

        String node = findCheapest(costs, verified);
        while (node != null) {
            int cost = costs.get(node); //atual cost untill this node
            Map<String, Integer> neighbors = graph.get(node); //neighbors
            for (String n : neighbors.keySet()) { //for each neighbor
                int newCost = cost + neighbors.get(n);
                if (costs.getOrDefault(n, infinity) > newCost) {
                    costs.put(n, newCost);
                    parents.put(n, node);
                }
            } 
            verified.add(node);
            node = findCheapest(costs, verified);
        }
        //rebuid the shortest way from end to start
        List<String> path = new ArrayList<>();
        String current = "end";
        while (current != null) {
            path.add(current);
            current = parents.get(current);
        }
        Collections.reverse(path); //from start to end

        System.out.println("the best route is: ");
        System.out.println(String.join(" -> ", path));
        System.out.println("the cost for it is: " + costs.get("end"));
    }

    //auxiliary function
    private static String findCheapest(Map<String, Integer> costs, Set<String> verified) {
        int cheapestCost = Integer.MAX_VALUE;
        String cheapestNode = null;
        for (String node : costs.keySet()) {
            int cost = costs.get(node);
            if (cost < cheapestCost && !verified.contains(node)) {
                cheapestCost = cost;
                cheapestNode = node;
            }
        }
        return cheapestNode;
    }
}
