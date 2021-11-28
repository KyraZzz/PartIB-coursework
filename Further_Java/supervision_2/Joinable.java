package Further_Java.supervision_2;

public abstract class Joinable implements Runnable {
    abstract void exec();

    private boolean executing = false;

    final public void run() {
        // call the exec() method
        synchronized (this) {
            executing = true;
            this.exec();
            executing = false;
            this.notify();
        }
    }

    void join() {
        // block the calling thread until exec() completes in run()
        if (executing) {
            try {
                this.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        run();
    }

}
