#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

// Skewed random in [low, high] with power-law distribution (skew)
int rand_range_weighted(int low, int high, double skew = 2.0) {
    double r = pow(rnd.next(0.0, 1.0), skew);
    return low + (high - low) * r;
}

char rand_op() {
    return rnd.next(0, 1) == 0 ? '+' : '*';
}

int rand_val(char op) {
    if (op == '+') return rnd.next(0, 1000);
    return rnd.next(2, 3);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    // Open output file
    ofstream fout("testcases.txt");
    if (!fout) {
        cerr << "Cannot open output file\n";
        return 1;
    }

    int T = rnd.wnext(95, 5000, 7); // Skewed towards 10000
    fout << T << "\n";

    while (T--) {
        int n = rnd.wnext(3, 29, 7);  // Skewed towards 29
        int max_m = n * (n - 1) / 2;
        int m = rnd.wnext(n, max_m, 7); // Skewed towards dense graphs

        fout << n << " " << m << "\n";

        vector<int> nodes(n);
        iota(nodes.begin(), nodes.end(), 1);

        std::seed_seq seed{(unsigned int)rnd.next(INT_MIN, INT_MAX)};
        std::mt19937 mt(seed);

        std::shuffle(nodes.begin(), nodes.end(), mt);

        set<pair<int, int>> edges;
        while ((int)edges.size() < m) {
            int i = rnd.next(0, n - 2);
            int j = rnd.next(i + 1, n - 1);
            edges.emplace(nodes[i], nodes[j]);
        }

        for (auto [u, v] : edges) {
            fout << u << " " << v << "\n";
        }

        for (int i = 0; i < n; ++i) {
            char op1 = rand_op();
            int val1 = rand_val(op1);
            char op2 = rand_op();
            int val2 = rand_val(op2);
            fout << op1 << " " << val1 << " " << op2 << " " << val2 << "\n";
        }
    }

    fout.close();

    return 0;
}
