#!/bin/bash

build_folder="./build/"
executable="pomodoro"

executable_path=$(find "$build_folder" -maxdepth 1 -type f -executable | head -n 1)

if [ -n "$executable_path" ]; then
    executable_name=$(basename "$executable_path")
    
    sudo cp "$executable_path" /usr/bin/$executable
    
    if [ $? -eq 0 ]; then
		echo "Executable '$executable' installed successfully."
    else
        echo "Error: Failed to copy the executable to /usr/bin/."
    fi
else
	./scripts/build
	if [ $? -eq 0 ]; then
        ./install.sh
	fi
fi
