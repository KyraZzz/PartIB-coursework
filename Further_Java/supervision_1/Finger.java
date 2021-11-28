package Further_Java.supervision_1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketAddress;
import java.util.stream.Collectors;

public class Finger {
    static final int DEFAULT_PORT = 79;
    static int timeout = 2000;

    public static void main(String[] args) throws IOException {
        try {
            if (args.length != 1) {
                throw new IllegalArgumentException("Wrong number of arguments.");
            }
            String[] strargs = args[0].split("@");

            SocketAddress socketAddress = new InetSocketAddress(strargs[1], DEFAULT_PORT);
            Socket socket = new Socket();
            socket.connect(socketAddress, timeout);

            // continuously receive arguments PrintWriter out = new
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out.println(strargs[0] + "\n");
            System.out.println(in.lines().collect(Collectors.joining()));
            socket.close();
        } catch (IllegalArgumentException e) {
            System.out.println(e);
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
