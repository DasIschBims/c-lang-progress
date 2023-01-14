#!/bin/bash
for folder in Day*; do
    if [ -d "$folder" ]; then
        for file in "$folder"/*; do
            if [[ ! "$file" =~ .*\..* ]] || [[ "$file" == *.exe ]]; then
                rm "$file"
            fi
        done
    fi
done
