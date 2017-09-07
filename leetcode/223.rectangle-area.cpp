/**
 * https://leetcode.com/problems/rectangle-area/
 * By Nroskill
 * runtime 16 ms
 * language cpp
 */

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (C - A) * (D - B) + (G - E) * (H - F) - ((A >= G || E >= C || B >= H || F >= D) ? 0 : (min(C, G) - max(A, E)) * (min(D, H) - max(B, F)));
    }
};