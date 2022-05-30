QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chifoumivue.cpp \
    connexion.cpp \
    main.cpp \
    chifoumi.cpp \
    parametrage.cpp

HEADERS += \
    chifoumi.h \
    chifoumivue.h \
    connexion.h \
    parametrage.h

FORMS += \
    chifoumivue.ui \
    connexion.ui \
    parametrage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    chifoumires.qrc
