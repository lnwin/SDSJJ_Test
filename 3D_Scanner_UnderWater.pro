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
#------------------------------------------以下是PCL的配置信息：版本PCL1.11(release版本)   vtk版本8.2
#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_common
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_commond

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/OpenNI2/Include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/OpenNI2/Include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_features
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_featuresd

#INCLUDEPATH += 'D:/PCL 1.11.0/include/pcl-1.11/pcl'
#DEPENDPATH += 'D:/PCL 1.11.0/include/pcl-1.11/pcl'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_filters
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_filtersd

#INCLUDEPATH += 'D:/PCL 1.11.0/include/pcl-1.11'
#DEPENDPATH += 'D:/PCL 1.11.0/include/pcl-1.11'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_io
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_iod

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include/boost-1_73'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include/boost-1_73'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_io_ply
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_io_plyd

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Eigen/eigen3'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Eigen/eigen3'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_kdtree
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_kdtreed

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/FLANN/include/flann'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/FLANN/include/flann'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_keypoints
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_keypointsd

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/FLANN/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/FLANN/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_ml
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_mld

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Qhull/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Qhull/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_octree
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_octreed

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include/vtk-8.2'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include/vtk-8.2'



#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_outofcore
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_outofcored

#INCLUDEPATH += 'D:/PCL 1.11.0/include'
#DEPENDPATH += 'D:/PCL 1.11.0/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_people
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_peopled

#INCLUDEPATH += 'D:/PCL 1.11.0/include'
#DEPENDPATH += 'D:/PCL 1.11.0/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_recognition
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_recognitiond

#INCLUDEPATH += 'D:/PCL 1.11.0/include'
#DEPENDPATH += 'D:/PCL 1.11.0/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_registration
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_registrationd

#INCLUDEPATH += 'D:/PCL 1.11.0/include'
#DEPENDPATH += 'D:/PCL 1.11.0/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_sample_consensus
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_sample_consensusd

#INCLUDEPATH += 'D:/PCL 1.11.0/include'
#DEPENDPATH += 'D:/PCL 1.11.0/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_search
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_searchd

#INCLUDEPATH += 'D:/PCL 1.11.0/include'
#DEPENDPATH += 'D:/PCL 1.11.0/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_segmentation
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_segmentationd

#INCLUDEPATH += 'D:/PCL 1.11.0/include'
#DEPENDPATH += 'D:/PCL 1.11.0/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_stereo
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_stereod

#INCLUDEPATH += 'D:/PCL 1.11.0/include'
#DEPENDPATH += 'D:/PCL 1.11.0/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_surface
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_surfaced

#INCLUDEPATH += 'D:/PCL 1.11.0/include'
#DEPENDPATH += 'D:/PCL 1.11.0/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_tracking
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_trackingd

#INCLUDEPATH += 'D:/PCL 1.11.0/include'
#DEPENDPATH += 'D:/PCL 1.11.0/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_visualization
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/lib/' -lpcl_visualizationd

#INCLUDEPATH += 'D:/PCL 1.11.0/include'
#DEPENDPATH += 'D:/PCL 1.11.0/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_atomic-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_atomic-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_bzip2-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_bzip2-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_chrono-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_chrono-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_container-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_container-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_coroutine-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_coroutine-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_date_time-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_date_time-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_exception-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_exception-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_fiber-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_fiber-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_filesystem-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_filesystem-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_graph_parallel-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_graph_parallel-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_iostreams-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_iostreams-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_locale-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_locale-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_log_setup-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_log_setup-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_log-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_log-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_math_c99f-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_math_c99f-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_math_c99l-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_math_c99l-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_math_c99-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_math_c99-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_math_tr1f-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_math_tr1f-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_math_tr1l-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_math_tr1l-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_math_tr1-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_math_tr1-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_mpi-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_mpi-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_nowide-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_nowide-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_numpy38-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_numpy38-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_prg_exec_monitor-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_prg_exec_monitor-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_program_options-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_program_options-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_python38-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_python38-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_random-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_random-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_regex-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_regex-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_serialization-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_serialization-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_stacktrace_noop-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_stacktrace_noop-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_stacktrace_windbg_cached-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_stacktrace_windbg_cached-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_system-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_system-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_test_exec_monitor-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_test_exec_monitor-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_thread-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_thread-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_timer-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_timer-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_type_erasure-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_type_erasure-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_unit_test_framework-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_unit_test_framework-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_wave-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_wave-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_wserialization-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_wserialization-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_zlib-vc142-mt-x64-1_73
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Boost/lib/' -llibboost_zlib-vc142-mt-x64-1_73d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Boost/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/FLANN/lib/' -lflann
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/FLANN/lib/' -lflannd

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/FLANN/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/FLANN/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/FLANN/lib/' -lflann_cpp
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/FLANN/lib/' -lflann_cppd

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/FLANN/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/FLANN/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/FLANN/lib/' -lflann_cpp_s
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/FLANN/lib/' -lflann_cpp_sd

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/FLANN/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/FLANN/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/FLANN/lib/' -lflann_s
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/FLANN/lib/' -lflann_sd

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/FLANN/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/FLANN/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Qhull/lib/' -lqhull
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Qhull/lib/' -lqhulld

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Qhull/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Qhull/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Qhull/lib/' -lqhull_p
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Qhull/lib/' -lqhull_pd

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Qhull/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Qhull/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Qhull/lib/' -lqhull_r
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Qhull/lib/' -lqhull_rd

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Qhull/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Qhull/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Qhull/lib/' -lqhullcpp
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Qhull/lib/' -lqhullcppd

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Qhull/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Qhull/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Qhull/lib/' -lqhullstatic
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Qhull/lib/' -lqhullstaticd

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Qhull/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Qhull/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Qhull/lib/' -lqhullstatic_r
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/Qhull/lib/' -lqhullstatic_rd

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/Qhull/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/Qhull/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkChartsCore-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkChartsCore-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkChartsCore-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonColor-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonColor-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonComputationalGeometry-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonComputationalGeometry-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonCore-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonCore-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonDataModel-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonDataModel-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonExecutionModel-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonExecutionModel-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonMath-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonMath-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonMisc-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonMisc-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonSystem-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonSystem-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonTransforms-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkCommonTransforms-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkDICOMParser-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkDICOMParser-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkDomainsChemistry-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkDomainsChemistry-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkDomainsChemistryOpenGL2-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkDomainsChemistryOpenGL2-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkdoubleconversion-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkdoubleconversion-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkdoubleconversion-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkdoubleconversion-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkexodusII-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkexodusII-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkexpat-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkexpat-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersAMR-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersAMR-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersCore-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersCore-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersExtraction-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersExtraction-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersFlowPaths-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersFlowPaths-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersGeneral-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersGeneral-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersGeneric-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersGeneric-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersHybrid-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersHybrid-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersHyperTree-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersHyperTree-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersImaging-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersImaging-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersModeling-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersModeling-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersParallel-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersParallel-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersParallelImaging-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersParallelImaging-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersPoints-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersPoints-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersProgrammable-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersProgrammable-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersSelection-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersSelection-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersSMP-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersSMP-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersSources-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersSources-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersStatistics-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersStatistics-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersTexture-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersTexture-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersTopology-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersTopology-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersVerdict-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkFiltersVerdict-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkfreetype-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkfreetype-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkGeovisCore-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkGeovisCore-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkgl2ps-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkgl2ps-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkglew-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkglew-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'



#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkhdf5_hl-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkhdf5_hl-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkhdf5-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkhdf5-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingColor-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingColor-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingCore-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingCore-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingFourier-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingFourier-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingGeneral-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingGeneral-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingHybrid-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingHybrid-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingMath-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingMath-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingMorphological-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingMorphological-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingSources-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingSources-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingStatistics-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingStatistics-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingStencil-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkImagingStencil-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkInfovisCore-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkInfovisCore-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkInfovisLayout-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkInfovisLayout-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkInteractionImage-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkInteractionImage-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkInteractionStyle-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkInteractionStyle-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkInteractionWidgets-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkInteractionWidgets-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOAMR-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOAMR-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOAsynchronous-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOAsynchronous-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOCityGML-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOCityGML-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOCore-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOCore-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOEnSight-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOEnSight-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOExodus-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOExodus-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOExport-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOExport-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOExportOpenGL2-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOExportOpenGL2-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOExportPDF-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOExportPDF-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOGeometry-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOGeometry-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOImage-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOImage-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOImport-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOImport-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOInfovis-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOInfovis-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOLegacy-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOLegacy-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOLSDyna-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOLSDyna-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOMINC-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOMINC-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOMovie-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOMovie-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIONetCDF-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIONetCDF-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOParallel-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOParallel-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOParallel-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOParallelXML-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOParallelXML-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOParallelXML-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOPLY-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOPLY-8.2d

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOSegY-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOSegY-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOSegY-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOSQL-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOSQL-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOSQL-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOTecplotTable-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOTecplotTable-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOTecplotTable-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOVeraOut-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOVeraOut-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOVeraOut-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOVideo-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOVideo-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOVideo-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOXML-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOXML-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOXML-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOXMLParser-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOXMLParser-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkIOXMLParser-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkjpeg-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkjpeg-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkjpeg-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkjsoncpp-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkjsoncpp-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkjsoncpp-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtklibharu-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtklibharu-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtklibharu-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtklibxml2-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtklibxml2-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtklibxml2-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtklz4-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtklz4-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtklz4-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtklzma-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtklzma-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtklzma-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkmetaio-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkmetaio-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkmetaio-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkNetCDF-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkNetCDF-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkNetCDF-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkogg-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkogg-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkogg-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkParallelCore-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkParallelCore-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkParallelCore-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkParallelCore-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkParallelCore-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkParallelCore-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkpng-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkpng-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkpng-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkproj-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkproj-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkproj-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkpugixml-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkpugixml-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkpugixml-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingAnnotation-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingAnnotation-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingAnnotation-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingContext2D-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingContext2D-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingContext2D-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingContextOpenGL2-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingContextOpenGL2-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingContextOpenGL2-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingVolume-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingVolume-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingVolume-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingVolumeOpenGL2-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingVolumeOpenGL2-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingVolumeOpenGL2-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtksqlite-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtksqlite-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtksqlite-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtksys-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtksys-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtksys-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtktheora-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtktheora-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtktheora-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtktiff-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtktiff-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtktiff-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkverdict-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkverdict-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkverdict-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkViewsContext2D-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkViewsContext2D-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkViewsContext2D-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkViewsCore-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkViewsCore-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkViewsCore-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkViewsInfovis-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkViewsInfovis-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkViewsInfovis-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkzlib-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkzlib-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkzlib-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/OpenNI2/Lib/' -lOpenNI2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/OpenNI2/Lib/' -lOpenNI2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/OpenNI2/Lib/' -lOpenNI2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/OpenNI2/Lib'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/OpenNI2/Lib'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkGUISupportQt-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkGUISupportQt-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkGUISupportQt-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkGUISupportQtSQL-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkGUISupportQtSQL-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkGUISupportQtSQL-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingQt-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingQt-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingQt-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkViewsQt-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkViewsQt-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkViewsQt-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkGUISupportQtSQL-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkGUISupportQtSQL-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingQt-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingQt-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkRenderingQt-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

#win32:CONFIG(release, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkViewsQt-8.2
#else:win32:CONFIG(debug, debug|release): LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkViewsQt-8.2d
#else:unix: LIBS += -L'D:/PCL 1.11.0/3rdParty/VTK/lib/' -lvtkViewsQt-8.2

#INCLUDEPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'
#DEPENDPATH += 'D:/PCL 1.11.0/3rdParty/VTK/include'

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
