def calculate_percentages(l):
    from collections import defaultdict
    graph = defaultdict(set)

    for a, b in l:
        graph[a].add(b)
        graph[b].add(a)

    sorted_people = sorted(graph, key=lambda x: (-len(graph[x]), x))

    max_group, min_group = sorted_people[:5], sorted_people[5:10]

    def get_connected_count(group):
        return len(set(person for p in group for person in (graph[p] | {p})))

    total_people = len(graph)
    max_percentage = round(get_connected_count(max_group) / total_people, 3)
    min_percentage = round(get_connected_count(min_group) / total_people, 3)

    return max_percentage, min_percentage