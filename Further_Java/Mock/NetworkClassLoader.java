package Further_Java.Mock;

import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;

public class NetworkClassLoader extends ClassLoader {
    private String server;
    private int port;

    NetworkClassLoader(String server, int port) {
        this.server = server;
        this.port = port;
    }

    @Override
    public Class<?> findClass(String name) throws ClassNotFoundException {
        // it is a client
        try (Socket s = new Socket(server, port);
                InputStream is = s.getInputStream();) {
            byte[] buffer = new byte[1024];
            int validLength = 0;
            while (true) {
                final int bytesRead = is.read(buffer, validLength, buffer.length - validLength);
                if (bytesRead == -1) {
                    break;
                }
                validLength += bytesRead;
                if (validLength == buffer.length) {
                    // reach the capacity of the buffer
                    byte[] tmp = new byte[2 * buffer.length];
                    System.arraycopy(buffer, 0, tmp, 0, validLength);
                    buffer = tmp;
                }
            }
            byte[] b = new byte[validLength];
            System.arraycopy(buffer, 0, b, 0, validLength);
            return defineClass(name, b, 0, b.length);
        } catch (IOException e) { // handle exceptions}
        }
        return null;
    }
}