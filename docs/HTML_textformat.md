# 文本格式化

## 文本的格式化标签

`<b>`：加粗文本

```html
<p>This is <b>bold</b> text.</p>
```

`<em>`：强调文本，通常以斜体显示

```html
<p>This is <em>emphasized</em> text.</p>
```

`<i>`:斜体文本

```html
<p>This is <i>italic</i> text.</p>
```

`<small>`：小号文本

```html
<p>This is <small>small</small> text.</p>
```

`<strong>`：表示重要性，通常以加粗显示

```html
<p>This is <strong>important</strong> text.</p>
```

`<sub>`：下标文本

```html
<p>This is <sub>subscript</sub> text.</p>
```

`<sup>`：上标文本

```html
<p>This is <sup>superscript</sup> text.</p>
```

`<ins>`：表示插入的文本，通常以下划线显示

```html
<p>This is <ins>inserted</ins> text.</p>
```

`<del>`：表示删除的文本，通常以删除线显示

```html
<p>This is <del>deleted</del> text.</p>
```

`<mark>`：表示高亮文本

```html
<p>This is <mark>highlighted</mark> text.</p>
```

## 计算机代码

`<code>`：表示计算机代码，通常以等宽字体显示

```html
<p>This is <code>cout<<"Hello World";</code> text.</p>
```

## 引用

`<abbr>`：表示缩写，提供缩写的完整形式

```html
<p>The <abbr title="World Health Organization">WHO</abbr> is an international organization.</p>
```

`<address>`：表示联系信息,点击可以跳转到邮箱客户端发送邮件

```html
<address>Contact us at: <a href="mailto:3168966792@qq.com">Contact Email</a></address>
```

`<bdo>`：表示双向文本,比如“abcde”: rtl显示为“edcba”，ltr显示为“abcde”

```html
<p><bdo dir="rtl">From right to left.</bdo></p>
<p><bdo dir="ltr">From left to right.</bdo></p>
```

`<blockquote>`：表示长引用，通常以缩进显示

```html
<blockquote>
  <p>This is a blockquote. It is used for long quotations.</p>
</blockquote>
```

`<cite>`：表示引用的作品或来源

```html
<p><cite>To Kill a Mockingbird</cite> is a classic novel.</p>
```

`<q>`：表示短引用，通常以引号显示

```html
<p>She said, <q>This is a quote.</q></p>
```

`<dfn>`：表示定义的术语

```html
<p><dfn>HTML</dfn> stands for HyperText Markup Language.</p>
```

## 整合html

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Text Format</title>
    </head>
    <body>
        <p>This is the <b>Bold Text</b>.</p><br>
        <p>This is the <em>Emphasized Text</em>.</p><br>
        <p>This is the <i>Italic Text</i>.</p><br>
        <p>This is the <small>Small Text</small>.</p><br>
        <p>This is the <strong>Strong Text</strong>.</p><br>
        <p>This is the <sub>Subscript Text</sub>.</p><br>
        <p>This is the <sup>Superscript Text</sup>.</p><br>
        <p>This is the <ins>Inserted Text</ins>.</p><br>
        <p>This is the <del>Deleted Text</del></p>.<br>
        <code> cout<<"Hello World";</code><br>
        <kbd>Ctrl + C</kbd><br>
        <samp>Sample Text</samp><br>
        <var>x</var> = 10<br>
        <pre>
        This is preformatted text.
        It preserves whitespace and line breaks.
        </pre><br>
        The<abbr title="World Health Organization">WHO</abbr> was founded in 1948.
        <address>
        Written by <a href="mailto:webmaster@example.com">Jon Doe</a>.<br>
        Visit us at:<br>
        Example.com<br>
        Box 564, Disneyland<br>
        USA
        </address><br>
        <cite>Author Name</cite><br>
        <p><bdo dir="ltr">Left to Right</bdo></p>
        <p><bdo dir="rtl">Right to Left</bdo></p>
        <blockquote cite="http://www.worldwildlife.org/who/index.html">
        For 50 years, WWF has been protecting the future of nature. The world's leading conservation organization, WWF works in 100 countries and is supported by 1.2 million members in the United States and close to 5 million globally.
        </blockquote>
        <p><q>To be, or not to be, that is the question.</q></p>
        <p><cite>AAA</cite> says that</p>
        <p><dfn>HTML</dfn> stands for HyperText Markup Language.</p>
    </body>
</html>
```
