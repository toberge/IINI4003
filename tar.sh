#!/usr/bin/env bash
# find . ! \( -name build -name "*.gz" \) \
#     -exec tar czf "${1:-submission}".tar.gz -- {} +
tar --exclude-vcs-ignores -czf "${1:-submission}".tar.gz -- *
