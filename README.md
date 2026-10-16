# My Notebook

个人笔记 / 知识库，使用 [MkDocs](https://www.mkdocs.org/)（Material 主题）构建的文档站点。

## 内容

- 写作指南：Markdown 语法等
- Git 使用指南
- 算法：基础数据结构、高级数据结构
- HTML 基础：基本语法、文本格式、角色页示例

## 本地运行

先安装依赖：

```bash
pip install mkdocs mkdocs-material
```

本地预览（启动开发服务器，浏览器打开 <http://127.0.0.1:8000>）：

```bash
mkdocs serve
```

构建静态站点（输出到 `site/`，已加入 `.gitignore`，不提交）：

```bash
mkdocs build
```

## 目录结构

```text
docs/            # 文档源文件（.md）
  images/        # 文档用到的图片
  javascripts/   # 自定义 JS（MathJax 配置等）
  stylesheets/   # 自定义 CSS
Algorithm/       # 算法相关内容
mkdocs.yml       # MkDocs 配置（站点名、导航、主题、扩展）
```

## 说明

- 站点名称、导航、主题、Markdown 扩展等都在 `mkdocs.yml` 里配置。
- 页面使用 Material 主题（slate 配色），并通过 MathJax 支持数学公式。
- 之前的 HTML 百科页面已拆分到独立仓库 [HTML-Webpage](https://github.com/chenguan0613/HTML-Webpage)。
