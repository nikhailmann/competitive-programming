class Solution { //maxheap -- furthest away point will be at the top https://gyazo.com/5715c193f6f6e7a5cee241c974efaef5
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> MaxHeap = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] l, int[] r) {
                return distance(l) - distance(r);
            } 
        });
        
        for (int[] p : points) {
            MaxHeap.add(p);
            //if (MaxHeap.size() > k) {
              //  MaxHeap.poll();
            //}
        }
        
        int[][] ans = new int[k][2];
        while (k-- > 0) {
            ans[k] = MaxHeap.poll();
        }
        return ans;
        
    }
    
    private int distance(int[] point) {
        return point[0] * point[0] + point[1] * point[1];
    }
        
}

/* TLE solution
class Solution {
    public int[][] kClosest(int[][] points, int k) {
        int[][] ans = new int[k][3];
        for (int[] e : ans) {
            Arrays.fill(e, Integer.MAX_VALUE);
        }
        
        for(int i = 0; i < points.length; i++) {
            int curr = (int)(Math.pow(points[i][0], 2) + Math.pow(points[i][1], 2));
            if (curr < ans[k-1][0]) {
                ans[k-1][0] = curr;
                ans[k-1][1] = points[i][0];
                ans[k-1][2] = points[i][1];
                Arrays.sort(ans, Comparator.comparingInt(arr -> arr[0]));
            }
        }
        
        int[][] ret = new int[k][2];
        for (int i = 0; i < k; i++) {
            ret[i][0] = ans[i][1];
            ret[i][1] = ans[i][2];
        }
        return ret;
    }
        
        
}
*/
