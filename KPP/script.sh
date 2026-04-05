cd "$(dirname "$0")"
g++ -std=c++17 -Wall \
main.cpp \
User.cpp \
Photographer.cpp \
Administrator.cpp \
Photo.cpp \
CMenu.cpp \
CMenuItem.cpp \
-o app
./app