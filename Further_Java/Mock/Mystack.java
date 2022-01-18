import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

class MyStack {
    public static void main(String args[]) {
        int port = args.length == 2 ? Integer.parseInt(args[0]) : 1248;
        String filename = args[1];

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            while (true) {
                Socket s = serverSocket.accept();
                // on connection, sends the contents of the file to the client
                Thread clientHandler = new Thread() {
                    @Override
                    public void run() {
                        try (BufferedWriter out = new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
                                BufferedReader reader = new BufferedReader(new FileReader(filename));) {
                            String line = null;
                            while ((line = reader.readLine()) != null) {
                                out.write(line);
                                out.flush(); // why need this
                            }
                        } catch (IOException e) {
                            // handle exceptions
                        }
                    }
                };
                clientHandler.start();
            }
        } catch (IOException e) {
            System.out.printf("Cannot use port number $d\n", port);
        }
    }
}