import java.util.*;

public class LexicalAnalyser {
    // List of C-style keywords
    private static final Set<String> keywords = new HashSet<>(Arrays.asList(
            "int", "float", "if", "else", "while", "return", "char", "void", "for"));

    // List of special symbols
    private static final Set<Character> specialSymbols = new HashSet<>(Arrays.asList(
            '+', '-', '*', '/', '=', '<', '>', '!', ';', '(', ')', '{', '}', ','));

    // Method to check if a word is a keyword
    private static boolean isKeyword(String word) {
        return keywords.contains(word);
    }

    // Method to check if a string is an identifier
    private static boolean isIdentifier(String word) {
        if (word.isEmpty() || (!Character.isLetter(word.charAt(0)) && word.charAt(0) != '_')) {
            return false;
        }
        for (char c : word.toCharArray()) {
            if (!Character.isLetterOrDigit(c) && c != '_') {
                return false;
            }
        }
        return true;
    }

    // Method to check if a string is a number
    private static boolean isNumber(String word) {
        for (char c : word.toCharArray()) {
            if (!Character.isDigit(c)) {
                return false;
            }
        }
        return true;
    }

    // Lexical Analyzer function
    public static void lexicalAnalyzer(String code) {
        StringTokenizer tokenizer = new StringTokenizer(code, " \t\n\r()+-*/=<>!;{},", true);
        
        System.out.println("Lexical Analysis Output:");
        
        while (tokenizer.hasMoreTokens()) {
            String token = tokenizer.nextToken().trim();
            
            if (token.isEmpty()) continue;

            if (specialSymbols.contains(token.charAt(0))) {
                System.out.println("Special Symbol: " + token);
            } else if (isKeyword(token)) {
                System.out.println("Keyword: " + token);
            } else if (isNumber(token)) {
                System.out.println("Number: " + token);
            } else if (isIdentifier(token)) {
                System.out.println("Identifier: " + token);
            } else {
                System.out.println("Unknown Token: " + token);
            }
        }
    }

    // Driver function
    public static void main(String[] args) {
        String code = "int main() { int num = 10; if (num > 5) return num; }";
        System.out.println("Input Code: " + code + "\n");
        lexicalAnalyzer(code);
    }
}
