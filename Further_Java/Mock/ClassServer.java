import java.io.RandomAccessFile;
import java.net.ServerSocket;
import java.net.Socket;

public class ClassServer {
    public static void main(String[] args) throws Exception {
        final int port = Integer.parseInt(args[0]);
        final String classFilename = args[1];
        try (ServerSocket serverSocket = new ServerSocket(port);
                RandomAccessFile fp = new RandomAccessFile(classFilename, "r");) {
            final int size = (int) fp.length();
            final byte[] classBytes = new byte[size];
            int readSoFar = 0;
            while (readSoFar < size) {
                readSoFar += fp.read(classBytes, readSoFar, size);
            }
            while (true) {
                Socket s = serverSocket.accept();
                s.getOutputStream().write(classBytes);
                s.close();
            }
        }
    }
}
