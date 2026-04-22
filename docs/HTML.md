# HTML元素+属性+事件

## 标准的网页骨架
* `<!DOCTYPE html>`：文档类型声明，这里是告诉浏览器用HTML5来解析
* `<html>`：根元素，Root Element,所有的代码都写到这里面
* `<head>`：头部元素，Head Element,放一些不显示在页面上的信息，比如标题、编码、样式表等
* `<meta charset="UTF-8">`：指定文档的字符编码为UTF-8，确保网页能正确显示各种字符
* `<title>`：标题元素，Title Element,定义网页的标题，显示在浏览器标签上
* `<body>`：主体元素，Body Element,放网页的内容，比如文本、图片、链接等

具体如下：
```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>这是我的标题</title>
    </head>
    <body>

    </body>
</html>
```

## 文本与排版标签
`<h1>`到`<h6>`：标题标签，Heading Tags,分别表示不同级别的标题，`<h1>`是最高级别，`<h6>`是最低级别

`<p>`：段落标签，Paragraph Tag,表示一段文本

`<br>`：换行标签，Line Break Tag,表示换行

`<hr>`：水平线标签，Horizontal Rule Tag,表示一条水平线，用于分隔内容

## 图片与超链接
`<img>`：图片标签,用于插入图片，常用属性有`src`（图片路径）和`alt`（如果图片失效的替代文本）

`<a>`：超链接标签，Anchor Tag,用于创建链接，常用属性有`href`（链接地址）和`target`（链接打开方式）
## 表单输入与交互

`<input>`：输入标签,用于创建各种类型的输入框，常用属性有`type`（输入类型，如text、password、checkbox等）和`name`（输入名称）

`<button>`：按钮标签，Button Tag,用于创建按钮，常用属性有`type`（按钮类型，如submit、reset、button）和`onclick`（点击事件处理函数）

## 全局属性
`id`：唯一标识符属性,用于给元素设置一个唯一的标识符,用JavaScript或CSS来引用

`class`：类属性，Class Attribute,用于给元素设置一个或多个类名，用JavaScript或CSS来引用

`style`：直接在元素上设置CSS样式

`title`：提示属性，Title Attribute,用于给元素设置一个提示文本，当鼠标悬停在元素上时显示

`data-*`：自定义数据属性，Data Attribute,用于存储自定义数据，可以通过JavaScript来访问

## 特定元素的属性
`herf`:指定链接的目标地址
```html
<a href="https://www.google.com">Google</a>
```

`src`:指定图片的路径
```html
<img src="https://www.google.com/images/branding/googlelogo/1x/googlelogo_color_272x92dp.png" alt="Google Logo">
```

`alt`:指定图片无法显示时的替代文本
```html
<img src="invalid_image.jpg" alt="Image not found">
```

`type`:指定输入元素的类型
```html
<input type="text" placeholder="Default Value">
```

`value`:指定输入元素的默认值
```html
<input type="text" value="Default Value">
```

`placeholder`:指定输入元素的占位符
```html
<input type="text" placeholder="请输入内容">
```

`target`:指定链接的打开方式
```html
<a href="https://www.google.com" target="_blank">Google</a>
```

## 布尔属性
只需确认是否存在即可，存在即True，不存在即False
`disabled`:元素不可用
```html
<input type="text" disabled>
```

`readonly`:元素只读
```html
<input type="text" readonly>
```

`required`:元素必填
```html
<input type="text" required>
```

`checked`:用于复选框或单选按钮，表示是否被选中
```html
<input type="checkbox" checked>
```

## 事件
`onclick`：点击事件，当元素被点击时触发
```html
<button onclick="alert('Button clicked!')">Click Me</button>
```

`onmouseover`：鼠标悬停事件，当鼠标悬停在元素上时触发
```html
<div onmouseover="this.style.backgroundColor='yellow'">Hover over me</div>
```

`onmouseout`：鼠标离开事件，当鼠标离开元素时触发
```html
<div onmouseout="this.style.backgroundColor='white'">Hover over me</div>
```

`onchange`：改变事件，当输入元素的值发生改变时触发
```html
<input type="text" onchange="alert('Input changed!')">
```


## Javascript
`<script>`：脚本标签,用于嵌入或引用JavaScript代码

## 实例代码
```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>这是我的标题</title>
    </head>
    <body>
        <p style="color: rgb(5, 103, 125);">there are 6 titles</p>
        <h1>It's my first title</h1>
        <a href="https://www.google.com">Google</a>
        <br>
        <a href="https://www.bilibili.com/">Bilibili</a>
        <br><br>
        <input type="text" placeholder="请输入内容">
        <br><br>
        <input type="password" id="password" placeholder="请输入密码">
        <br>
        <button onclick="checkPwd()">Submit</button>
        <br><br>
        <img src="https://www.google.com/images/branding/googlelogo/1x/googlelogo_color_272x92dp.png" alt="Google Logo">
        <script>
            function checkPwd(){
                var pwd = document.getElementById("password").value;
                if(pwd === "123456"){
                    alert("密码正确！");
                } else {
                    alert("密码错误！");
                }
            }
        </script>
    </body>
</html>
```