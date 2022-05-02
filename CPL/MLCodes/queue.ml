module type Queue = sig
  type 'a queue
	val qempty : 'a queue (* an empty queue *)
	val qnull : 'a queue -> bool (* test queue is empty *)
	val qhd : 'a queue -> 'a (* get head element of queue *)
	val deq : 'a queue -> 'a queue (* dicard head element, return queue *)
	val enq : 'a queue -> 'a -> 'a queue (* add element at end of queue *)
	val norm : 'a queue -> 'a queue (* normalise a queue *)
end

module QSinList : Queue = struct
  exception Empty
  type 'a queue = Q of 'a list
  let qempty = Q([])
  let qnull q = (q == Q([]))
  let qhd = function
    |Q(x::xs) -> x
    |_ -> raise Empty
  let deq = function
    |Q(x::xs) -> Q(xs)
    |_ -> raise Empty
  let enq (Q(l)) x = Q(l @ [x])
  let norm q = q
end

module QDoubList : Queue = struct
  exception Empty
  type 'a queue = Q of 'a list * 'a list
  let qempty = Q([],[])
  let qnull q = (q = Q([],[]))
  let qhd = function
	  |Q(x::xs,tls) -> x
	  |_ -> raise Empty
  let norm = function
    | Q([],tls) -> Q(List.rev tls, [])
    | q -> q
    let deq = function
    |Q(x::xs,tls) -> norm (Q(xs,tls))
    |_ -> raise Empty
  let enq (Q(hds,tls)) x = norm (Q(hds,x::tls))
end
