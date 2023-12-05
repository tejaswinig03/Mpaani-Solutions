import java.util.*;
public class LengthOfLastWord {
    public static int lengthOfLastWord(String s) {
        s = s.trim();

        int lastSpaceIndex = s.lastIndexOf(' ');

        if (lastSpaceIndex == -1) {
            return s.length();
        }

        return s.length() - lastSpaceIndex - 1;
    }
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        String input = sc.nextLine();
        int result = lengthOfLastWord(input);
        System.out.println("Length of the last word: " + result);
    }
}
