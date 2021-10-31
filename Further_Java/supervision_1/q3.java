package supervision_1;

// Runnable interface
class ExpThread1 implements Runnable {
    public void run() {
        System.out.println("expThread1 runs");
    }
}

// Thread class
class ExpThread2 extends Thread {
    public void run() {
        System.out.println("expThread2 runs");
    }

    public static void main(String[] args) {
        Thread exp1 = new Thread(new ExpThread1());
        exp1.start();
        ExpThread2 exp2 = new ExpThread2();
        exp2.start();
    }
}