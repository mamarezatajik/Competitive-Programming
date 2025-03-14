def solve(n, m, L):
    import numpy as np
    transition_matrix = np.zeros((n + 1, n + 1))

    for i in range(n + 1):
        if i > 0:
            transition_matrix[i, i - 1] = L[i]
        if i < n:
            transition_matrix[i, i + 1] = 1 - L[i]

        transition_matrix[i, i] = 1 - np.sum(transition_matrix[i])

    initial_distribution = np.zeros(n + 1)
    initial_distribution[0] = 1

    for _ in range(m):
        initial_distribution = initial_distribution @ transition_matrix

    expected_value = np.dot(np.arange(n + 1), initial_distribution)

    return round(expected_value, 5)