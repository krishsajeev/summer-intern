#include <iostream>
#include <bits/stdc++.h>
class Vertex{
    public:
        int row;
        int col;
        Vertex(int row,int col){
            this->row=row;
            this->col=col;
        }
};
// Avoiding memory leaks.
void deleteMatrix(int **arry, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] arry[i];
    }
    delete[] arry;
}
void deleteMatrix(bool **arry, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] arry[i];
    }
    delete[] arry;
}

// This is a modified DFS algorithm that find the groups and their sizes and segregates them based on labels.
int DFS(int **mat, bool **isVisited, int row, int col, int rowSize, int colSize, int **labels, int label)
{
    if (row >= 0 && row < rowSize && col >= 0 && col < colSize && !isVisited[row][col] && mat[row][col] != 0)
    {
        isVisited[row][col] = true;

        int groupSize = mat[row][col];
        labels[row][col] = label;
        groupSize += DFS(mat, isVisited, row - 1, col, rowSize, colSize, labels, label);
        groupSize += DFS(mat, isVisited, row, col - 1, rowSize, colSize, labels, label);
        groupSize += DFS(mat, isVisited, row + 1, col, rowSize, colSize, labels, label);
        groupSize += DFS(mat, isVisited, row, col + 1, rowSize, colSize, labels, label);

        return groupSize;
    }
    return 0;
}


void findGroups(int **graph, bool **isVisited, int **labels, int *leaderSize, int *count, int *leaderLabel, int **groups, int rows, int cols)
{
    int *temp = new int[(rows * cols) / 2];

    int label = 1;
    int numGroups = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!isVisited[i][j] && graph[i][j] != 0)
            {
                int groupSize = DFS(graph, isVisited, i, j, rows, cols, labels, label);
                if (groupSize > *leaderSize)
                {
                    *leaderLabel = label;
                    *leaderSize = groupSize;
                }
                // std::cout << groupSize << " ";
                temp[numGroups] = groupSize;
                label++;
                (*count)++;
                numGroups++;
            }
        }
    }

    *groups = new int[(*count)];
    for (int i = 0; i < (*count); i++)
    {
        (*groups)[i] = temp[i];
    }

    delete[] temp; //Avioiding memory leaks.
}
int dist(Vertex v1,Vertex v2){
    return abs(v1.row-v2.row) + abs(v1.col-v2.col);
}
int main()
{
    // Sample Test Case.
    int mat[5][5] = {
        {0, 2, 0, 3, 1},
        {4, 1, 2, 0, 0},
        {2, 0, 0, 0, 0},
        {0, 1, 0, 2, 3},
        {0, 0, 1, 1, 0},
    };

    int rows, cols;
    std::cout << "Enter the number of rows and cols:" << "\n";
    //std::cin >> rows;
    //std::cin >> cols;

    // Sample Test Case

    rows = 5;
    cols = 5;

    // Create memory from the heap.
    int **graph = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        graph[i] = new int[cols];
    }
    bool **isVisited = new bool *[rows];
    for (int i = 0; i < rows; i++)
    {
        isVisited[i] = new bool[cols];
    }
    int **labels = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        labels[i] = new int[cols];
    }

    // Initialise the matrices.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            isVisited[i][j] = false;
            labels[i][j] = 0;
        }
    }

    // Get input.
    std::cout << "Enter values:"
              << "\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //std::cin >> graph[i][j];
            // Automated input for Sample Test Case
            graph[i][j] = mat[i][j];
        }
    }

    std::cout << "The matrix is" << "\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int leaderLabel = INT_MIN;
    int leaderSize = INT_MIN;
    int count = 0;
    int *groups;

    // Function for finding the groups and sizes
    findGroups(graph, isVisited, labels, &leaderSize, &count, &leaderLabel, &groups, rows, cols);

    int option=1;
    /*std::cout << "DO YOU WANT TO FIND THE GROUPS AND THE LEADER [ 1 / 0 ]?" << std::endl;
    std::cin >> option;
    */
    if(option==1){
        std::cout << "\nTHE GROUPS ARE" << std::endl;
        for (int i = 0; i < count; i++)
        {
            std::cout << groups[i] << " ";
        }
        std::cout << "\nTHE NUMBER OF GROUPS ARE " << count;
        std::cout << "\nTHE LEADER HAS A SIZE OF " << leaderSize << std::endl;
    }

    int *distances = new int[count];
    for (int i = 0; i < count; i++)
    {
        if (i == leaderLabel - 1)
        {
            distances[i] = 0;
        }
        else
        {
            distances[i] = INT_MAX;
        }
    }
    std::cout << std::endl;

    std::vector<Vertex> leader;
    std::map<int, std::vector<Vertex>> nonleader;

    for(int i = 0; i < rows;i++){
        for(int j = 0; j < cols; j++){
            Vertex v(i, j);
            if(labels[i][j] == leaderLabel){
                leader.push_back(v);
            }
            else if(labels[i][j] != 0){
                nonleader[labels[i][j]].push_back(v);
            }
        }
    }
/*
    for(int i=0;i<leader.size();i++){
        std::cout << leader[i].row << leader[i].col;
    }
*/
/*
    std::map<int, std::vector<Vertex>>::iterator itr;
    for (itr = nonleader.begin(); itr != nonleader.end(); ++itr) {
        std::cout << itr->first << std::endl;
        std::vector<Vertex> temp=itr->second;
        for(int i=0;i<temp.size();i++){
        std::cout << temp[i].row <<" " << temp[i].col<<std::endl;
    }
    }
*/
    std::map<int, std::vector<Vertex>>::iterator itr;
    for (itr = nonleader.begin(); itr != nonleader.end(); ++itr) {
        //std::cout << itr->first << std::endl;
        std::vector<Vertex> temp = itr->second;
        int minDistance = INT_MAX;
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr2 < temp.size()){
            int currDistance = dist(leader[ptr1],temp[ptr2]);
            if(minDistance > currDistance){
                minDistance = currDistance;
            }
            if(currDistance >= dist(leader[ptr1+1], temp[ptr2])){
                ptr1++;
            }
            else{
                ptr2++;
            }
        }
        distances[(itr->first) - 1] = minDistance - 1;
    }

    std::cout << "THE DISTANCE VECTOR IS \n";
    for(int i = 0; i < count; i++){
        std::cout << distances[i] << " ";
    }


    // Avoiding memory leaks.
    deleteMatrix(graph, rows);
    deleteMatrix(isVisited, rows);
    deleteMatrix(labels, rows);
    delete[] groups;
    delete[] distances;

    return 0;
}