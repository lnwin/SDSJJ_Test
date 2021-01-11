import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.12
import MyControl 1.0
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


MouseArea{
           anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            //测试时点击左键或右键
            onClicked: {
                if(mouse.button===Qt.LeftButton){
                    console.log('----qml 点击左键：Cpp发射信号')
                   // cpp_obj.name="gongjianbo"  //修改属性会触发set函数，获取值会触发get函数
                   // cpp_obj.year=1992
                    cpp_obj.chufa() //调用Q_INVOKABLE宏标记的函数
                    }
                 }
         }

FirstDLL    //注册CPP对象
       {
       id:cpp_obj


       }

Button{
       id:setbutton;
       text: "测试";
       onClicked:
       {
           console.log("测试点击");
       }

}


}
