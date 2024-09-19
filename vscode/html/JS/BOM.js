// Browser Object Model 浏览器对象模型

/* 
                组成

        Window      浏览器窗口对象
        Navigator   浏览器对象
        Screen      屏幕对象
        history     历史记录对象
        Location    地址栏对象

*/

var obj = "location";

/*
Window  调用时 window. 可以省略 

    history -- 对history对象的只读引用
    location -- 用于窗口或框架的Location对象
    navigator -- 对Navigator对象的只读引用

    alert() -- 显示带有一段消息和一个确认按钮的警告框
    confirm() -- 显示带有一段消息以及确认按钮和取消按钮的对话框
    setInterval() -- 按照指定的周期(ms) 来调用函数或计算表达式
    setTimeout() -- 在指定的毫秒后调用函数或计算表达式

*/


if (obj == "window")
{
    // confirm()
    var flag = confirm("确认吗");
    console.log(flag);


    // setInterval()  循环执行
    var i = 0;
    setInterval(function(){
        i++;
        console.log("定时器执行了" + i + "次");
    },2000);


    // setTimeout() 只执行一次
    setTimeout(() => {
        alert("JS");
    }, 3000);

}


/* 
Location

    href -- 设置或返回完整的url

*/


if (obj == "location")
{
    alert(location.href);
    // location.href = "https://www.baidu.com";  设定地址栏地址后自动跳转
    
}












