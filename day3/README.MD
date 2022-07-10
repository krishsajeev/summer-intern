# FINDING THE GROUPS IN A CITY

This algorithm considers the city as an undirected, unit-weighted graph with maximim degree = 4.

#### ALGORITHM TO FIND THE NUMBER OF GROUPS
    Do a DFS on the graph for each vertex with a non- zero value
    Create a dynamic array (used custom-reallocation) and save the group sizes
    Create another matrix which has a label (marker) for each group

Note - The last step is done as a preprocessing step for the following function

#### ALGORITHM TO FIND THE SHORTEST PATH
    (Done using Dynamic programming)
    Initialise a dstance vector with all cells as INT_MAX.
    Create a custom queue datastructure (Since the problem states not to use STL !)
    Do a BFS on the graph for each vertex which is a part of the leader group.
    Find the distance and minimize the distance vector.
