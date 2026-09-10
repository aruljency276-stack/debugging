public class AuthSystem {
    public static boolean verifyToken(String generatedToken, String inputToken) {
        // 🪲 BUG: Compares memory addresses, not the string content.
        // Works fine during small internal checks due to the String Pool,
        // but fails completely on dynamically generated inputs.
        return generatedToken == inputToken;
    }
}
