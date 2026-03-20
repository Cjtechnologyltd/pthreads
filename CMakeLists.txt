cmake_minimum_required(VERSION 3.23)
project(pthreads)
add_executable(pthreads)

target_sources(pthreads
  PRIVATE
    main.c
)