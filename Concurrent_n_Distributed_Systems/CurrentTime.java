package Concurrent_n_Distributed_Systems;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.UnknownHostException;

public class CurrentTime {
    public static void main(String[] args) throws UnknownHostException, IOException {
        if (args.length != 1) {
            System.out.println("usage: java CurrentTime <systemname>");
            System.exit(1);
        }

        String machine = args[0];
        final int port = 123;
        Socket s = new Socket(machine, port);
        BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
        String timestamp = br.readLine();
        System.out.println(machine + ": current time is: " + timestamp);
    }
}