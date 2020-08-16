#!/usr/bin/env bash
tar czf "${1:-submission}".tar.gz -- *[^g][^z]
