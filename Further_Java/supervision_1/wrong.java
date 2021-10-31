package supervision_1;

public class wrong {
    public static void oldness(int o) {
        try {
            if (o <= 0) {
                throw new IllegalArgumentException("Input must be positive.");
            }
            System.out.printf("Age in days = %f", o * 365.25);
        } catch (IllegalArgumentException e) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        oldness(Integer.parseInt(args[0]));
    }
}
