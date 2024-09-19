// 点击点亮按钮点亮灯泡 点击熄灭按钮熄灭灯泡

function on(){
    document.getElementById("light").src = "img/on.gif";
}

function off(){
    document.getElementById("light").src = "img/off.gif";
}


// 输入框鼠标聚焦后展示小写  失焦后展示大写

function lower(){
    var input = document.getElementById("name");
    input.value = input.value.toLowerCase();
}

function upper(){
    var  input = document.getElementById("name");
    input.value = input.value.toUpperCase();
}

// 实现全选和反选按钮
function checkAll(){
    var checkBoxes = document.getElementsByName("hobby");

    for (let i = 0; i < checkBoxes.length; i++) {
        const check = checkBoxes[i];
        check.checked = true;
        
    }

}

function reverseAll(){
    var checkBoxes = document.getElementsByName("hobby");

    for (let i = 0; i < checkBoxes.length; i++) {
        const check = checkBoxes[i];
        check.checked = false;
        
    }
}
