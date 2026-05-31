import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class j15 { 
    public static void main(String[] args) {
        //states to cover set
        Set<String> statesToCover = new HashSet<>(Arrays.asList(
            "mt", "wa", "or", "id", "nv", "ut", "ca", "az"
        ));

        //covered states station map
        Map<String, Set<String>> stations = new HashMap<>();
        stations.put("kone", new HashSet<>(Arrays.asList("id", "nv", "ut")));
        stations.put("ktwo", new HashSet<>(Arrays.asList("wa", "id", "mt")));
        stations.put("kthree", new HashSet<>(Arrays.asList("or", "nv", "ca")));
        stations.put("kfour", new HashSet<>(Arrays.asList("nv", "ut")));
        stations.put("kfive", new HashSet<>(Arrays.asList("ca", "az")));

        //chosen stations set
        Set<String> finalStations = new HashSet<>();
        
        while (!statesToCover.isEmpty()) {
            String bestStation = null;
            Set<String> statesCovered = new HashSet<>();
            for (Map.Entry<String, Set<String>> entry : stations.entrySet()){
                Set<String> covered = new HashSet<>(statesToCover);
                covered.retainAll(entry.getValue());
                if (covered.size() > statesCovered.size()) {
                    bestStation = entry.getKey();
                    statesCovered = covered;
                }
            }
            if (bestStation != null) {
                finalStations.add(bestStation);
                statesToCover.removeAll(statesCovered);
            }
        }
        List<String> sortedStations = new ArrayList<>(finalStations);
        Collections.sort(sortedStations);
        System.out.println(sortedStations);
    }
}