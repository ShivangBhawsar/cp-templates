import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        // String s = scan.nextLine();
        String s = "           YES      leading spaces        are valid,    problemsetters are         evillllll";
        // Write your code here.
        ArrayList<String> arr = new ArrayList<>(Arrays.asList(s.split("[^a-zA-Z]+")));
        if (s.charAt(0) == ' ')
        {
            arr.remove(0);
        }
        System.out.println(arr.size());
        for (String s1 : arr) {
            System.out.println(s1);
        }
        scan.close();
    }

}
