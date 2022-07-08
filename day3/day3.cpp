#include <bits/stdc++.h>
#include<iostream>
const int ROWS=5;
const int COLS=5;

//Template for a smart pointer to avoid memory leaks.
template <class T>
class SmartPtr {
    private:
        T* ptr;
    public:
        //Constructor.
        explicit SmartPtr(T* p = NULL)
        {
            ptr = p;
        }

        //Destructor.
        ~SmartPtr()
        {
            delete (ptr); 
        }

        //Overloaded operator
        T& operator * () 
        {
            return *ptr; 
        }
    
        T* operator -> () 
        { 
            return ptr; 
        }

        T* operator + (const int& i)
        {
            return ptr+i;
        }
};

int DFS(int mat[ROWS][COLS], SmartPtr<bool*> isVisited, int row, int col)
{
    //If (out-of-bounds) or (already-visited) or (boundary) return 0.
    if (row<0 || row>=ROWS || col<0 || col>=COLS || (*(*(isVisited + row) + col)) || mat[row][col]==0)
        return 0;

    (*(*(isVisited + row) + col))=true; //Mark as visited.

    int groupCount = 0;
    
    groupCount += mat[row][col];
    groupCount += DFS(mat, isVisited, row-1, col); //Up.
    groupCount += DFS(mat, isVisited, row, col-1); //Left.
    groupCount += DFS(mat, isVisited, row, col+1); //Right.
    groupCount += DFS(mat, isVisited, row+1, col); //Down.

    return groupCount;    
}

int main()
{
    int mat[ROWS][COLS] = {
                        {0, 2, 0, 3, 1},
                        {4, 1, 2, 0, 0},
                        {2, 0, 0, 0, 0},
                        {0, 1, 0, 2, 3},
                        {0, 0, 1, 1, 0},
                    };


    //Create a "Smart" isVisited matrix.
    SmartPtr<bool*> isVisited(new bool*[ROWS]);
    for (int i = 0; i < ROWS; i++) {
        *(isVisited + i) = new bool[COLS];
    }

    //Initialise the isVisited matrix to false.
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            *(*(isVisited + i) + j) = false;
        }
    }

    int leaderCount = INT_MIN;
    std::cout << "THE GROUPS ARE ";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ( !(*(*(isVisited + i) + j)) && mat[i][j]!=0) {
                int count = DFS(mat, isVisited, i, j);  //Do a DFS on the graph
                std::cout << count << " ";
                leaderCount = (leaderCount > count)? leaderCount : count;   //Maximise the group size to find leader.
            }
        }
    }

    std::cout << std::endl << "THE LEADER HAS A GROUP SIZE OF " << leaderCount;



}