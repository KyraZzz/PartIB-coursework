(* Here the main program block starts *)
program main;
begin
function f(var x, y: integer): integer;
begin
x := 2;
y := 1;
if x = 1 then f := 3 else f:= 4
end;
var z: integer;
z := 0;
writeln( f(z,z) )
end