#!/usr/bin/bash

# Get project name from CMakeLists.txt
project_name=$(grep -oP '(?<=project\()\w+' CMakeLists.txt)
subdir_name=$(grep -oP '(?<=add_subdirectory\()\w+' CMakeLists.txt)
dirs=($(echo "$subdir_name" | tr ' ' '\n'))
exe_dir="${dirs[0]}"

# Get the project name
if [[ $project_name ]]; then
  echo "project name: $project_name"
  echo "project dir: $exe_dir"
else
  echo "Project name not found in CMakeLists.txt"
fi

# Build or rebuild and run
build_and_run ()
{
  cmake --build build
  if [[ -f ./build/$exe_dir/$project_name ]]; then
      echo "launching: ./build/$exe_dir/$project_name"
      ./build/$exe_dir/$project_name
  fi
}

# .clang-format and .clang-tidy
if [[ ! -f .clang-format ]]; then
    clang-format --style Webkit --dump-config > .clang-format 
fi

if [[ ! -f .clang-tidy ]]; then
    clang-tidy --dump-config > .clang-tidy
fi

# Create build directory
if [[ ! -d ./build/ ]]; then
  echo "creating build directory"
  mkdir build
fi

# First time? Generate ninja build files using cmake
if [[ -d ./build ]] && [[ $(ls ./build | wc -l ) -eq 0 ]]; then
  cmake -GNinja -Bbuild
fi

# if [[ ! -f compile_commands.json ]]; then
#     rm compile_commands.json
#     ln -s ./build/compile_commands.json compile_commands.json
# fi

build_and_run
