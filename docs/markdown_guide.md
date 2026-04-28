# Markdown 语法

## 1. Headings
如果你想在文章中打出多级标题，要在 `#` 后面加一个空格，像下面这样书写：

`# 一级标题`
`## 二级标题`
`### 三级标题`

---

## 2. Text Formatting
两个 `*` 括起来表示 **Bold (粗体)**

单个 `*` 括起来表示 *斜体*

两个 `~` 括起来表示 ~~删除线~~

如果你要换行，需要连续敲击两次 Enter (回车) 键，也就是留出一个空行。

---

## 3. Lists

**无序列表 (单个 `*` 加空格就好，嵌套在星号前按 Tab 键)：**

* 小睦
    * 小祥

**有序列表（1. 2. 3. 这样子，注意点号后面有空格）：**

1. 打开冰箱
2. 放进大象
3. 关上冰箱

**待办事项 (Task Lists)：**

- [x] 打开冰箱
- [ ] 放进大象
- [ ] 关上冰箱

---

## 4. Code Blocks

**行内代码:** 使用单个反引号，也就是这个东西，比如 `std::vector`。

**多行代码:** 使用三个反引号，并在第一行加上语言名称，比如 cpp：

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main(){
    cout<<"Hello  World!" <<endl;
    return 0;
}
```


## 5. 表格
```powershell
首先是表头：
| 三角初华 | 丰川祥子 | 若叶睦 |

再是对齐方式：
| :--- | :----: | ---: |

然后一行一行地写内容：
| 左对齐 | 居中 | 右对齐 |
| 这一列默认左对齐 | 这里居中 | 这里靠右 |
```

| 三角初华 | 丰川祥子 | 若叶睦 |
| :--- | :----: | ---: |
| 左对齐 | 居中 | 右对齐 |
| 这一列默认左对齐 | 这里居中 | 这里靠右 |


## 6. 常用指令

|操作|指令|目的|
|:---|:---|:---|
|初始化|`mkdocs new [name]`|在新文件夹中创建MKDocs的骨架|
|本地浏览|`mkdocs serve`|修改网页后实时查看网页效果，当然你也可以`crtl K V`在vscode上面看也很方便|
|构建静态页|`mkdocs build`|将Markdown转换成纯HTML文件，存在`site/`里面|
|清理|`mkdocs build --clean`|删除`site/`里的内容在构建前|
|部署到Github|`mkdocs gh-deploy`|自动构建并把网站发布到Github pages线上|

当然看到这里肯定是有很多疑问的：

1.初始化创建新的文件夹，这个[name]具体是什么？

这个name是我们的项目名，拿我这个举例，就叫做“My-Notebook”. 这里有两个核心文件，一个是.yml文件可以看作是目录，然后具体的文本内容全部放到了`docs/`里面


2.构建静态页是什么？什么叫做构建？

浏览器是不认识markdown的, 它只认识html. 当运行`mkdocs build` 的时候它会读取 `docs/` 里每一个`.md`, 按照`yml` 里的样式把它们全都翻译成`.html`，也就是构建

3.site/文件里面是干嘛的，为什么要删除？

运行 build 后，所有的 HTML、图片、CSS 都会被塞进这个文件夹

4.gh-deploy是什么意思，如果分支的名字不是这个呢？

gh代表Github,deploy即部署发布.运行后它会做三件事情
* 在后台运行build
* 创建一个专门存放网页的分支
* 把`site/`里面的内容推送到这个分支里里面

5.如果分支不是默认名字`gh-pages`呢？

   Github pages 是默认寻找`gh-pages`这个分支的,如果你需要把它放在其它分支里，需要手动在`.yml`文件里加上
   ```powershell
   remote_branch: web-site #告诉指令往哪里push
   ```

6.如何插入图片
直接在markdown里插入图片的链接就好了，语法是这样的：
```markdown
![图片描述](图片链接)
```

举个例子，如果我想插入一张宵崎奏的照片，那就如下：

特训前：
![Kanade](My-Notebook/docs/images/kanade.png)


特训后：
![Kanade](My-Notebook/docs/images/kanade_after_training.png)

差不多就是这些了