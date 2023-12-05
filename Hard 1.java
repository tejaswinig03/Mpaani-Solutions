import java.util.Scanner;

public class ShortestPalindrome {

    public static String shortestPalindrome(String s) {
        int n = s.length();

        String modifiedString = s + "#" + new StringBuilder(s).reverse().toString();

        // Create the KMP table
        int[] kmpTable = new int[2 * n + 1];
        for (int i = 1, j = 0; i < 2 * n + 1; ) {
            if (modifiedString.charAt(i) == modifiedString.charAt(j)) {
                kmpTable[i++] = ++j;
            } else {
                if (j > 0) {
                    j = kmpTable[j - 1];
                } else {
                    kmpTable[i++] = 0;
                }
            }
        }
        int longestPrefixSuffix = kmpTable[2 * n];
        int charactersToAdd = n - longestPrefixSuffix;
        StringBuilder result = new StringBuilder(s.substring(n - charactersToAdd)).reverse();
        result.append(s);

        return result.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = scanner.nextLine();

        String result = shortestPalindrome(input);

        System.out.println("Shortest palindrome: " + result);
    }
}
