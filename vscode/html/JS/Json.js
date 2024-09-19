// json定义格式
// var 变量名 = '{"key1" : value1, "key2" : value2}';

// json字符串定义  (json字符串不能折行  只能用单引号)
var jsonStr = '{"name" : "Tom","age" : 18, "address" : ["北京", "上海", "杭州"]}';  
   

// json字符串转json对象
var jsonObject = JSON.parse(jsonStr);
console.log(jsonObject.name); // 访问json对象属性


// json对象转json字符串
var jsonString = JSON.stringify(jsonObject);
console.log(jsonString);
