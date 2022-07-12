# FINDING THE GROUPS IN A CITY

This algorithm considers the city as an undirected, unit-weighted graph with maximum degree = 4.

#### ALGORITHM TO FIND THE NUMBER OF GROUPS
    Do a DFS on the graph for each vertex with a non- zero value.
    Create a dynamic array (used custom-reallocation) and store the group sizes.
    Create another matrix which has a label (marker) for each group.

Note - The last step is done as a preprocessing step for the following function

#### ALGORITHM TO FIND THE SHORTEST PATH
    Create vectors for each label.
    For each co-ordinate in the leader-vector, iterate through the non-leader vectors.
    Find the minimal distance.
    (The previous step has been optimised by leveraging the sorted order of the co-ordinates)
