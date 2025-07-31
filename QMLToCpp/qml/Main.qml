import QtQuick
import QtQuick.Controls.Material
import com.franco.custom

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Sequence types to JS array")

    CppClass {
        id: cppClassId
    }

    Button {
        id: btn1Id
        text: "Send to Cpp"
        onClicked: function() {
            var arr = ["Apple", "Banana", "Avocado", "Pear", "Orange"]
            cppClassId.qmlArrayToCpp(arr)
        }
    }

    Button {
        id: btn2Id
        text: "Read from Cpp"
        anchors.top: btn1Id.bottom
        onClicked: function() {
            var arr = cppClassId.retrieveStrings()
            print("The length of the array is: " + arr.length)

            arr.forEach(function(elem) {
                print("element: " + elem)
            })
        }
    }
}
