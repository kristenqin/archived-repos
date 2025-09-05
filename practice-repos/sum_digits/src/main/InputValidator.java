package main;

public class InputValidator {
    public static boolean validate(String input) {
        if (input == null || input.isEmpty()) {
            return false;
        }

        for (char c : input.toCharArray()) {
            if (!Character.isDigit(c)) {
                return false;
            }
        }

        int number = Integer.parseInt(input);
        return number >= 0 && number <= 1000;
    }
}
