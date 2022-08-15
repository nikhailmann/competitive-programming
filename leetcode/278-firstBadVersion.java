/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int lp = 1;
        int rp = n;
        while (lp < rp) {
            int mid = lp + (rp - lp)/2; // prevent overflow
            if (isBadVersion(mid)) {
                rp = mid;
            } else {
                lp = mid + 1;
            }
        }
        return rp;
    }
}

/**
public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int lp = 1;
        int rp = n;
        int result = lp + (rp - lp)/2;
        while (lp <= rp) {
            int mid = lp + (rp - lp)/2; // prevent overflow
            if (isBadVersion(mid)) {
                result = mid;
                rp = mid - 1;
            } else {
                lp = mid + 1;
            }
        }
        return result;
    }
}
**/
