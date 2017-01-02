# CC

> I don't remember what is this code for... LOL

I think it's a parser :D

## How to build

```sh
brew install boost
make all
```

## How to run

`./output/cc ./example`

./example
```
let rec fac n =
begin
    if n > 1 then
    begin
        n * (n - 1)
    end
    else
    begin
        1
    end
end
let rec fac2 n =
begin
    match n with
    begin
        | _ when n > 1 ->
        begin
            n * (n - 1)
        end
        | _ ->
        begin
            1
        end
    end
end
let a = 10 in
let add x y =
begin
    let mutable k = x in
    k <- k + y
    k
end
do printfn "%A" (fac (add 5 5)) in
```

./cc example
```
program(statement(let(let)function-defn(rec(rec)ident(fac)function-defn-arguments(ident(n)function-defn-arguments())'='(=)block-st(begin(begin)program(statement(expr(if-expr(if(if)expr(expr(ident(n))infix-op('>'(>))expr(const(int(1))))then(then)block-st(begin(begin)program(statement(expr(expr(ident(n))infix-op('*'(*))expr('('(()expr(expr(ident(n))expr('-'(-)expr(const(int(1)))))')'()))))program'())end(end))else(else)block-st(begin(begin)program(statement(expr(const(int(1))))program'())end(end)))))program'())end(end))))program'(statement(let(let)function-defn(rec(rec)ident(fac2)function-defn-arguments(ident(n)function-defn-arguments())'='(=)block-st(begin(begin)program(statement(expr(match-expr(match(match)expr(ident(n))with(with)begin(begin)match-patterns(match-pattern('|'(|)expr('_'(_))when(when)expr(expr(ident(n))infix-op('>'(>))expr(const(int(1))))'->'(->)block-st(begin(begin)program(statement(expr(expr(ident(n))infix-op('*'(*))expr('('(()expr(expr(ident(n))expr('-'(-)expr(const(int(1)))))')'()))))program'())end(end)))match-patterns(match-pattern('|'(|)expr('_'(_))'->'(->)block-st(begin(begin)program(statement(expr(const(int(1))))program'())end(end)))match-patterns()))end(end))))program'())end(end))))program'(statement(let(let)function-defn(ident(a)'='(=)expr(const(int(10)))in(in)))program'(statement(let(let)function-defn(ident(add)function-defn-arguments(ident(x)function-defn-arguments(ident(y)function-defn-arguments()))'='(=)block-st(begin(begin)program(statement(let(let)function-defn(mutable(mutable)ident(k)'='(=)expr(ident(x))in(in)))program'(statement(expr(expr(ident(k))'<-'(<-)expr(expr(ident(k))expr('+'(+)expr(expr(ident(y))expr(ident(k)))))))program'()))end(end))))program'(statement(do(do)expr(expr(ident(printfn))expr(expr(const(string("%A")))expr('('(()expr(expr(ident(fac))expr('('(()expr(expr(ident(add))expr(expr(const(int(5)))expr(const(int(5)))))')'())))')'()))))in(in))program'())))))
```
