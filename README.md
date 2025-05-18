# Friend Recommendation System using BFS in C

This is a simple command-line **Friend Recommendation System** implemented in C using **Breadth-First Search (BFS)** on an undirected graph represented as an adjacency list.

---

## Features

- Input a social network with people and friendships by names.
- Get friend recommendations based on the **degree of connection** (e.g., friends of friends).
- Handles friend suggestions at any degree level.
- Easy to use with name-based inputs and outputs.

---

## How to Compile and Run

1. **Compile** the code with a C compiler, for example using `gcc`:

   ```bash
   gcc friend_recommendation.c -o friend_recommendation
   ```

2. **Run** the executable:

   ```bash
   ./friend_recommendation
   ```

---

## Input Format

- Enter the number of people in the network.
- Enter the name of each person (one per line).
- Enter the number of friendships.
- Enter each friendship by specifying **two names**, one per line. Example:

  ```
  Alice
  Bob
  ```

  This means Alice and Bob are friends (undirected).
- Enter the name of the person you want recommendations for.
- Enter the degree of connection for recommendations (e.g., `2` means friends of friends).

---

## Example Interaction

```
Welcome to the Friend Recommendation System!
Enter the number of people in the network: 6
Enter name of person 0: Alice
Enter name of person 1: Bob
Enter name of person 2: Charlie
Enter name of person 3: David
Enter name of person 4: Eve
Enter name of person 5: Frank
Enter the number of friendships: 5
Enter the friendships (e.g., Alice Bob means Alice is friends with Bob):
Friendship 1:
Alice
Bob
Friendship 2:
Bob
Charlie
Friendship 3:
Bob
David
Friendship 4:
Charlie
Eve
Friendship 5:
David
Frank

Friendship Connections:
Alice is friends with: Bob
Bob is friends with: David Charlie Alice
Charlie is friends with: Eve Bob
David is friends with: Frank Bob
Eve is friends with: Charlie
Frank is friends with: David

Enter the name of the person to get friend recommendations: Alice
Enter the degree of connection to suggest (e.g., 2 for friends-of-friends): 2

Friend recommendations for Alice (Degree 2):
- You may know Charlie (at degree 2)
- You may know David (at degree 2)
```

Feel free to fork, modify, and improve!  
Questions? Just open an issue or contact me.

