#include <iostream>
using namespace std;

struct tree {
    static constexpr int BASE=(1LL<<19);
    int treeP[BASE<<1];

    void update(int node, int val) {
        node += BASE;
        treeP[node] = val;
        node >>= 1;
        while(node > 0) {
            treeP[node] = treeP[(node<<1)] + treeP[(node<<1)+1];
            node >>= 1;
        }
    }
    int query(int l, int r) {
        int ans=0;
        l += BASE - 1;
        r += BASE + 1;
        while((l>>1) != (r>>1)) {
            if((l & 1) == 0)
                ans += treeP[l+1];
            if((r & 1) == 1) 
                ans += treeP[r-1];
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
};

int main() {
    tree drzewko;
    
    drzewko.update(1, 10);
    drzewko.update(2, 5);
    drzewko.update(3, 8);
    cout << drzewko.query(1, 2) << endl;
    cout << drzewko.query(1, 3) << endl;
}
