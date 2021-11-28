package Further_Java.supervision_2;

public class Fellow extends Thread {
    private Fork left;
    private Fork right;

    Fellow(Fork left, Fork right) {
        this.left = left;
        this.right = right;
    }

    @Override
    public void run() {
        try {
            // think for 10 seconds
            Thread.sleep(10000);
            // eat for 10 seconds
            left.pickUp();
            right.pickUp();
            Thread.sleep(10000);
            left.putDown();
            right.putDown();
            // think for 10 seconds
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted");
        }
    }
}
