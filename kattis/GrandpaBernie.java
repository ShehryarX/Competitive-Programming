package kattis;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStreamWriter;
import java.util.*;

public class GrandpaBernie {

    static FastScanner sc = new FastScanner();
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) {
        HashMap<String, ArrayList<Integer>> countryToYears = new HashMap<>();

        int N = sc.nextInt();

        for (int i = 0; i < N; i++) {
            String s = sc.next();
            int y = sc.nextInt();

            if (!countryToYears.containsKey(s)) {
                countryToYears.put(s, new ArrayList<>());
            }

            countryToYears.get(s).add(y);
        }

        for (Map.Entry<String, ArrayList<Integer>> val : countryToYears.entrySet()) {
            Collections.sort(val.getValue());
        }

        int Q = sc.nextInt();

        for (int i = 0; i < Q; i++) {
            out.println(countryToYears.get(sc.next()).get(sc.nextInt() - 1));
        }

        out.close();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        char nextChar() {
            return nextLine().charAt(0);
        }
    }
}