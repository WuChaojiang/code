package Demo;

import java.util.Arrays;
import java.util.Scanner;

public class ArraysDemo {
    public void testRandomNumber() {
        System.out.println("Input counts: ");

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        while (n <= 0) {
            System.out.println("Invalid number, the number should greate zeor. \nInput counts: ");
            n = scanner.nextInt();
        }

        int[] numbers = new int[n];
        for (int i = 0; i < n; ++i) {
            numbers[i] = i+1;
        }

        int[] result = new int[n];
        
        int index = 0;
        while (n > 0) {
            int r = (int)(Math.random() * n);

            result[index] = numbers[r];
            index++;

            numbers[r] = numbers[n-1];
            n--;
        }

        System.out.println(Arrays.toString(result));

    }
}
