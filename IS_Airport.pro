QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authwindow.cpp \
    databases.cpp \
    main.cpp \
    mainwindow.cpp \
    passenger.cpp \
    passengersbase.cpp \
    registrywindow.cpp \
    route.cpp \
    routesbase.cpp \
    ticket.cpp \
    ticketsbase.cpp \
    user.cpp \
    usersbase.cpp \
    usersviewwindow.cpp

HEADERS += \
    authwindow.h \
    databases.h \
    mainwindow.h \
    passenger.h \
    passengersbase.h \
    registrywindow.h \
    route.h \
    routesbase.h \
    ticket.h \
    ticketsbase.h \
    user.h \
    usersbase.h \
    usersviewwindow.h

FORMS += \
    authwindow.ui \
    mainwindow.ui \
    registrywindow.ui \
    usersviewwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
