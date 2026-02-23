for i in {1..100}; do
    echo -n "Run $i: "
    ./a.out
    done | grep -v 80000
