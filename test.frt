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
