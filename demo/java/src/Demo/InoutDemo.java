package Demo;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Date;
import java.util.Scanner;

public class InoutDemo {
    Student student;

    public void inputFromIn() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Input student name and age?");
        String name = scanner.next();
        int age = scanner.nextInt();
        String newline = scanner.nextLine();
        System.out.println("The new line: " + newline);
        student = new Student(name, age);
    }

    public void print() {
        System.out.println("Student: The name is " + student.getName() + ", the age is " + student.getAge());
    }

    public void testFormat() {
        System.out.printf("%tc\n", new Date());
        System.out.printf("%s %tB %<te, %<tY", "Due date:", new Date());

        Scanner scanner = new Scanner(System.in);
        System.out.println("Input float?");
        float nub = scanner.nextFloat();
        System.out.printf("%(.2f", nub);
    }

    public void testFile() throws FileNotFoundException {
        String dir = System.getProperty("user.dir");
        System.out.println("Test File: " + dir);

        Path dir1 = Paths.get("InoutDemo.java");
        System.out.println("Test File: " + dir1);

        PrintWriter printWriter = new PrintWriter("myfile.txt");
    }
}
