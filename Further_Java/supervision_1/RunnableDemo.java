package supervision_1;

import java.util.ArrayList;

// Runnable for sharing across multiple threads
class R implements Runnable {
    long counter = 0;

    @Override
    public void run() {
        for (int i = 0; i < 100000; i++)
            counter++;
    }
}

// Runnable to demo static variable concurrency issues
class S implements Runnable {
    static long counter = 0;

    @Override
    public void run() {
        for (int i = 0; i < 100000; i++)
            counter++;
    }
}

// Runnable to demo synchronized functions
class F implements Runnable {
    long counter = 0;

    // synchronized means this function can only be run at most once at a time
    synchronized void incrementCounter() {
        counter++;
    }

    @Override
    public void run() {
        for (int i = 0; i < 100000; i++)
            incrementCounter();
    }
}

public class RunnableDemo {

    static void problematic() throws InterruptedException {
        R runnable = new R(); // Just one R, shared between threads

        ArrayList<Thread> threads = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            threads.add(new Thread(runnable));
            threads.get(i).start();
        }
        for (int i = 0; i < 10; i++) {
            threads.get(i).join();
        }
        System.out.printf("Counter is %d. It should be: %d\n", runnable.counter, 10 * 100000);
    }

    static void alsoProblematic() throws InterruptedException {
        ArrayList<Thread> threads = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            threads.add(new Thread(new S())); // Makes a new S every time
            threads.get(i).start();
        }
        for (int i = 0; i < 10; i++) {
            threads.get(i).join();
        }
        System.out.printf("Static counter is %d. It should be: %d\n", S.counter, 10 * 100000);
    }

    static void fixedButSlower() throws InterruptedException {
        F runnable = new F(); // Just one F, shared between threads, but has a synchronised method

        ArrayList<Thread> threads = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            threads.add(new Thread(runnable));
            threads.get(i).start();
        }
        for (int i = 0; i < 10; i++) {
            threads.get(i).join();
        }
        System.out.printf("Synchronised counter is %d. It should be: %d\n", runnable.counter, 10 * 100000);
    }

    public static void main(String[] args) throws InterruptedException {
        problematic();
        alsoProblematic();
        fixedButSlower();
    }
}
