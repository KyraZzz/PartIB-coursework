package Further_Java.supervision_2;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

class Record {

}

class Unit extends Joinable {
    private Iterator<Record> it;

    Unit(Iterator<Record> it) {
        this.it = it;
    }

    Integer maxV = null;

    @Override
    void exec() {
        maxV = Eval.maxf(it);
    }

}

public class Eval {
    public static int f(Record r) {
        return 0;
    }

    public static Integer maxf(Iterator<Record> it) {
        // return the maximum value computed by f
        // for every Record returned by the iterator or null
        // if there are no records available
        Integer maxV = null;
        while (it.hasNext()) {
            int value = f(it.next());
            maxV = maxV == null || maxV < value ? value : maxV;
        }
        return maxV;
    }

    public static Integer parmaxf(Iterator<Record> it, int n) {
        // same functionality as maxf
        // but with n parallel threads of execution for computation
        List<Unit> units = new ArrayList<Unit>();
        for (int i = 0; i < n; i++) {
            units.add(new Unit(it));
            new Thread(units.get(i)).start();
        }

        for (Unit u : units) {
            u.join();
        }
        Integer maxV = null;
        for (Unit u : units) {
            maxV = maxV == null || maxV < u.maxV ? u.maxV : maxV;
        }
        return maxV;
    }
}
