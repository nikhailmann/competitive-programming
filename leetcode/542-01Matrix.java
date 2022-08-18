class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        for (int i = 0; i < m; i++) { //from top and left
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != 0) {
                    int l = i - 1 >= 0 ? mat[i-1][j] : m+n;
                    int t = j - 1 >= 0 ? mat[i][j-1] : m+n;
                    mat[i][j] = 1 + Math.min(l, t);
                }
            }
        }
        for (int i = m-1; i >= 0; i--) {// from bottom and right
            for (int j = n-1; j >= 0; j--) {
                if (mat[i][j] != 0) {
                    int r = i + 1 < m ? mat[i+1][j] : m+n;
                    int b = j + 1 < n ? mat[i][j+1] : m+n;
                    mat[i][j] = Math.min(mat[i][j], 1 + Math.min(r, b));
                }
            }
        } 
        return mat;
    }
    
}

/*
class Solution { //faster bfs solution
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        Queue<int[]> q = new LinkedList();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.offer(new int[] {i, j});
                } else {
                    mat[i][j] = -1; //to check if we've processed this element or not
                }
            }
        }
        
        int[][] DIR = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
        while(!q.isEmpty()) {
            int[] curr = q.poll();
            int r = curr[0], c = curr[1];
            for (int[] d: DIR) {
                int newr = r + d[0];
                int newc = c + d[1];
                if (newr < 0 || newc < 0 || newr >= m || newc >= n || mat[newr][newc] != -1) {
                    continue;
                }
                mat[newr][newc] = 1 + mat[r][c];
                q.offer(new int[] {newr, newc});
            }
        }
        return mat;
    }
    
}
/*


/* //slow dfs solution
class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] ans = new int[m][n];
        boolean[][] found = new boolean[m][n]; //visited array
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = updateMatrixAux(mat, i, j, m, n, found);
            }
        }
        return ans;
    }
    
    public int updateMatrixAux(int[][]mat, int i, int j, int m, int n, boolean[][] found) {
        if (i < 0 || j < 0 || i >= m || j >= n || found[i][j]) {
            return m+n;
        }
        if (mat[i][j] == 0) {
            return 0;
        }
        found[i][j] = true;
        int ans = 1 + Math.min(
            Math.min(updateMatrixAux(mat, i+1, j, m, n, found), updateMatrixAux(mat, i-1, j, m, n, found)),
            Math.min(updateMatrixAux(mat, i, j+1, m, n, found), updateMatrixAux(mat, i, j-1, m, n, found))
        );
        found[i][j] = false;
        return ans;
    }
}

*/
