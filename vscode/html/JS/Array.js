// alert("Hello JavaScript");

function add(a, b)
{
    return a + b;
}

var arr = [1, 2, 3, 4];
console.log(arr[0]);
console.log(arr[1]);

arr[10] = "hello";
console.log(arr);
console.log(arr.length);

// forEach()  遍历数组中有值的元素
arr.forEach(function(e){
    console.log(e);
}) 


// 箭头简化function关键字
/* arr.forEach((e)=>{
    console.log(e);
})
 */
// push添加元素到末尾
arr.push(7, 8, 9);
console.log(arr);


// splice 删除数组元素 第一个参数指定起始下标 第二个参数指定删除个数
arr.splice(2, 2);
console.log(arr);





