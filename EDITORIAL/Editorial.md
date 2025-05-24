\documentclass{article}
\usepackage{graphicx} % Required for inserting images
\usepackage{amsmath}  % For better math support

\title{Editorial} 
\author{Tushar Bagani}
\date{May 2025}

\begin{document}

\maketitle

\section{Key Observations}

Since each operation is either multiplication or addition, the more nodes we traverse in a path, the more our score can Increase.

If we choose a node \( x \) with an incoming edge from \( y \), we can potentially obtain a higher score by choosing node \( y \) first. Therefore, we should start from nodes with no incoming edges. Let us call these nodes \textbf{Good} nodes.

We can use topological sorting to sort all the nodes and then traverse them in that order.  
There may be more than one \textbf{Good} node.

Let \( dp[i] \) represent the maximum score that can be achieved by traveling from any Good node to the \( i \)-th node.

Then, for each node \( x \) in topological order, we examine all the nodes \( j \) that have edges leading to \( x \) (using the reverse adjacency list).

The state \( dp[i] \) can then be defined as the maximum of all \( dp[j] \) values, followed by the maximum score from applying either of the two operations at node \( i \).

\section{Complexity Analysis}

\begin{itemize}
    \item \textbf{Topological Sort:} \( O(n + m) \)
    \item \textbf{DP Computation:} For each node, we iterate over its predecessors — also \( O(n + m) \)
\end{itemize}

Hence, the overall time complexity is efficient for the given constraints: \( n \leq 30 \), \( m \leq \frac{n(n-1)}{2} \).

\end{document}
