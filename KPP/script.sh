cd "$(dirname "$0")"
g++ -std=c++17 -Wall \
    main.cpp \
    User.cpp \
    Employee.cpp \
    Client.cpp \
    Service.cpp \
    CMenu.cpp \
    CMenuItem.cpp \
    -o app
./app