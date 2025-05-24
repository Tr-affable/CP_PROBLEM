# Problem: DAG Operations Maximization

You are given a directed acyclic graph (DAG) with \(n\) nodes and \(m\) edges. Each node performs two operations on the values received from its incoming edges — either addition or multiplication — with fixed operands.

Your task is to compute the maximum possible value that can be obtained at any node after processing all operations along the graph, starting from a virtual source node with initial value zero.

## Input

- The first line contains an integer \(t\) — the number of test cases.
- For each test case:
  - The first line contains two integers \(n\) and \(m\) — the number of nodes and edges.
  - The next \(m\) lines each contain two integers \(x, y\) denoting a directed edge from node \(x\) to node \(y\).
  - The next \(n\) lines each describe a node with a format:  
    ```
    s x c y
    ```
    where:
    - \(s\) and \(c\) are either '+' or '*', indicating the operation type
    - \(x\) and \(y\) are integers representing the operands for the two operations respectively

## Output

For each test case, output a single integer — the maximum value computed among all nodes.

## Constraints

- \(1 \le t \le 10\)
- \(1 \le n, m \le 10^5\)
- \(1 \le x, y \le 1000\) (for addition operands)
- \(1 \le x, y \le 3\) (for multiplication operands)
- The graph is guaranteed to be acyclic.
- The longest path in the DAG does not exceed 30.

## Sample Input

