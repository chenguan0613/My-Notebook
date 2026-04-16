# Markdown 语法
## 1.Headings
# #一级标题
## ##二级标题
### ###三级标题

## 2.Text Formating
两个*括起来 means **Bold**

单个* 括起来表示 *斜体*

两个~ 代表删除线

如果你要换行需要两次enter


## 3.列表 Lists
**无序列表 单个*就好，空心的话就是星号前加tab**
* 小睦
    * 小祥


**有序列表（1.2.3.这样子）**
1. 打开冰箱
2. 放进大象
3. 关上冰箱

**待办事项 (Task Lists -)**
- [x] 打开冰箱
- [ ] 放进大象
- [ ] 关上冰箱

## 4.Code Blocks
**行内代码:** 使用单个反引号，也就是这个东西，比如`std::vector`

**多行代码** 使用三个反引号,比如
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "Hello, Competitive Programming!" << endl;
    return 0;
}
```