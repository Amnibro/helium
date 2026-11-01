#!/bin/bash
f=$1; x=$2; shift 2; a=(); for o in "$@"; do [ "$o" = --native ] || a+=("$o"); done
"${HCW:?}" "$f" "$x.wasm" --web "${a[@]}" || exit $?
printf '#!/bin/sh\nexec node %s %s "$@"\n' "$(cd "$(dirname "$0")/../.." && pwd)/hc/web/host.mjs" "$x.wasm" > "$x"; chmod +x "$x"
