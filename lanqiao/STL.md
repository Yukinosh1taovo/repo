# vector

```cpp
vector<datatype> arrname(length, default_value); //构造 O(n)  提前指定长度可节省时间

vector<vector<int>> mat(100, vector<int> (666, -1)) //二维
    // 构造初始100行，初始666列的二维数组，初值为-1

arrrname[i];
arrname.begin(), arrname.end()； // 返回迭代器
arrname.push_back(value); //O(1) 
arrname.pop_back(); //O(1) 
arrname.size(); //O(1) returntype : size_t[0,2^32)
arrname.clear(); //O(n)
arrname.empty(); //O(1)
arrname.erase()
arrname.resize(length, dafault_value); //O(n) 缩短删除多余值,延长且指定默认值则 新元素 均为默认值
```



# stack

```cpp
stack<datatype> stk;

stk.push(value);
stk.pop;
stk.top();
stk.size();
stk.empty();

//不可访问内部元素
```



# queue

```cpp
queue<datatype> que;

que.push(value);
que.pop();
que.front();
que.back();
que.size();
que.empty();
que.clear();

//不可访问内部元素
```



# priority_queue

```cpp
priority_queue<datatype, containers, comparators> pq;  // 默认为大顶堆

priority_queue<int> pque1;                            // 储存int的大顶堆
priority_queue<int, vector<int>, greater<int>> pque2; // 储存int的小顶堆

pq.push(value); // O(logn)
pq.pop(); // O(logn)
pq.top(); // O(1) 
pq.size();
pq.empty();

// 不可访问内部元素 


    
```





# set

| 集合三要素 | 解释                           | set           | multiset      | unordered_set |
| ---------- | ------------------------------ | ------------- | ------------- | ------------- |
| 确定性     | 一个元素要么在集合中，要么不在 | ✔             | ✔             | ✔             |
| 互异性     | 一个元素仅可以在集合中出现一次 | ✔             | ❌（任意次）   | ✔             |
| 无序性     | 集合中的元素是没有顺序的       | ❌（从小到大） | ❌（从小到大） | ✔             |

``` cpp
set<datatype, comparators> st;

set<int> st1;               // 储存int的集合（从小到大）
set<int, greater<int>> st2; // 储存int的集合（从大到小）

st.insert(value); // 插入
st.erase(value); // 删除
st.find(value); // 查找
st.count(value); // 判断元素是否存在
st.size();
st.empty();
st.clear();

// 增删查时间复杂度均为 O(logn)
// 不存在下标索引 元素只读 不可用迭代器计算下标

```

```cpp
// 1- 定义
#include <set>
set<int> s; // 元素必须可比较大小，元素类型必须要支持 < 运算，结构体需要重载 <
// 2- 插入
s.insert(key); // 插入
// 3- 删除
s.erase(key); // 删除值为 key 的元素
s.erase(iter); // 删除迭代器 iter 指向的元素，例如 s.erase(s.begin());
s.erase(iter1, iter2); // 删除区间 [iter1, iter2) 的所有元素，例如 s.erase(s.begin(), s.end());
s.clear(); // 清空集合
// 4- 求大小  
int siz = s.size(); // 求集合大小
bool flag = s.empty(); // 集合判空
// 5-查询
if(s.find(key) != s.end()) // find 函数返回一个指向被查找到元素的迭代器
cout << "exist" << endl;
if(s.count(key) == 1) // count 返回某个值元素的个数
cout << "exist" << endl;
set<int>::iterator iter = s.lower_bound(key); // 求 key 的下界，返回指向大于等于某值的第一个元素的迭代器
set<int>::iterator iter = s.upper_bound(key); // 求 key 的上界，返回大于某个值元素的迭代器

// auto 类型推断关键字 在NOI 系列比赛中也可以使用了
auto iter = s.lower_bound(key); // 求 key 的下界，返回指向大于等于某值的第一个元素的迭代器
    
auto iter = s.upper_bound(key); // 求 key 的上界，返回大于某个值元素的迭代器

// 6-遍历

set<int>::iterator iter; // 正向遍历
for(iter=s.begin(); iter!=s.end(); iter++)
{
cout<<*iter<<endl;
}

set<int>::reverse_iterator riter; // 反向遍历，不重要
for(riter=s.rbegin(); riter!=s.rend(); riter++)
{
cout<<*riter<<endl;
}

// 7- 求最值
set<int>::iterator it = s.begin(); // 最小值
cout << *it << endl;
set<int>::iterator it = s.end(); // 最大值
cout << *(--it) << endl;
/*

注意：
1. set 和优先队列一样，其中的元素必须支持 < 运算符
2. set 的迭代器支持 ++、--、==、!=、*iter 等操作
3. set 的迭代器不支持 +、-、 +=、-= 等算术操作符，也不支持 >、<、
>=、<= 等比较操作符
*/

```





# map

| 性质   | 解释                         | map           | multimap      | unordered_map |
| ------ | ---------------------------- | ------------- | ------------- | ------------- |
| 互异性 | 一个键仅可以在映射中出现一次 | ✔             | ❌（任意次）   | ✔             |
| 无序性 | 键是没有顺序的               | ❌（从小到大） | ❌（从小到大） | ✔             |

``` cpp
map<key_datatype, value_datatype, comparator> mp;

map<int, int> mp1;               // int->int 的映射（键从小到大）
map<int, int, greater<int>> mp2; // int->int 的映射（键从大到小）

//三种遍历
for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    cout << it->first << ' ' << it->second << endl;

for (auto &pr : mp) //(C++11)
    cout << pr.first << ' ' << pr.second << endl;

for (auto &[key, val] : mp) // (C++17)
    cout << key << ' ' << val << endl;

mp[key] = value; // 增，改，查
mp.find(key); // 查找元素，返回迭代器 没找到返回mp.end()  O(1)
mp.erase(key); // 删除元素
mp.count(key); // 判断元素是否存在
mp.size();
mp.clear();
mp.empty();
// 增删改查时间复杂度均为 O(logn)
// 如果使用中括号访问 map 时对应的键不存在，那么会新增这个键，并且值为默认值，因此中括号会影响键的存在性
// 不可用迭代器计算下标
```

```cpp
// 定义，以 string, int 对为例
#include <map>
map<string, int> mp; // 底层是红黑树，元素可比较大小，key 的结构体要重载 < 运算

// 2- 插入
mp.insert(make_pair("zhs", 18)); // 插入一个键值对，若原先存在该 key，则无法插入和覆盖
mp.insert(pair<string,int>("zhs", 18)); // 插入一个键值对，若原先存在该 key，则无法插入和覆盖
mp["zhs"] = 18; // 甚至可以类似数组下标去访问 key 对应的 value，若原先不存在该 key，则创建，若原先存在，则覆盖以前该关键字对应的值
mp.emplace("zhs", 18); // 插入效果跟 insert 效果完全一样

// 3- 删除
mp.erase(key); // 删除值为 key 的元素
mp.erase(iter); // 删除迭代器 iter 指向的元素，例如
mp.erase(mp.begin());
mp.erase(iter1, iter2); // 删除区间 [iter1, iter2) 的所有元素，例如 mp.erase(mp.begin(), mp.end());
mp.clear(); // 清空集合
// 3- 求大小
int siz = mp.size(); // 求集合大小
bool flag = mp.empty(); // 集合判空

// 4-查询
if(mp.find(key) != mp.end()) // find 函数返回一个指向被查找到元素的迭代器
cout << mp[key] << endl;
if(mp.count(key)) // count 返回某个值元素的个数
cout << mp[key] << endl;
auto iter = mp.lower_bound(key); // 求 key 的下界，返回指向大于等于某值的第一个元素的迭代器
auto iter = mp.upper_bound(key); // 求 key 的上界，返回大于某个值元素的迭代器
    
// 5-遍历
map<string, int>::iterator iter; // 正向遍历
for(iter=mp.begin(); iter!=mp.end(); iter++)
{
cout << iter->first << " " << iter->second << endl;
// 或者
cout << (*iter).first << " " << (*iter).second << endl;
}
map<int>::reverse_iterator riter; // 反向遍历
for(riter=mp.rbegin(); riter!=mp.rend(); riter++)
{
// 遍历的同时修改
iter->second += 10;
cout << iter->first << " " << iter->second << endl;
}
for (auto x : mp){ // C++ 11 auto 遍历
cout << x.first << " " << x.second << endl;

// map的插入与遍历
}
for (auto& x : mp){ // C++ 11 auto 遍历
x.second += 10; // 遍历并修改
cout << x.first << " " << x.second << endl;
}
// 6- 求最值
map<string, int>::iterator it = mp.begin(); // 最小值
cout << *it << endl;
map<string, int>::iterator it = mp.end(); // 最大值
cout << *(--it) << endl;
/*
1. map 和 set 一样，其中的元素必须支持 < 运算符
2. 在插入时，使用 insert 和 用数组方式去插入，在原先存在要插入的键值时是有区别的，insert不会插入，用数组方式插入	则会直接覆盖原先数据
3. map 的迭代器支持 ++、--、==、!=、(*iter).first、(*iter).second、iter->first、 iter->second 等操作
4. map 的迭代器不支持 +、-、 +=、-= 等算术操作符，也不支持 >、<、>=、<= 等比较操作符
*/

```



# string

```cpp
string s(length, defalult_value);

s.substr(起始下标, 子串长度); // string sub = s.substr(2, 10);
s.find(字符串, 起始下标); // int pos = s.find("awa");  从起始下标到末尾查找
s.rfind(字符串, 终点下标); // 从开头到终点下标查找
s.insert(起始下标， 插入字符串);
s.erase(起始下标， 删除长度); // 删除长度未指定默认删除起始下标以后的所有字符
s.replace(起始下标, 替换长度, 替换字符串); // 注意第二个参数为替换长度而不是末尾位置
s = s + "abc"; // s += "abc"  拼接字符串
s.push_back('a'); // s.append('a'); 都是在字符串末尾添加字符

    
```



#### **数值与字符串互转（C++11）**

| **源**                                         | **目的**    | **函数**    |
| ---------------------------------------------- | ----------- | ----------- |
| int / long long / float / double / long double | string      | to_string() |
| string                                         | int         | stoi()      |
| string                                         | long long   | stoll()     |
| string    bvb                                  | float       | stof()      |
| string                                         | double      | stod()      |
| string                                         | long double | stold()     |



# pair

``` cpp
pair<datatype1, datatype2> pr;

// 两种赋值
pair<int, char> pr = make_pair(1, 'a');
pair<int, char> pr = {1, 'a'}; //  C++11

// 两种取值
pair<int, char> pr = {1, 'a'};
int awa = pr.first;
char bwb = pr.second;

pair<int, char> pr = {1, 'a'};
auto &[awa, bwb] = pr;  // C++17

// 可用 “==” 判同 (pr1 == pr2)
```



# bitset





# deque



# list



