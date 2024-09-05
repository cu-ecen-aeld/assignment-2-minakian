#!/bin/bash

# Check if the number of arguments is not equal to 2
if [ "$#" -ne 2 ]; then
    echo "Error: Two arguments required - a file path and a text string."
    exit 1
fi

# Assign arguments to variables
writefile=$1
writestr=$2

# Extract the directory path from the file path
directory=$(dirname "$writefile")

# Create the directory if it doesn't exist
mkdir -p "$directory"
if [ $? -ne 0 ]; then
    echo "Error: Could not create the directory $directory."
    exit 1
fi

# Write the string to the file, overwriting any existing content
echo "$writestr" > "$writefile"
if [ $? -ne 0 ]; then
    echo "Error: Could not create or write to the file $writefile."
    exit 1
fi

# Print a success message
echo "Successfully wrote to the file $writefile."