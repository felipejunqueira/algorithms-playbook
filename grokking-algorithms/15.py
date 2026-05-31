#GREEDY ALGORITHM

states_to_cover = set(["mt", "wa", "or", "id", "nv", "ut", "ca", "az"])

stations = {}
stations["kone"] = set(["id", "nv", "ut"])
stations["ktwo"] = set(["wa", "id", "mt"])
stations["kthree"] = set(["or", "nv", "ca", ])
stations["kfour"] = set(["nv", "ut"])
stations["kfive"] = set(["ca", "az"])

final_stations = set()

while states_to_cover:
    best_station = None
    covered_states = set()
    for station, states_by_station in stations.items():
        covered = states_to_cover & states_by_station
        if len(covered) > len(covered_states):
            best_station = station
            covered_states = covered
    final_stations.add(best_station)
    states_to_cover -= covered_states

print(sorted(final_stations))
