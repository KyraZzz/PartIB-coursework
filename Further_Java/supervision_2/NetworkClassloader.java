package Further_Java.supervision_2;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Arrays;

public class NetworkClassloader extends ClassLoader {
    private String server;
    private int port;

    NetworkClassloader(String server, int port) {
        this.server = server;
        this.port = port;
    }

    @Override
    protected Class<?> findClass(String name) throws ClassNotFoundException {
        // download class file and place contents in byte array b
        byte[] tmp = new byte[16]; // stores a chunk of contents of the file
        byte[] b = new byte[16]; // stores all contents of the file
        Socket socket = null;
        try {
            socket = new Socket(this.server, this.port);
            InputStream in = socket.getInputStream();
            int flag = -1;
            int readLength = 0;
            while ((flag = in.read(tmp, readLength, tmp.length - readLength)) != -1) {
                readLength += flag;
                byte[] b2 = Arrays.copyOf(b, readLength); // b2 = b + [0,0,...,0], with len(b2) = readLength
                System.arraycopy(tmp, 0, b2, b.length, flag); // b2 = b + tmp(len = flag), with len(b2) = readLength
                b = Arrays.copyOf(b2, readLength); // b = b2
            }
            // after read the whole file
            return defineClass(name, b, 0, b.length);
        } catch (IOException e) {
            throw new ClassNotFoundException(e.getMessage());
        } finally {
            try {
                if (socket != null) {
                    socket.close();
                }
            } catch (IOException e) {
                throw new ClassNotFoundException(e.getMessage());
            }
        }
    }

    public static void main(String[] args) throws IOException {
        if (args.length != 2) {
            throw new IllegalArgumentException("Program usage:<port:int> <file path:string>");
        }
        int port;
        String filepath;
        ServerSocket socket = null;
        try {
            port = Integer.parseInt(args[0]);
            filepath = args[1];
            // get the file contents and copy it into byte array
            File f = new File(filepath);
            FileInputStream in = new FileInputStream(filepath);
            int fileSize = (int) f.length();
            byte[] b = new byte[fileSize];
            int val = -1;
            int total = 0;
            while ((val = in.read(b)) != -1 && total < fileSize) {
                total += val;
            }
            in.close();
            socket = new ServerSocket(port);
            while (true) {
                Socket s = socket.accept();
                s.getOutputStream().write(b);
                s.close();
            }
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Program usage:<port:int> <file path:string>");
        } catch (IOException e) {
            System.out.println("IOException from the socket.");
        } finally {
            if (socket != null) {
                socket.close();
            }
        }
    }
}
