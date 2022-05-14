import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/* Minimax algorithm */
class Node {
    int value;
    List<Node> successors;
    boolean visited = false;

    Node(int v, List<Node> successors) {
        this.value = v;
        this.successors = successors;
    }

    Node(int v) {
        this.value = v;
    }
}

public class Minimax {
    static final int MAX_V = Integer.MAX_VALUE;
    static final int MIN_V = Integer.MIN_VALUE;

    static boolean cutoff(Node n) {
        return n.successors == null;
    }

    public static int playerMax(int alpha, int beta, Node n) {
        n.visited = true;
        if (cutoff(n)) {
            return n.value;
        }
        int value = MIN_V;
        for (Node c : n.successors) {
            int opponentV = playerMin(alpha, beta, c);
            value = value > opponentV ? value : opponentV;
            if (value >= beta) {
                return value;
            }
            alpha = value > alpha ? value : alpha;
        }
        return value;
    }

    public static int playerMin(int alpha, int beta, Node n) {
        n.visited = true;
        if (cutoff(n)) {
            return n.value;
        }
        int value = MAX_V;
        for (Node c : n.successors) {
            int opponentV = playerMax(alpha, beta, c);
            value = value < opponentV ? value : opponentV;
            if (value <= alpha) {
                return value;
            }
            beta = value < beta ? value : beta;
        }
        return value;
    }

    public static Node[] build(int[] arr) {
        Node[] narr = new Node[arr.length / 2];
        int j = 0;
        for (int i = 0; i < arr.length; i += 2) {
            narr[j++] = new Node(0, Arrays.asList(new Node(arr[i]), new Node(arr[i + 1])));
        }
        return narr;
    }

    public static Node[] build(Node[] arr) {
        Node[] narr = new Node[arr.length / 2];
        int j = 0;
        for (int i = 0; i < arr.length; i += 2) {
            narr[j++] = new Node(0, Arrays.asList(arr[i], arr[i + 1]));
        }
        return narr;
    }

    public static void treePrint(Node root) {
        List<Node> queue = new ArrayList<Node>();
        queue.add(root);
        List<Integer> unvisitedID = new ArrayList<Integer>();
        int count = 0;
        while (queue.size() > 0) {
            Node u = queue.remove(0);
            if (!u.visited)
                unvisitedID.add(count);
            count++;
            if (u.successors != null) {
                for (Node c : u.successors) {
                    queue.add(c);
                }
            }
        }
        System.out.println(unvisitedID.toString());
    }

    public static Node initialise(int[] arr) {
        Node[] d3 = build(arr);
        Node[] d2 = build(d3);
        Node[] d1 = build(d2);
        Node root = new Node(0, Arrays.asList(d1));
        return root;
    }

    public static void main(String[] args) {
        int[] arr = { 1, -15, 2, 19, 18, 23, 4, 3, 2, 1, 7, 8, 9, 10, -2, 5, -1, -30, 4, 7, 20, -1, -1, -5 };
        Node root = initialise(arr);
        System.out.printf("Max goes first:%d\n", playerMax(MIN_V, MAX_V, root));
        treePrint(root);
        root = initialise(arr);
        System.out.printf("Min goes first:%d\n", playerMin(MIN_V, MAX_V, root));
        treePrint(root);
    }
}