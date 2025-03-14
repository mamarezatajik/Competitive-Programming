def calculate_percentages(l):
    from collections import defaultdict

    # Step 1: Construct adjacency list
    graph = defaultdict(set)
    for a, b in l:
        graph[a].add(b)
        graph[b].add(a)

    # Step 2: Compute connection counts
    connections = {person: len(friends) for person, friends in graph.items()}

    # Step 3: Sort individuals based on number of connections (desc), then by name (asc)
    sorted_people = sorted(connections.items(), key=lambda x: (-x[1], x[0]))

    # Step 4: Select top 10 people
    top_10 = sorted_people[:10]

    # Step 5: Compute max and min cheating probability
    total_edges = sum(connections.values()) / 2  # Each connection is counted twice

    max_contributions = sum(top_10[i][1] for i in range(5))
    min_contributions = sum(top_10[i][1] for i in range(5, 10))

    max_percent = max_contributions / total_edges
    min_percent = min_contributions / total_edges

    # Step 6: Return the rounded results
    return round(max_percent, 3), round(min_percent, 3)

# Example input
l = [['Zahra', 'Mona'], ['Saeed', 'Reza'], ['Amin', 'Narges'], ['Milad', 'Armin'], ['Majid', 'Mona'],
     ['Mona', 'Reza'], ['Zahra', 'Sara'], ['Sara', 'Amin'], ['Narges', 'Saeed'], ['Sara', 'Majid'],
     ['Ahmad', 'Abbas'], ['Abbas', 'Mona'], ['Saman', 'Reza'], ['Sara', 'Ahmad'], ['Iman', 'Ahmad'],
     ['Javad', 'Abbas'], ['Kamand', 'Sara'], ['Narges', 'Matin'], ['Saghi', 'Narges'], ['Omid', 'Reza'],
     ['Omid', 'Iman'], ['Abbas', 'Omid'], ['Javad', 'Omid'], ['Ahmad', 'Saghi']]

# Expected output: (0.842, 0.632)
print(calculate_percentages(l))
