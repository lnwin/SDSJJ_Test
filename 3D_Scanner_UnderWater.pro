QT += core gui
QT +=multimedia
QT +=multimediawidgets
QT +=opengl
greaterThan(QT_MAJOR_VERSION, 4):

QT += widgets
QT += serialport

CONFIG += c++11


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
Debug {
        contains(QMAKE_COMPILER_DEFINES, _WIN64) {
                LIBS += -L./Depends/x64/vs2013shared				-lMVSDKmd
        LIBS += -L./Depends/x64/vs2013shared				-lImageConvert
                DESTDIR = ./Bin/x64
        }
        else {
                LIBS += -L./Depends/win32/vs2013shared				-lMVSDKmd
        LIBS += -L./Depends/win32/vs2013shared				-lImageConvert
                DESTDIR = ./Bin/win32
        }
}
else {
        contains(QMAKE_COMPILER_DEFINES, _WIN64) {
                LIBS += -L./Depends/x64/vs2013shared				-lMVSDKmd
                LIBS += -L./Depends/x64/vs2013shared				-lImageConvert
                DESTDIR = ./Bin/x64
        }
        else {
                LIBS += -L./Depends/win32/vs2013shared				-lMVSDKmd
                LIBS += -L./Depends/win32/vs2013shared				-lImageConvert
                DESTDIR = ./Bin/win32
    }
}


INCLUDEPATH += ./Include


SOURCES += \
    CameraParameter.cpp \
    HDCamera.cpp \
    Math3d.cpp \
    OpenGLShow.cpp \
    QtVideoCapture.cpp \
    WorkThread.cpp \
    gl_image.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    CameraParameter.h \
    HDCamera.h \
    OpenGLShow.h \
    QtVideoCapture.h \
    SDK.h \
    WorkThread.h \
    gl_image.h \
    mainwindow.h \
    math3d.h \
    stb_image.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    3D_Scanner_UnderWater_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS+=-lopengl32 -lglu32

win32:CONFIG(release, debug|release): LIBS += -LD:/opencv/build/x64/vc15/lib/ -lopencv_world3411
else:win32:CONFIG(debug, debug|release): LIBS += -LD:/opencv/build/x64/vc15/lib/ -lopencv_world3411d

INCLUDEPATH += D:/opencv/build/include
DEPENDPATH += D:/opencv/build/include


DISTFILES += \
    Depends/ImageConvert.dll \
    Depends/win32/vs2013shared/ImageConvert.lib \
    Depends/win32/vs2013shared/MVSDKmd.lib \
    Depends/x64/vs2013shared/ImageConvert.lib \
    Depends/x64/vs2013shared/MVSDKmd.lib \
    glm/CMakeLists.txt \
    picture/green.png

RESOURCES += \
    picture.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Depends/x64/vs2013shared/ -lImageConvert
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Depends/x64/vs2013shared/ -lImageConvert

INCLUDEPATH += $$PWD/Include
DEPENDPATH += $$PWD/Include



win32:CONFIG(release, debug|release): LIBS += -LD:/Qt5.14/5.14.2/msvc2017_64/lib/ -lfreeglut
else:win32:CONFIG(debug, debug|release): LIBS += -LD:/Qt5.14/5.14.2/msvc2017_64/lib/ -lfreeglutd

INCLUDEPATH += D:/Qt5.14/5.14.2/msvc2017_64/include
DEPENDPATH += D:/Qt5.14/5.14.2/msvc2017_64/include
