class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int orig = image[sr][sc];
        if (orig == color) return image;
        int l = image.length;
        int w = image[0].length;
        return floodFillAux(image, sr, sc, orig, color, l, w);
        
    }
    
    public int[][] floodFillAux(int[][] image, int sr, int sc, int orig, int color, int l, int w) {
        image[sr][sc] = color;
        if (sr - 1 >= 0 && image[sr-1][sc] == orig)  { // up
            image = floodFillAux(image, sr-1, sc, orig, color, l, w);
        }
        if (sr + 1 < l && image[sr+1][sc] == orig) {
            image = floodFillAux(image, sr+1, sc, orig, color, l, w);
        }
        if (sc - 1 >= 0 && image[sr][sc-1] == orig) {
            image = floodFillAux(image, sr, sc-1, orig, color, l, w);
        }
        if (sc + 1 < w && image[sr][sc+1] == orig) {
            image = floodFillAux(image, sr, sc+1, orig, color, l, w);
        }
        return image;
        
    }
}
