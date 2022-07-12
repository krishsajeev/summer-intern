#include <iostream>
#include <bits/stdc++.h>

// Datastructure for inserting matrix cells into queue.
struct Node
{
    int row;
    int col;
    Node *next;
};

// Queue Datastructure for BFS traversal.
class Queue
{
    private:
        Node *front, *rear;
        int size;

    public:
        Queue()
        {
            front = rear = NULL;
            size = 0;
        }

        bool isEmpty()
        {
            return size == 0;
        }

        Node *peek()
        {
            return front;
        }

        bool isNULL(Node *node)
        {
            return node->row == -1 && node->col == -1;
        }

        void print()
        {
            if (front == NULL)
            {
                return;
            }
            Node *temp = front;
            while (temp)
            { // Will check until NULL is not found.
                std::cout << "(" << temp->row << "," << temp->col << ")";
                temp = temp->next;
            }
            std::cout << std::endl;
        }

        Node *dequeue()
        {
            if (front == NULL)
            {
                return NULL;
            }
            Node *temp = front;
            if (front == rear)
            { // If only one node is there.
                front = rear = NULL;
            }
            else
            {
                front = front->next;
            }
            size--;
            return temp;
        }

        void enqueue(int row, int col)
        {
            Node *temp = new Node;
            if (temp == NULL)
                return;

            temp->row = row;
            temp->col = col;
            temp->next = NULL;

            // for first node
            if (front == NULL)
            {
                front = rear = temp;
            }
            else
            {
                rear->next = temp;
                rear = temp;
            }
            size++;
        }

        ~Queue() // Destructor to avoid memory leaks.
        {
            while (front != NULL)
            {
                Node *temp = front;
                front = front->next;
                delete temp;
            }
            rear = NULL;
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

// Helper function used by the queue.
bool isValid(bool **isVisited, int r, int c, int rowSize, int colSize, int **labels, int leaderLabel)
{
    return r >= 0 && r < rowSize && c >= 0 && c < colSize && labels[r][c] != leaderLabel && isVisited[r][c] == false;
}

// This is a modified BFS algorithm that find the shortest path using DYNAMIC PROGRAMMING.
void BFS(Queue q, int **labels, bool **isVisited, int row, int col, int rowSize, int colSize, int leaderLabel, int *distances)
{
    q.enqueue(row, col);
    q.enqueue(-1, -1);

    isVisited[row][col] = true;

    int distance = 0;
    while (!q.isEmpty())
    {
        // q.print();
        Node *node = q.peek();
        if (!q.isNULL(node))
        {
            node = q.dequeue();
            int currRow = node->row;
            int currCol = node->col;

            if (distances[labels[currRow][currCol] - 1] > distance)
            {
                distances[labels[currRow][currCol] - 1] = distance;
            }
            isVisited[currRow][currCol] = true;

            if (isValid(isVisited, currRow + 1, currCol, rowSize, colSize, labels, leaderLabel))
            {
                q.enqueue(currRow + 1, currCol); // Up
                isVisited[currRow + 1][currCol] = true;
            }
            if (isValid(isVisited, currRow, currCol + 1, rowSize, colSize, labels, leaderLabel))
            {
                q.enqueue(currRow, currCol + 1); // Right
                isVisited[currRow][currCol + 1] = true;
            }
            if (isValid(isVisited, currRow - 1, currCol, rowSize, colSize, labels, leaderLabel))
            {
                q.enqueue(currRow - 1, currCol); // Down
                isVisited[currRow - 1][currCol] = true;
            }
            if (isValid(isVisited, currRow, currCol - 1, rowSize, colSize, labels, leaderLabel))
            {
                q.enqueue(currRow, currCol - 1); // Left
                isVisited[currRow][currCol - 1] = true;
            }
        }
        else
        {
            q.dequeue();
            if (q.isEmpty())
                return;
            q.enqueue(-1, -1);
            distance++;
        }
    }
}

void findShortestPath(int *distances, bool **isVisited, int **labels, int leaderLabel, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (labels[i][j] == leaderLabel)
            {

                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        isVisited[i][j] = false;
                    }
                }

                Queue q;
                BFS(q, labels, isVisited, i, j, rows, cols, leaderLabel, distances);
            }
        }
    }
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

    int option;
    std::cout << "DO YOU WANT TO FIND THE GROUPS AND THE LEADER [ 1 / 0 ]?" << std::endl;
    std::cin >> option;
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

    // Function to find the shortest path from the leaser group to all other groups
    findShortestPath(distances, isVisited, labels, leaderLabel, rows, cols);


    std::cout << "DO YOU WANT TO FIND THE SHORTEST PATH FROM THE LEADER TO OTHER GROUPS? [ 1/0 ]\n";
    std::cin >> option;
    if(option==1){
        /*
        std::cout << "THE DISTANCE VECTOR IS (EDGES)" << std::endl;
        for(int i=0;i<count;i++){
            std::cout << distances[i] << " ";
        }
        */

        std::cout << "\nTHE DISTANCE VECTOR IS (VERTICES)" << std::endl;
        for (int i = 0; i < count; i++)
        {
            if (i == leaderLabel - 1)
            {
                std::cout << distances[i] << " ";
            }
            else
            {
                std::cout << distances[i] - 1 << " ";
            }
        }
    }

    // Avoiding memory leaks.
    deleteMatrix(graph, rows);
    deleteMatrix(isVisited, rows);
    deleteMatrix(labels, rows);
    delete[] groups;
    delete[] distances;

    return 0;
}