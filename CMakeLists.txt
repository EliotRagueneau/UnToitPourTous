cmake_minimum_required(VERSION 3.13)
project(UnToitPourTous)

set(CMAKE_CXX_STANDARD 14)

include_directories(Headers)
include_directories(Headers/Clients)
include_directories(Headers/Goods)

add_executable(UnToitPourTous
        Sources/Clients/Buyer.cpp
        Sources/Clients/Client.cpp
        Sources/Clients/Seller.cpp
        Sources/Goods/Flat.cpp
        Sources/Goods/Good.cpp
        Sources/Goods/Ground.cpp
        Sources/Goods/House.cpp
        Sources/Goods/Professional.cpp
        Sources/Goods/Residential.cpp
        Sources/Agency.cpp
        Sources/Utils.cpp
        main.cpp)
