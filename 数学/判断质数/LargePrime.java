package 数学.判断质数;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;

public class LargePrime {

	// 测试次数，次数越多失误率越低，但速度也越慢
	public static int s = 10;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		int t = Integer.valueOf(br.readLine());
		for (int i = 0; i < t; i++) {
			BigInteger n = new BigInteger(br.readLine());
			// isProbablePrime方法包含MillerRabin和LucasLehmer测试
			// 给定测试次数s即可
			out.println(n.isProbablePrime(s) ? "Yes" : "No");
		}
		out.flush();
		out.close();
		br.close();
	}

}