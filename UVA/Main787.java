import java.util.Scanner;
import java.math.BigInteger;

class Main787 {

    static final int END = -999999;
    static int arr[] = new int[110];
    static int maxIndex;

    static BigInteger solve() {
        BigInteger res = BigInteger.valueOf((long)END);
        for(int i=0;i<maxIndex;++i) {
            BigInteger tt = BigInteger.valueOf((long)arr[i]);
            res = res.max(tt);
            for(int j=i+1;j<maxIndex;++j) {
                tt = tt.multiply(BigInteger.valueOf((long)arr[j]));
                res = res.max(tt);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()) {
            int x;
            maxIndex = 0;
            while( (x = sc.nextInt()) != END) {
                arr[maxIndex] = x;
                ++maxIndex;
            }
            System.out.println(solve());
        }
    }
}
