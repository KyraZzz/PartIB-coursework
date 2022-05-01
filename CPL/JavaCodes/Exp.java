package CPL.JavaCodes;

public class Exp {
    private int tag;

    Exp(int tag) {
        this.tag = tag;
    }
}

class Var extends Exp {
    private char var_name;

    public Var(char var_name) {
        super(1);
        this.var_name = var_name;
    }
}

class Neg extends Exp {
    private Exp arg;

    public Neg(Exp arg) {
        super(2);
        this.arg = arg;
    }
}

class Divide extends Exp {
    private Exp arg1;
    private Exp arg2;

    public Divide(Exp arg1, Exp arg2) {
        super(3);
        this.arg1 = arg1;
        this.arg2 = arg2;
    }
}