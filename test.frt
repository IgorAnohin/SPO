( actual expected -- )
: test
    = if
        ." Success" cr
    else
        ." Failed" cr
    then

;

include parity.frt
: 1_is_odd_test
    ." 1 is odd: "
    1 parity 0 test
;

: 2_is_even_test
    ." 2 is even: "
    2 parity 1 test
;


include prime.frt
: 1_is_not_prime_test
    ." 1 is not a prime: "
    1 prime 0 test
;

: 2_is_prime_test
    ." 2 is a prime: "
    2 prime 1 test
;

: 5_is_prime_test
    ." 5 is a prime: "
    5 prime 1 test
;

: 6_is_not_prime_test
    ." 6 is not a prime: "
    6 prime 0 test
;

include concat.frt
: hello_plus_world_concat_test
    ." 'Hello ' + 'world' = 'Hello world': "
    m" Hello "
    m" world"
    concat
    m" Hello world"
    string-eq 1 test
;

include primarnost.frt
: 4_ne_primarnoe_test
    ." 4 ne primarnoe test: "
    4 primarnost 0 test
;
: 20_ne_primarnoe_test
    ." 20 ne primarnoe test: "
    20 primarnost 0 test
;
: 15_primarnoe_test
    ." 15 primarnoe test: "
    15 primarnost 1 test
;


." Parity:" cr
1_is_odd_test
2_is_even_test
cr

." Primary:" cr
1_is_not_prime_test
2_is_prime_test
5_is_prime_test
6_is_not_prime_test
cr

." Concat:" cr
hello_plus_world_concat_test
cr

." Primarnost:" cr
4_ne_primarnoe_test
20_ne_primarnoe_test
15_primarnoe_test
cr
