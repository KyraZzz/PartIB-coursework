package Further_Java.supervision_1;

public class wrong {
    public static void oldness(int o) {
        try {
            if (o <= 0) {
                throw new IllegalArgumentException("Input must be positive.");
            }
            System.out.printf("Age in days = %2f", o * 365.25);
        } catch (IllegalArgumentException e) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        try {
            oldness(Integer.parseInt(args[0]));
        } catch (NumberFormatException e) {
            System.out.println("Error parsing arguments");
        }
    }
}
