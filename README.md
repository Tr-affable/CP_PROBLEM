# MAXIMIZE THE SCORE

In a magic world of numbers you are given a directed acyclic graph (DAG) with \(n\) nodes and \(m\) edges. Initially your score is 0. Each node can performs one of the two operations :-
- **Addition Operation (`+ a`)** : Add a to the current score.
- **Multiplication Operation (`× b`)**: Multiply b to the current score.

You have the ability to choose any node once and travel along any directed path. Once you reach a dead end \(i.e. you reached a node with no outgoing path\) you Stop . You want to maximize the score. Outpur the maximum possible score you can get. 
## Input

- The first line contains an integer t \(1 ≤ t ≤ 10000\) — the number of test cases.
- For each test case:
  - The first line contains two integers **n**\(1 ≤ **n** ≤ 30\) and m  \(n-1 ≤ **m** ≤ n*(n-1)/2\) — the number of nodes and edges.
  - The next m lines each contain two integers x ,y denoting a directed edge from node x to node y.
  - The next n lines each describe 2 operation of the form  (`+ a`) \(0 ≤ **a** ≤ 1000\) or (`× b`) \(2 ≤ **b** ≤ 3\). You can chose any one of the two operations. 
## Output

For each test case, output a single integer — the maximum score computed among all nodes .
### SAMPLE INPUT
1    
6 8   
1 6   
2 1   
2 3   
2 4   
3 6   
4 1   
4 5   
6 5   
 +984 *3     
 +860 +608     
 *2   +65     
 +943 *3     
 *2   *2     
 +231 +684
### OUTPUT
16848

## Explanation
If you start from the node 2. and then follow the path like     

**2 → 4 → 1 → 6 → 5**     
You will have a total score of  16848.     
It can be shown that this is the maximum value.     