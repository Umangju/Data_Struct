﻿#include <iostream>

using namespace std;

#define SIZE 10

template<typename T>
class AdjacencyList
{
private:
    struct Node
    {
        char data;
        Node* next;

        Node(T data, Node* link = nullptr)
        {
            this->data = data;
            next = link;
        }
    };

    int size;           // 정점의 개수
    T vertex[SIZE];     // 정점의 집합
    Node* list[SIZE];   // 인접 리스트

public:
    AdjacencyList()
    {
        size = 0;

        for (int i = 0; i < SIZE; i++)
        {
            list[i] = NULL;
            vertex[i] = NULL;
        }
    }

    ~AdjacencyList()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (list[i] != nullptr)
            {
                delete[] list[i];
            }
        }
    }

    void Insert(T data)
    {
        if (size >= SIZE)
        {
            cout << "Adjacency List Overflow" << endl;
            return;
        }
        else
        {
            vertex[size++] = data;
        }
    }

    void Connect(int u, int v)
    {
        if (size <= 0)
        {
            cout << "Adjacency List is Empty" << endl;
        }
        else if (u >= size || v >= size)
        {
            cout << "Index Out of Range" << endl;
        }
        else
        {
            list[u] = new Node(vertex[v], list[u]);
            list[v] = new Node(vertex[u], list[v]);
        }
    }

    void Show()
    {
        if (size <= 0)
        {
            cout << "Adjacency List is Empty" << endl;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << vertex[i] << " : ";
                Node* currentNode = list[i];

                while (currentNode != nullptr)
                {
                    cout << currentNode->data << " ";
                    currentNode = currentNode->next;
                }
                cout << endl;
            }
        }
    }

};

int main()
{
    AdjacencyList<char> adjacencyList;

    adjacencyList.Insert('A');
    adjacencyList.Insert('B');
    adjacencyList.Insert('C');
    adjacencyList.Insert('D');

    adjacencyList.Connect(0, 1);
    adjacencyList.Connect(1, 2);
    adjacencyList.Connect(1, 3);
    adjacencyList.Connect(2, 3);

    adjacencyList.Show();

    return 0;
}