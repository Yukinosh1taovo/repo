// Document Object Model 文档对象模型  将标记语言的各个组成部分封装成对应的对象
/* 
    Document        整个文档对象
    Element         元素对象
    Attribute       属性对象
    Text            文本对象
    Comment         注释对象
*/


// getElementById() 根据id属性值获取  返回单个Element对象
var img = document.getElementById("h1");
console.log(img);



// getElementsByTagName()  根据标签名称获取  返回Element对象数组
var divs = document.getElementsByTagName('div');
for (let i = 0; i< divs.length; i++) {
    const element = divs[i];
    console.log(element);
   
}


// getElementsByName()    根据name属性值获取  返回Element对象数组
var ins = document.getElementsByName("hobby");
for (let i = 0; i < ins.length; i++) {
    const element = ins[i];
    console.log(element);
    
}

// getElementsByClassName()   根据class属性值获取  返回Elements对象数组
var clsS = document.getElementsByClassName("cls");
for (let i = 0; i < clsS.length; i++) {
    const element = clsS[i];
    console.log(element);
    
}

// 获取后查询相应对象的方法进行js操作 如修改cls类的第一个文本
var cls1 = clsS[0];
// cls1.innerHTML = "原神启动";



// 点亮灯泡
img.src = "img/on.gif";

// 将所有div标签的标签体内容后面加上红色的 very good
for (let i = 0; i < divs.length; i++) {
    const div = divs[i];
    div.innerHTML += "<font color = 'red'>very good</font>";

    
}

// 使所有的复选框呈现被选中的状态
for (let i = 0; i < ins.length; i++) {
    const check = ins[i];
    check.checked = true;
    
}