package CPL.JavaCodes;

import java.util.ArrayList;
import java.util.Arrays;

class Fruit {
    int weight;
}

class Apple extends Fruit {
    boolean isRed;
}

public class Foo {
    public static void main(String[] args) {
        System.out.println("Starting...");
        Fruit f = new Fruit();
        Apple a = new Apple();

        System.out.println("Simple casting:");
        Fruit OKf = a; // use a subtype anywhere requires a supertype

        Apple[] av = new Apple[10];
        Fruit[] fv = new Fruit[10];
        ArrayList<Apple> a1 = new ArrayList<Apple>(Arrays.asList(av));
        ArrayList<Fruit> f1 = new ArrayList<Fruit>(Arrays.asList(fv));
        System.out.println("Checking a1.size = " + a1.size() + ";f1.size = " + f1.size());

        ArrayList<? extends Fruit> p = a1;
        ArrayList<Fruit> q = f1;
        q.set(3, f);

        System.out.println("Old style arrays and variance:");
        Fruit[] r = av;
        r[3] = f; // raise exception
        System.out.println("Stopping");
    }
}