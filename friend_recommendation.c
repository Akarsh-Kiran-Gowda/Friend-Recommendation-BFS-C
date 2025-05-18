#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define NAME_LEN 50

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adjList[MAX];
int visited[MAX];
char names[MAX][NAME_LEN];
int numPeople;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Add friendship (undirected)
void addFriend(int a, int b) {
    Node* newNode = createNode(b);
    newNode->next = adjList[a];
    adjList[a] = newNode;

    newNode = createNode(a);
    newNode->next = adjList[b];
    adjList[b] = newNode;
}

// Find index of a name in the array, or -1 if not found
int getIndexByName(char name[]) {
    for (int i = 0; i < numPeople; i++) {
        if (strcmp(names[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

// Check if two people are direct friends
int isFriend(int a, int b) {
    Node* temp = adjList[a];
    while (temp != NULL) {
        if (temp->data == b) return 1;
        temp = temp->next;
    }
    return 0;
}

void resetVisited(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

void displayFriends() {
    printf("\nFriendship Connections:\n");
    for (int i = 0; i < numPeople; i++) {
        printf("%s is friends with: ", names[i]);
        Node* temp = adjList[i];
        while (temp != NULL) {
            printf("%s ", names[temp->data]);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Recommend friends at given degree
void recommendFriends(int start, int degree) {
    int level[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    resetVisited(numPeople);
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];

        Node* temp = adjList[current];
        while (temp) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                level[temp->data] = level[current] + 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }

    printf("\nFriend recommendations for %s (Degree %d):\n", names[start], degree);
    int found = 0;
    for (int i = 0; i < numPeople; i++) {
        if (level[i] == degree && !isFriend(start, i) && i != start) {
            printf("- You may know %s (at degree %d)\n", names[i], degree);
            found = 1;
        }
    }
    if (!found) {
        printf("- No new friend suggestions at degree %d.\n", degree);
    }
}

int main() {
    int numConnections;
    printf("Welcome to the Friend Recommendation System!\n");
    printf("Enter the number of people in the network: ");
    scanf("%d", &numPeople);
    getchar(); // consume newline

    for (int i = 0; i < numPeople; i++) {
        printf("Enter name of person %d: ", i);
        fgets(names[i], NAME_LEN, stdin);
        names[i][strcspn(names[i], "\n")] = 0;  // Remove trailing newline
        adjList[i] = NULL; // initialize adjacency list
    }

    printf("Enter the number of friendships: ");
    scanf("%d", &numConnections);
    getchar(); // consume newline

    printf("Enter the friendships (e.g., Alice Bob means Alice is friends with Bob):\n");
    for (int i = 0; i < numConnections; i++) {
        char name1[NAME_LEN], name2[NAME_LEN];
        printf("Friendship %d: ", i + 1);
        fgets(name1, NAME_LEN, stdin);
        fgets(name2, NAME_LEN, stdin);
        name1[strcspn(name1, "\n")] = 0;
        name2[strcspn(name2, "\n")] = 0;

        int idx1 = getIndexByName(name1);
        int idx2 = getIndexByName(name2);

        if (idx1 == -1 || idx2 == -1) {
            printf("Error: One or both names not found. Please enter valid names.\n");
            i--; // repeat this friendship input
        } else {
            addFriend(idx1, idx2);
        }
    }

    displayFriends();

    char personName[NAME_LEN];
    int personIndex, degree;

    printf("\nEnter the name of the person to get friend recommendations: ");
    fgets(personName, NAME_LEN, stdin);
    personName[strcspn(personName, "\n")] = 0;

    personIndex = getIndexByName(personName);
    if (personIndex == -1) {
        printf("Person not found in the network.\n");
        return 0;
    }

    printf("Enter the degree of connection to suggest (e.g., 2 for friends-of-friends): ");
    scanf("%d", &degree);

    recommendFriends(personIndex, degree);

    return 0;
}
