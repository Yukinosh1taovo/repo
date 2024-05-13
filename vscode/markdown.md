# 一级标题
## 二级标题
### 三级标题
正文直接输入



代码块如下

```  cpp
int binarySearch(vector<int>& nums, int target){
  if(nums.size() == 0)
    return -1;

  int left = 0, right = nums.size() - 1;
  while(left <= right){
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid - 1; }
  }

  // End Condition: left > right
  return -1;
}

```


正文中的代码块如下  

这是一段代码`int mid = left + (right - left) / 2;`

有序列表如下 (数字+句点+空格) 缩进空置多级列表

1. first
2. second
3. third
   1. 一
   2. 二
   3. 三
      1. 四
      2. 五
      3. 六

无序列表如下 -  空格
- first
- second
- third
  - 一
  - 二
  - 三
    - 四
    - 五
    - 六


倾斜如下

*这是一段倾斜文本*

加粗如下

**这是一段加粗文本**

斜体加粗如下

***这是一段斜体加粗文本***

删除线如下  

~~这是一段删除线文本~~

引用如下

>这是一段引用文本


分割线如下

---

图片如下
![???](https://pic3.zhimg.com/80/v2-719ba7a0710621b64515763733405e06_720w.webp "??")


超链接如下
[www.google.com](www.google.com)

表格如下
|星期一|星期二|星期三|
|:-|:-:|-:|
|原神|原神|原神|
|原神|原神|原神|
|原神|原神|原神|

