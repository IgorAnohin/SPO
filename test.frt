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


." Parity:" cr
1_is_odd_test
2_is_even_test
cr
