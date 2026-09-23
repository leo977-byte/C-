#include <bits/stdc++.h>
using namespace std;
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
void BFS(int startNode, vector<vector<int>>& adjList, int V) {
    vector<bool> visited(V, false); // مصفوفة عشان مانزرش نفس النود مرتين
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " "; // بنطبع النود اللي بنزورها حالياً

        // بنلف على كل جيران النود الحالية
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor); // بنرمي الجار في الطابور عشان يجي عليه الدور
            }
        }
    }
}

void BFS(int startNode, vector<vector<int>>& adjList, int V) {
    vector<bool> visited(V, false); // مصفوفة عشان مانزرش نفس النود مرتين
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " "; // بنطبع النود اللي بنزورها حالياً

        // بنلف على كل جيران النود الحالية
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor); // بنرمي الجار في الطابور عشان يجي عليه الدور
            }
        }
    }
}