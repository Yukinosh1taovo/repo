/* 
常见事件
    onclick     鼠标单击事件
    onblur      元素失去焦点
    onfocus     元素获得焦点
    onload      某个页面或元素被完成加载
    onsubmit    当表单被提交时触发该事件
    onkeydown   某个键盘的键被按下
    onmouseover 鼠标被移到某元素之上
    onmouseout  鼠标从某元素离开
*/

//onload : 页面/元素加载完成后触发
function load(){
    console.log("页面加载完成")
}

//onclick: 鼠标点击事件
function fn1(){
    console.log("单击事件被点击了");
}

//onblur: 失去焦点事件
function bfn(){
    console.log("失去焦点");
}

//onfocus: 元素获得焦点
function ffn(){
    console.log("获得焦点");
}

//onkeydown: 某个键盘的键被按下
function kfn(){
    console.log("键盘被按下了");
}

//onmouseover: 鼠标移动到元素之上
function over(){
    console.log("鼠标移入了")
}

//onmouseout: 鼠标移出某元素
function out(){
    console.log("鼠标移出了")
}

//onsubmit: 提交表单事件
function subfn(){
    alert("表单被提交了");
}