package Further_Java.Mock;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.lang.reflect.Field;
import java.lang.reflect.InaccessibleObjectException;
import java.util.Deque;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Set;

public class Person implements Serializable {
    private final long accountId;
    private String fullname;
    private Set<Person> friends;
    private static long acc = 0;

    public Person(String fullname) {
        synchronized (this) {
            this.accountId = acc;
            acc += 1;
            this.fullname = fullname;
            this.friends = new HashSet<Person>();
        }
    }

    public void addFriends(Set<Person> friends) {
        for (Person f : friends) {
            if (this.friends.contains(f) || f == this)
                continue;
            Person smaller = this.accountId < f.accountId ? this : f;
            Person larger = this.accountId < f.accountId ? f : this;
            synchronized (smaller) {
                synchronized (larger) {
                    this.friends.add(f);
                    f.friends.add(this);
                }
            }
        }
    }
}

class Save {
    public static void save(Set<Person> everyone, ObjectOutputStream oos) throws IOException {
        // save a single copy of each person in Set<Person> everyone to disk via
        // oos.writeObjecj(obj)
        Set<Person> saved = new HashSet<>();
        for (Person p : everyone) {
            if (saved.contains(p))
                continue;
            oos.writeObject(p);
            saved = bfs(p, saved);
        }
    }

    private static Set<Person> getFriends(Person p) {
        try {
            Field f = p.getClass().getDeclaredField("friends");
            f.setAccessible(true);
            return (Set<Person>) f.get(p);
        } catch (InaccessibleObjectException | NoSuchFieldException | SecurityException | IllegalArgumentException
                | IllegalAccessException e) {
            e.printStackTrace();
        }
        return null;
    }

    private static Set<Person> bfs(Person p, Set<Person> saved) {
        Deque<Person> queue = new LinkedList<>();
        queue.add(p);
        while (!queue.isEmpty()) {
            Person curr = queue.pollFirst();
            if (!saved.contains(curr)) {
                saved.add(curr);
                queue.addAll(getFriends(curr));
            }
        }
        return saved;
    }
}