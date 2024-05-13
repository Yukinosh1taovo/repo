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



# string

```cpp
string s(length, defalult_value);

s.substr(起始下标, 子串长度); // string sub = s.substr(2, 10);
s.find(字符串, 起始下标); // int pos = s.find("awa");
```

#### **数值与字符串互转（C++11）**

| **源**                                         | **目的**    | **函数**    |
| ---------------------------------------------- | ----------- | ----------- |
| int / long long / float / double / long double | string      | to_string() |
| string                                         | int         | stoi()      |
| string                                         | long long   | stoll()     |
| string                                         | float       | stof()      |
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



