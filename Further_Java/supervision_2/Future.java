package Further_Java.supervision_2;

public abstract class Future<T> {
    private T data;
    private boolean executed = false;

    public Future() {
        Thread f = new Thread() {
            @Override
            public void run() {
                data = execute();
                executed = true;
                Future.this.notifyAll();
            }
        };
        f.start();
    }

    public abstract T execute();

    public synchronized T get() {
        if (!executed) {
            try {
                this.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        return data;
    }
}
