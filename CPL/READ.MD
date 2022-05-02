# Run LISP SBCL files from terminal
```
    $ sbcl
    * (load "<filename>.lisp>")
```

# Run LISP CLISP file from terminal
    $ clisp
    > (load "<filename>.lisp")

# Compile OCAML file
    $ ocamlc -o <file>.byte <file>.ml
    $ ./<file>.byte

# Run OCAML file interactively
    $ ocaml
    # #use "<file>.ml"