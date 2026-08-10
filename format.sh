#!/bin/sh
for candidate in \
    "$(command -v clang-format)" \
    "$HOME"/.vscode/extensions/ms-vscode.cpptools-*/LLVM/bin/clang-format \
    "$HOME/.local/share/nvim/mason/bin/clang-format"
do
    if [ -x "$candidate" ]; then
        exec "$candidate" -i $(git ls-files '*.cpp' '*.hpp')
    fi
done

echo "no clang-format found... add a candidate path to wherever you installed it to this file (format.sh)" >&2
exit 1
