let foldleft f accu l =
  let r_accu = ref accu in
  let r_l = ref l in
  let _ = while List.length(!r_l) > 0 do
    r_accu := f !r_accu (List.hd !r_l);
    r_l := List.tl !r_l;
  done
in !r_accu