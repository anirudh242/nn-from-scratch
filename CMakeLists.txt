cmake_minimum_required(VERSION 3.10)

project(autodiff_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main
    main.cpp
    Value.cpp
    graph.cpp
    Neuron.cpp
    Layer.cpp
    MLP.cpp
)

add_custom_target(run
    COMMAND main
    COMMAND dot -Tpng graph.dot -o graph.png
    COMMAND xdg-open graph.png
    DEPENDS main
)