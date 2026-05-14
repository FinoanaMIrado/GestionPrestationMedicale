QT += core gui widgets sql openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ajoutuser.cpp \
    diagrammewidget.cpp \
    etatdeprestation.cpp \
    listemedecinconsulter.cpp \
    listepatient.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    medecin.cpp \
    modifmed.cpp \
    modiftrait.cpp \
    modipat.cpp \
    patient.cpp \
    traitement.cpp

HEADERS += \
    ajoutuser.h \
    diagrammewidget.h \
    etatdeprestation.h \
    listemedecinconsulter.h \
    listepatient.h \
    login.h \
    mainwindow.h \
    medecin.h \
    modifmed.h \
    modiftrait.h \
    modipat.h \
    patient.h \
    traitement.h

FORMS += \
    ajoutuser.ui \
    diagrammewidget.ui \
    etatdeprestation.ui \
    listemedecinconsulter.ui \
    listepatient.ui \
    login.ui \
    mainwindow.ui \
    medecin.ui \
    modifmed.ui \
    modiftrait.ui \
    modipat.ui \
    patient.ui \
    traitement.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
