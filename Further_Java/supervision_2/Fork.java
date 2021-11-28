package Further_Java.supervision_2;

public class Fork {
    private boolean inUse = false;

    public synchronized void pickUp() {
        if (inUse) {
            try {
                this.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        inUse = true;
        System.out.println("Pick up a fork.");
    }

    public void putDown() {
        inUse = false;
        System.out.println("Pick down a fork.");
        this.notify();
    }
}