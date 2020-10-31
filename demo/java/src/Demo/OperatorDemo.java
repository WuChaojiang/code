package Demo;

import java.util.Scanner;

public class OperatorDemo {
    public void test() {
        System.out.println("Input number: ");

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        while ( n != -1) {
            int fourthBitFromRight = (n & (1 << 3)) >> 3;
            System.out.printf("%d %<x The fourth Bit from right is %b", n, fourthBitFromRight == 1);

            System.out.println("\nInput number");

            scanner = new Scanner(System.in);
            n = scanner.nextInt();
        }
    }
}
