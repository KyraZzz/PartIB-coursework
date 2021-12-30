package Further_Java.Mock;

public class Subject {
    private String name;

    Subject(String name) {
        this.name = name;
    }

    public static boolean equal(Subject A, Subject B) {
        if (A.name == B.name)
            return true;
        return false;
    }

    public static void main(String[] args) {
        Subject A = new Subject("A");
        Subject B = new Subject("B");
        System.out.println(equal(A, B));
    }
}