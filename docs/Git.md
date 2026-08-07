# 基本Git指令

## 基础配置

```powershell
git config --global user.name "chenguan0613"
git config --global user.email "3168966792@qq.com"
git config --global core.editor code
```

## 初始化和克隆

```powershell
git init
git clone<url>
```

## 保存变更

```powershell
git status #查看当前文件状态(哪里改了，哪里没提交)
git add <filename> #将特定文件添加到暂存区
git add . #将当前目录下所有改动添加到暂存区
git commit -m "说明" #提交暂存区的改动到本地仓库
```

## 远程同步

当我修改了仓库名称或者要在不同设备上同步的时候,注意这里是逻辑连接，改不了我们电脑上文件的物理名称

```powershell
git remote -v #查看当前的远程仓库地址
git remote set-url origin <new-url> #修改远程仓库地址
git pull #拉取远程代码并合并到本地
git push origin<branch-name> #将本地提交推送到远程对应的分支
```

## 分支管理

```powershell
git branch #查看所有分支
git checkout -b <name> #创建并切换到新分支
git checkout <name> #切换到已有分支
git merge <name> #将某分支的代码合并到当前分支
```

## 撤销

```powershell
git checkout -- <file> # 撤销对某个文件的修改
git reset HEAD <file> #将文件从暂存区移出，但保留修改
git log --online #简洁地查看提交历史
```
