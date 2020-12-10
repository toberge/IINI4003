#!/usr/bin/env bats

@test "Task 1" {
    run build/spaces
    echo "$output"

    [ "${lines[0]}" = "this_is_a_string" ]
    [ "${lines[1]}" = "this_is_a_string" ]
    [ "${lines[2]}" = "this+is+a+string" ]
    [ "${lines[3]}" = "this_is_a_string" ]
    [ "${lines[4]}" = "this_is_a_string" ]
}

@test "Task 2" {
    run build/butikk
    echo "$output"

    [ "${lines[0]}" = "NTNU-nistepakken, 5, 0.15" ]
    [ "${lines[1]}" = "NTNU-koppen, 10, 0.25" ]
}

@test "Task 4" {
    run build/rgb
    echo "$output"

    [ "${lines[0]}" = "(0.5, 0.5, 0.5)" ]
    [ "${lines[1]}" = "(0.8, 0.8, 0.8)" ]
    [ "${lines[2]}" = "(1, 0.9, 0.9)"   ]
    [ "${lines[3]}" = "(130, 130, 130)" ]
    [ "${lines[4]}" = "(190, 190, 190)" ]
    [ "${lines[5]}" = "(255, 220, 220)" ]
}

@test "Task 6" {
    run build/pipes
    echo "$output"

    [ "${lines[0]}" = "{2, 4, 6}" ]
    [ "${lines[1]}" = "{1, 3}" ]
}
