QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authwindow.cpp \
    databases.cpp \
    editpasswindow.cpp \
    edituserwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    managerouteswindow.cpp \
    passenger.cpp \
    passengersbase.cpp \
    passesviewwindow.cpp \
    registrywindow.cpp \
    route.cpp \
    routesbase.cpp \
    routesviewwindow.cpp \
    ticket.cpp \
    ticketrequestwindow.cpp \
    ticketsbase.cpp \
    user.cpp \
    usersbase.cpp \
    usersviewwindow.cpp

HEADERS += \
    authwindow.h \
    databases.h \
    editpasswindow.h \
    edituserwindow.h \
    mainwindow.h \
    managerouteswindow.h \
    passenger.h \
    passengersbase.h \
    passesviewwindow.h \
    registrywindow.h \
    route.h \
    routesbase.h \
    routesviewwindow.h \
    ticket.h \
    ticketrequestwindow.h \
    ticketsbase.h \
    user.h \
    usersbase.h \
    usersviewwindow.h

FORMS += \
    authwindow.ui \
    editpasswindow.ui \
    edituserwindow.ui \
    mainwindow.ui \
    managerouteswindow.ui \
    passesviewwindow.ui \
    registrywindow.ui \
    routesviewwindow.ui \
    ticketrequestwindow.ui \
    usersviewwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
