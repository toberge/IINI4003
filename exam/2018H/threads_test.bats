#!/usr/bin/env bats

@test "gives correct output" {
    run build/threads
    [ "$output" = "0123012301230123" ] # not meant to work every time
}
